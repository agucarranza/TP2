cmake_minimum_required(VERSION 3.10)
project(TP2 C)

set(CMAKE_C_STANDARD 99)

add_executable(TP2 main.c func.h func.c parseo.c parseo.h)


add_executable(testeo test.c)