#!/bin/bash

# Seed for reproducible randomness
SEED=5204

# Get command line options
while getopts "d:fq" opt; do
    case "$opt" in
        d) OUT_DIR="${OPTARG%/}" ;;
        f) FORCE=true ;;
        q) QUIET=true ;;
    esac
done

# Check for out directory argument
if [[ -z "$OUT_DIR" ]]; then
    echo "Usage: $0 -d <dir> [-f] [-q]"
    exit 1
fi

# Create output directory if it doesn't exist
mkdir -p "$OUT_DIR"

# Function for printing info statements
info() {
    [[ -n "$QUIET" ]] || echo "$*"
}

# Function for creating random number inputs
# Usage: generate_numbers <outfile> <n> <min> <max>
function generate_numbers() {
    local outfile="$1"
    local n="$2"
    local min="$3"
    local max="$4"

    # Generate inputs if outfile doesn't already exist
    if [[ -n "$FORCE" || ! -f "$outfile" ]]; then
        echo "$n" > "$outfile"
        # Generate random usign 'awk' and SEED for reproducibility
        awk -v n="$n" -v min="$min" -v max="$max" -v seed="$SEED" '
            BEGIN {
                srand(SEED)
                for (i = 0; i <  n; i++) {
                    print int(min + rand() * (max - min))
                }
            }
        ' >> "$outfile"
        info "'$outfile' generated with seed: '$SEED'."
    else
        info "'$outfile' already exists. Skipping generation."
    fi
}

# p02255 - Insertion Sort
generate_numbers "$OUT_DIR/p02255.txt" 100 0 100

# p02259 - Bubble Sort
generate_numbers "$OUT_DIR/p02259.txt" 100 0 100

# p02260 - Selection Sort
generate_numbers "$OUT_DIR/p02260.txt" 100 0 100

# p02272 - Merge Sort
generate_numbers "$OUT_DIR/p02272.txt" 500000 0 2000000

# p02275 - Counting Sort
generate_numbers "$OUT_DIR/p02275.txt" 2000000 0 10000

# p02277 - Quick Sort
generate_numbers "$OUT_DIR/p02277.txt" 100000 1 2000000
