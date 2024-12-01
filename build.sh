#! /usr/bin/bash

# script to build the project

if [[ ! -f ./build ]]; then
    mkdir ./build
fi

cd ./build

if [[ "$?" == "0" ]]; then
    echo "switched to ./build"
else
    echo "E: can't enter dir ./build"
    exit 1
fi

echo "#########################"

cmake ..

if [[ "$?" != "0" ]]; then
    exit 1
fi
echo "#########################"

make

echo "#########################"
