#!/bin/bash

# Check the formatting with 2 arguments passed in
if [ "$#" -ne 2 ]; then
    echo "Error: Must pass in two arguments: file directory and the search string"
    exit 1
fi

filesdir=$1
searchstr=$2

# Check if its a valid directory
if [ ! -d "$filesdir" ]; then
    echo "Error: '$filesdir' is not a valid directory"
    exit 1
fi

# Get the number of files in the directory
file_number=$(find "$filesdir" -type f | wc -l)

# Get the number of lines that match the search string
match_number=$(grep -r "$searchstr" "$filesdir" 2>/dev/null | wc -l)

# Print results
echo "The number of files are $file_number and the number of matching lines are $match_number"