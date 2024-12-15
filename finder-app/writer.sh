#!/bin/bash

# Check the formatting with 2 arguments passed in
if [ "$#" -ne 2 ]; then
    echo "Error: Must pass in two arguments: Write file and the string"
    exit 1
fi

writefile=$1
writestr=$2

# Create the file in the path if it doesn't exist or overwrite existing
mkdir -p "$(dirname "$writefile")"

# Create/overwrite to the file
if ! echo "$writestr" > "$writefile"; then
    echo "Error: Cannot create or overwrite to the file '$writefile'"
    exit 1
fi

echo "Success: File '$writefile' added with the string"
