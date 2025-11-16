#!/bin/bash

# Check for src directory argument
if [ -z "$1" ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

SRC_DIR="$1"

# Check if src directory is a valid directory
if [ ! -d "$SRC_DIR" ]; then
    echo "Error: '$SRC_DIR' is not a valid directory."
    exit 1
fi

# Create directory for compiled programs
OUT_DIR="./out"
mkdir -p "$OUT_DIR"

# Create directory for CSV data output
DATA_DIR="./data"
mkdir -p "$DATA_DIR"

INPUT_FILE=    # To be set in main loop
TIMEOUT=1m     # Timeout for Cachegrind
NTIMES=5       # Number of iterations for 'time'

# Function to benchmark the program using 'time' and 'Cachegrind'
benchmark() {
    local tm_res tm_csv cg_res cg_csv

    # Run the program with GNU 'time'
    tm_res=$( for _ in $(seq 1 $NTIMES); do { /usr/bin/time -f "%e %U %S" "$1" < "$INPUT_FILE" 1> /dev/null; } 2>&1; done )
    tm_csv=$( awk -v N=$NTIMES '{ r+=$1; u+=$2; s+=$3 } END { printf "%.2f,%.2f,%.2f", r/N, u/N, s/N }' <<< "$tm_res" )

    # Run the program with 'Cachegrind'
    cg_res=$( timeout "$TIMEOUT" valgrind --tool=cachegrind --cache-sim=yes --cachegrind-out-file=/dev/null "$program" <<< "$INPUT_FILE" 2>&1 ) # --branch-sim=yes 
    if [ $? -eq 124 ]; then
        echo "Cachegrind timed out"
        cg_csv=",,,,"
    else
        cg_csv=$( grep -o "rate:.*" <<< "$cg_res" | awk '/./ { split($2, mr, "%"); o = o (o ? "," : "") mr[1]; } END { print o }' )
    fi 

    # Debug statements
    # printf "tm_res:\n%s\n" "$tm_res"
    # printf "tm_csv:\n%s\n" "$tm_csv"
    # printf "cg_res:\n%s\n" "$cg_res"
    # printf "cg_csv:\n%s\n" "$cg_csv"

    echo "$2,$tm_csv,$cg_csv" >> $DATA_FILE
}

# Loop through files
for file in "$SRC_DIR"/*; do
    echo "Processing problems: $file"
    INPUT_FILE=$(basename -- "$file")

    # Create CSV file output for each problem
    DATA_FILE="$DATA_DIR/${INPUT_FILE%.*}.csv"
    echo "src,real,user,sys,I1,LLi,D1,LLd,LL,pred" > "$DATA_FILE"

    INPUT_FILE="inputs/$INPUT_FILE"

    # Loop through each submission the problem
    while IFS= read -r submission <&3; do
        # Skip empty lines
        [ -z "$submission" ] && continue

        # Verify that the submission exists
        if [ -f "$submission" ]; then
            filename=$(basename -- "$submission")
            extension="${filename##*.}"
            
            if [ "$extension" == "c" ]; then
                echo "Compiling: $filename"
                program="$OUT_DIR/${filename%.c}.out"
                
                if gcc -g "$submission" -o "$program"; then
                    echo "Running benchmark on: ${filename%.c}.out"
                    benchmark "$program" "$filename" || { echo "Benchmark failed"; exit 1; }
                    echo "Finished running $filename"
                else
                    echo "Compilation failed for $filename. Skipping."
                fi
            else
                echo "Skipping non-C submission: $filename"
            fi
        else
            echo "Submission not found: $submission"
        fi
    done 3< "$file"
done

echo "Benchmark complete"
