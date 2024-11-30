#! /usr/bin/bash
# runs the simulation and graphs the results

if [ $1 ]
then
	./build/projectile_sim $1
else
	echo "ERROR: invalid input file"
fi

