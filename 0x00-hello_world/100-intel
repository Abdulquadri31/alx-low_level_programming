#!/bin/bash

# Check if CFILE variable is set
if [ -z "$CFILE" ]; then
    echo "Error: CFILE variable is not set."
    exit 1
fi

# Extract the filename without the extension
filename=$(basename "$CFILE" .c)

# Generate the assembly code and save it to a file with .s extension
gcc -S -masm=intel "$CFILE" -o "${filename}.s"

# Check if the assembly file was created successfully
if [ $? -eq 0 ]; then
    echo "Assembly code generated and saved to ${filename}.s"
else
    echo "Error: Failed to generate assembly code."
fi

