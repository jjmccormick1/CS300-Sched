cmake_minimum_required(VERSION 3.13)
project(sched C)

set(CMAKE_C_STANDARD 11)

add_executable(sched  sched.h sched.c proc.c proc.h procgen.c procgen.h)
target_link_libraries(sched m)

project(procgen C)

set(CMAKE_C_STANDARD 11)

add_executable(procgen procgen.c)