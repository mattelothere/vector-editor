cmake_minimum_required(VERSION 3.24)
project(vector_editor C)

set(CMAKE_C_STANDARD 11)

add_executable(vector_editor
        main.c shapes.c shapes.h structure.c menu.c id.c area.h area.c pixel.c pixel.h)
