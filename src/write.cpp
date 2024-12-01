// Copyright 2024 lorax
#include <iostream>
#include <string>
#include <fstream>

#include "./header.h"

void write(
        double t,
        double x,
        double y,
        double vx,
        double vy,
        double ax,
        double ay,
        double maxX,
        double maxY,
        std::string file) {
    static bool first = true;

    file += ".csv";  // make .csv file from file

    if (first) {
        std::ofstream writer(file);
        writer << "t,x,y,vx,vy,ax,ay\n";
        first = false;
    }

    std::ofstream writer(file, std::ios::app);  // create writer object

    writer
        << t
        << ","
        << x
        << ","
        << y
        << ","
        << vx
        << ","
        << vy
        << ","
        << ax
        << ","
        << ay
        << "\n";

    writer.close();
}
