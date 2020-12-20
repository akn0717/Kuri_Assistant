cmake_minimum_required(VERSION 3.17)
project(Kuri_Assistant)

set(CMAKE_CXX_STANDARD 14)

include_directories(Kuri_Assistant)

add_executable(Kuri_Assistant
        Kuri_Assistant/ACore.cpp
        Kuri_Assistant/ACore.h
        Kuri_Assistant/Dictionary.cpp
        Kuri_Assistant/Dictionary.h
        Kuri_Assistant/Kuri_Assistant.cpp
        Kuri_Assistant/Kuri_Assistant.h
        Kuri_Assistant/main.cpp
        Kuri_Assistant/Ultility.cpp)
