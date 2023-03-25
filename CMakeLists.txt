cmake_minimum_required(VERSION 3.24)
project(vector_editor C)

set(CMAKE_C_STANDARD 11)

add_executable(vector_editor
        main.c menu.c shapes.c shapes.h structure.c structure.h id.h id.c)
