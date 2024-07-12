#!/bin/bash
# create_static_lib.sh - Script to create a static lib from .c files

# Compile all .c files to .o files
gcc -c *.c

# Create the static library from the .o files
ar rcs liball.a *.o

# Clean up .o files
rm *.o
