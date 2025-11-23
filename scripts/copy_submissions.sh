#!/bin/bash

SRC_DIR="./test"   # Directory containing submission file paths
OUT_DIR="./src"    # Directory to copy files to

# Create output directory if it doesn't exist
mkdir -p "$OUT_DIR"

# Loop through each problem in the source directory
for file in "$SRC_DIR"/*; do
    echo "Processing file list: $file"

    # Create a folder for each problem
    folder=$(basename -- "$file")
    target_dir="$OUT_DIR/${folder%.*}"
    mkdir -p "$target_dir"

    # Read each submission path in the file
    while IFS= read -r file_path; do
        # Skip empty lines
        [ -z "$file_path" ] && continue

        # Check if the submission exists before copying
        if [ -f "$file_path" ]; then
            cp "$file_path" "$target_dir"
        else
            echo "File not found: $file_path"
        fi
    done < "$file"
done

echo "All files copied to $OUT_DIR."
