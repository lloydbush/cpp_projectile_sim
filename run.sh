#! /usr/bin/bash

if [ $1 ]
then
	./build/projectile_sim $1
	python3 plot.py $1
else
	echo "ERROR: invalid input file"
fi

