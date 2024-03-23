#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Ubuntu
    sudo apt-get update
    sudo apt-get install -y libgtest-dev cmake
    cd /usr/src/gtest
elif [[ "$OSTYPE" == "darwin"* ]]; then
    # Mac OS
    brew install cmake
    brew install googletest
    cd "$(brew --prefix googletest)/src"
fi

# Build the sources
sudo cmake CMakeLists.txt
sudo make

# Copy the static libraries to /usr/lib
sudo cp *.a /usr/lib

