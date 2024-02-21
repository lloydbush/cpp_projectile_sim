#! /usr/bin/bash

# script to build the project

mkdir build
echo "#########################"
cmake -S ./src -B ./build
echo "#########################"
cd ./build
echo "#########################"
make
echo "#########################"

