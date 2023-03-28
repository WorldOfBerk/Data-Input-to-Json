cmake_minimum_required(VERSION 3.23)
project(DataConverter C)

set(CMAKE_C_STANDARD 99)

add_executable(DataConverter main.c json_writer.c json_writer.h inp_validator.c inp_validator.h)
