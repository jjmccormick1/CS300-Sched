cmake_minimum_required(VERSION 3.13)
project(sched C)

set(CMAKE_C_STANDARD 11)

add_executable(sched process.c vm.c proc.c proc.h proctest.c)