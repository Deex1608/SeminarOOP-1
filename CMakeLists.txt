cmake_minimum_required(VERSION 3.31)
project(SeminarOOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(seminar
        Seminary4.cpp
Media.cpp
Song.cpp
Video.cpp
        MediaRepository.cpp
        MediaRepository.h
        Controller.cpp
        Controller.h)