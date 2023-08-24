#!/bin/sh
# writer.sh: writes a string ($2) in specified file ($1)
# Author: Lucas Cunha

# Check if both arguments are provided
if [ $# -ne 2 ]; then
    echo "Usage: $0 <writefile> <writestr>"
    exit 1
fi

# Assign arguments to variables
writefile=$1
writestr=$2

# Create the directory path if it doesn't exist
writefile_dir=$(dirname $writefile)
mkdir -p $writefile_dir

# Write the content to the file
echo $writestr > $writefile

# Check if the write operation was successful
if [ $? -ne 0 ]; then
    echo "Error: Failed to write to $writefile"
    exit 1
fi