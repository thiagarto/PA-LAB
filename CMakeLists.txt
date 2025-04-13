cmake_minimum_required(VERSION 3.30)
project(Lab01)

set(CMAKE_CXX_STANDARD 14)

include_directories(Lab01)

add_executable(Lab01
    Lab01/ChatGPT.cpp
    Lab01/ChatGPT.h
    Lab01/DTFecha.cpp
    Lab01/DTFecha.h
    Lab01/DTInfoEstudiante.cpp
    Lab01/DTInfoEstudiante.h
    Lab01/Estudiante.cpp
    Lab01/Estudiante.h
    Lab01/Informacion.cpp
    Lab01/Informacion.h
    Lab01/Libro.cpp
    Lab01/Libro.h
    Lab01/main.cpp
    Lab01/PaginaWeb.cpp
    Lab01/PaginaWeb.h)
