#!/bin/bash

# Get command line options
while getopts "d:i:t:o:beqvx" opt; do
    case "$opt" in
        d) DATA_DIR="${OPTARG%/}" ;;
        i) INPUT_DIR="${OPTARG%/}" ;;
        t) TEST_DIR="${OPTARG%/}" ;;
        o) OUT_DIR="${OPTARG%/}" ;;
        b) BENCH=true ;;
        e) ERROR=true ;;
        q) QUIET=true ;;
        v) VERBOSE=true ;;
        x) DEBUG=true ;;
    esac
done

# Check for data, input, and test directory arguments
if [[ -z "$DATA_DIR" || -z "$INPUT_DIR" || -z "$TEST_DIR" ]]; then
    echo "Usage: $0 -d <data_dir> -i <input_dir> -t <test_dir> [-o out_dir] [-b] [-e] [-q] [-v] [-x]"
    exit 1
fi

# Check if input directory is a valid directory
if [[ ! -d "$INPUT_DIR" ]]; then
    echo "Error: '$INPUT_DIR' is not a valid directory."
    exit 1
fi

# Check if test directory is a valid directory
if [[ ! -d "$TEST_DIR" ]]; then
    echo "Error: '$TEST_DIR' is not a valid directory."
    exit 1
fi

# Set directory for output files if not specified
if [[ -z "$OUT_DIR" ]]; then
    OUT_DIR="out"
fi

# Create directories if they do not exist
mkdir -p "$DATA_DIR" "$OUT_DIR"

# Header for the CSV file
CSV_HEADER="src,real,user,sys,I1,LLi,D1,LLd,LL"

# Variables for benchmarking
INPUT_FILE=    # Input for each problem, set in main loop
DATA_FILE=     # Output for each problem, set in main loop
TIMEOUT=1m     # Timeout for Cachegrind
NTIMES=5       # Number of iterations for 'time'

EXTENSION="c"

# Redirect output to /dev/null is QUIET is set
if [[ -n "$QUIET" ]]; then
    exec >/dev/null 2>&1
fi

# Redirect output to debug file if DEBUG is set
if [[ -n "$DEBUG" ]]; then
    # Create a debug output file
    DEBUGFILE="benchmark_out.txt"
    : > "$DEBUGFILE"
    exec >"$DEBUGFILE" 2>&1
fi

# Function for info statements
info() {
    [[ -n "$VERBOSE" ]] && echo "  (I) $*"
}

# Function for warn statements
warn() {
    echo "  (W) $*"
}

# Function to compile the code
compile() {
    local out exit

    # Check if '-e' flag is set
    if [[ -n "$ERROR" ]]; then
        out=$( gcc -g "$1" -o "$2" 2>&1 )
        exit=$?
        [[ -n "$out" ]] && warn "$out"
    else
        gcc -g "$1" -o "$2" &> /dev/null
        exit=$?
    fi

    return "$exit"
}

# Function to benchmark the program using 'time' and 'Cachegrind'
benchmark() {
    local tm_res tm_csv cg_res cg_csv

    # Run the program with GNU 'time'
    tm_res=$( for _ in $(seq 1 $NTIMES); do { /usr/bin/time -f "%e %U %S" "$1" < "$INPUT_FILE" 1> /dev/null; } 2>&1; done )
    tm_csv=$( awk -v N=$NTIMES '{ r+=$1; u+=$2; s+=$3 } END { printf "%.2f,%.2f,%.2f", r/N, u/N, s/N }' <<< "$tm_res" )

    # Run the program with 'Cachegrind' , changed prgram argument with 1 and went from <<< to a singular < 
    cg_res=$( timeout "$TIMEOUT" valgrind --tool=cachegrind --cache-sim=yes --cachegrind-out-file=/dev/null "$1" < "$INPUT_FILE" 2>&1 ) # --branch-sim=yes
    if [ $? -eq 124 ]; then
        warn "Cachegrind timed out"
        cg_csv=",,,,"
    else
        cg_csv=$( grep -o "rate:.*" <<< "$cg_res" | awk '/./ { split($2, mr, "%"); o = o (o ? "," : "") mr[1]; } END { print o }' )
    fi

    # Debug statements
    if [[ -n "$BENCH" ]]; then
        printf "tm_res:\n%s\n" "$tm_res"
        printf "tm_csv:\n%s\n" "$tm_csv"
        printf "cg_res:\n%s\n" "$cg_res"
        printf "cg_csv:\n%s\n" "$cg_csv"
    fi

    echo "$2,$tm_csv,$cg_csv" >> $DATA_FILE
}

# Loop through files
for file in "$TEST_DIR"/*; do
    echo "Processing problems: $file"

    # Extract file name
    INPUT_FILE=$(basename -- "$file")

    # Create CSV file output for each problem
    DATA_FILE="$DATA_DIR/${INPUT_FILE%.*}.csv"
    echo "$CSV_HEADER" > "$DATA_FILE"

    # Create a directory in OUT_DIR for each problem
    out_dir="$OUT_DIR/${INPUT_FILE%.*}"
    mkdir -p "$out_dir"

    # Set input file to problem input in input directory
    INPUT_FILE="$INPUT_DIR/$INPUT_FILE"

    # Loop through each submission to the problem
    # Input each file in fd 3 since benchmark closes fd 1 & fd 2
    while IFS= read -r submission <&3; do
        # Skip empty lines
        [[ -z "$submission" ]] && continue

        # Verify that the submission exists
        if [[ -f "$submission" ]]; then
            # Extract submission name and extension
            filename=$(basename -- "$submission")
            extension="${filename##*.}"

            # Run if the extension is what we are looking for
            if [[ "$extension" == "$EXTENSION" ]]; then
                info "Compiling: $filename"
                program="$out_dir/${filename%.c}.out"

                # Attempt to compile the submission
                if compile "$submission" "$program"; then
                    info "Running benchmark on: ${filename%.c}.out"
                    benchmark "$program" "$filename"
                    info "Finished running $filename"
                else
                    warn "Failed to compile submission: $filename"
                fi
            else
                warn "Skipping non-$EXTENSION submission: $filename"
            fi
        else
            warn "Submission not found: $submission"
        fi
    done 3< "$file"
done

echo "Benchmark complete."
