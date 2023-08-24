#!/bin/sh
# finder.sh: verifies the given string ($2) in the given folder ($1)
# Author: Lucas Cunha

# Check if both arguments are provided
if [ $# -ne 2 ]; then
    echo "Usage: $0 <filesdir> <searchstr>"
    exit 1
fi

# Assign arguments to variables
filesdir=$1
searchstr=$2

# Check if filesdir is a valid directory
if [ ! -d "$filesdir" ]; then
    echo "Error: $filesdir is not a valid directory"
    exit 1
fi

# Find matching lines and count files
total_files=$(expr `find $filesdir | wc -l` - 1)
matching_lines=`grep -r $searchstr $filesdir | wc -l`

echo "The number of files are $total_files and the number of matching lines are $matching_lines"