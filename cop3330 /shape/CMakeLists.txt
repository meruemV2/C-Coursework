cmake_minimum_required(VERSION 3.15)
project(shape)

set(CMAKE_CXX_STANDARD 11)

add_executable( shape shape.cpp cmake-build-debug/square.cpp cmake-build-debug/square.h cmake-build-debug/rectangle.cpp cmake-build-debug/rectangle.h cmake-build-debug/circle.cpp cmake-build-debug/circle.h cmake-build-debug/triangle.cpp cmake-build-debug/triangle.h cmake-build-debug/main.cpp cmake-build-debug/shape.cpp cmake-build-debug/shape.h)