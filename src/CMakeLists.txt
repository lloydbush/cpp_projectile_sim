cmake_minimum_required(VERSION 3.20.0)

file(GLOB src "*.cpp")

project(projectile_sim)

add_executable(${PROJECT_NAME} ${src})

