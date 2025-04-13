cmake_minimum_required(VERSION 3.30)
project(Lab01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab01
    ChatGPT.cpp
    ChatGPT.h
    DTFecha.cpp
    DTFecha.h
    DTInfoEstudiante.cpp
    DTInfoEstudiante.h
    Estudiante.cpp
    Estudiante.h
    Informacion.cpp
    Informacion.h
    Libro.cpp
    Libro.h
    main.cpp
    PaginaWeb.cpp
    PaginaWeb.h)
