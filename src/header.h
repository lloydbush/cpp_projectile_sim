// Copyright 2024 lorax

#pragma once

#include <iostream>
#include <string>

#include "./environment.h"
#include "./projectile.h"

// #define DEBUG  // uncomment for DEBUG info

#ifdef DEBUG
#define DEBUG_MSSG(mssg) std::cout \
    << "DEBUG(" << __FILE__ << ":" << __LINE__ << "): " << mssg << "\n";
#else
#define DEBUG_MSSG(mssg)
#endif

#define ERROR(mssg) std::cout \
    << "ERROR(" << __FILE__ << ":" << __LINE__ << "): " << mssg << "\n";

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
        std::string file);

int readEnv(environment &e);
int readProj(projectile &p);

int logo();

