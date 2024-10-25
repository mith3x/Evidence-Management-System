cmake_minimum_required(VERSION 3.23)
project(A3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(A3
        defs.h
        evidence.c
        init.c
        main.c)
