#! /usr/bin/bash

mkdir build
echo "#########################"
cmake -S ./src -B ./build
echo "#########################"
cd ./build
echo "#########################"
make
echo "#########################"

