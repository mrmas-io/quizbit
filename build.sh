#!/bin/bash

clean_build() {
    echo "Cleaning build directory..."
    rm -rf build
}

# Check if "--clean" or "clean" argument is provided
if [ "$1" == "--clean" ] || [ "$1" == "clean" ]; then
    clean_build
    exit 0
fi

# Create build directory if it doesn't exist
mkdir -p build/database

# Change to the build directory
cd build || exit

# Run cmake to generate build files
cmake ..

# Run make to build the program
make main

# Check if the build was successful
if [ $? -eq 0 ]; then
    echo "Build successful. Running the program..."
    # Run the generated executable
    ./main
else
    echo "Build failed."
fi
