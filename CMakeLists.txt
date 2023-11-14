cmake_minimum_required(VERSION 3.26)
project(ProyectoProg3)

set(CMAKE_CXX_STANDARD 14)

include_directories(Estructuras)

add_executable(ProyectoProg3
        Estructuras/ArbolAVL.h
        Estructuras/Articulo.h
        Estructuras/leerCSV.h
        Estructuras/Lista.h
        Estructuras/minmaxstock.h
        Estructuras/nodo.h
        Estructuras/NodoArbolAVL.h
        main.cpp)
