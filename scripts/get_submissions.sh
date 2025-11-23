#!/bin/bash

set -e    # Exit on error

# Check for src directory argument
if [[ -z "$1" || -z "$2" || -z "$3" ]]; then
    echo "Usage: $0 <src> <dst> p[num]"
    exit 1
fi

# Variables
SRC_DIR="${1%/}"
DST_DIR="${2%/}"
PROBLEM="$3"
EXT=".c"

# Validate source directory
if [[ ! -d "$SRC_DIR" ]]; then
    echo "Error: '$SRC_DIR' is not a directory."
    exit 1
fi

# Create destination directory if it doesn't exist
mkdir -p "$DST_DIR"

# Iterate through subdirectories
for entry in "$SRC_DIR"/*; do
    # Skip if not a directory
    [[ ! -d "$entry" ]] && continue

    # Extract folder name
    problem=$(basename -- "$entry")

    # Process if no problem specified or problem was found
    if [[ "$PROBLEM" == "p" || "$PROBLEM" == "$problem" ]]; then
        echo "Processing folder: $entry"

        # Create text file with the absolute paths
        output_file="$DST_DIR/$problem.txt"
        : > "$output_file"

        # Copy absolute paths of all files
        for submission in "$entry"/*"$EXT"; do
            realpath "$submission" >> "$output_file"
        done

        # Verify that the correct number of files were copied
        dc=$( ls "$entry" -1 | wc -l )
        fc=$( wc -l < "$DST_DIR/$problem.txt" )
        if [[ "$dc" -ne "$fc" ]]; then
            echo "Mismatch for $entry: $dc != $fc"
            exit 1
        fi

        # Exit if specified problem was found
        [[ "$PROBLEM" == "$problem" ]] && break;
    fi
done

echo "Submissions extracted to: $DST_DIR"
