// Copyright 2024 lorax
#include <iostream>
#include <string>
#include <INIReader.h>

#include "./header.h"

// parse double from INI file based on reader, section, key
int read_d(
    INIReader &reader,
    std::string sec,
    std::string key,
    std::string def,
    double &val
) {
    std::string tmp;

    tmp = reader.Get(sec, key, def);
    if (tmp != "") {
        val = stod(tmp);
        return 0;
    }

    std::cerr << "E: failed to parse " << sec << "." << key << "\n";
    return 1;
}

// read the INI file and parse values of variables
int readINI(environment &e, projectile &p) {
    char file_name[] = "sim.ini";
    INIReader reader(file_name);

    if (reader.ParseError() < 0) {
        std::cerr << "E: failed to load " << file_name << "\n";
        return 1;
    }

    if (read_d(reader, "environment", "g", "9.81", e.g) != 0) {
        return 1;
    }
    if (read_d(reader, "environment", "rho", "1.22", e.rho) != 0) {
        return 1;
    }
    if (read_d(reader, "environment", "dt",  "0.01", e.dt) != 0) {
        return 1;
    }

    if (read_d(reader, "projectile", "m",   "", p.m) != 0) {
        return 1;
    }
    if (read_d(reader, "projectile", "cd",  "", p.cd) != 0) {
        return 1;
    }
    if (read_d(reader, "projectile", "ar",  "", p.ar) != 0) {
        return 1;
    }
    if (read_d(reader, "projectile", "v0x", "", p.v0x) != 0) {
        return 1;
    }
    if (read_d(reader, "projectile", "v0y", "", p.v0y) != 0) {
        return 1;
    }
    if (read_d(reader, "projectile", "x0",  "0", p.x0) != 0) {
        return 1;
    }
    if (read_d(reader, "projectile", "y0",  "0", p.y0) != 0) {
        return 1;
    }

    return 0;
}
