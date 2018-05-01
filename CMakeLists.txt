cmake_minimum_required(VERSION 3.9)
project(Graphs4)
set(EXECUTABLE_NAME "Graphs4")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra")

include_directories(include/)

file(GLOB SOURCES "src/*.cpp")
add_executable(${EXECUTABLE_NAME} ${SOURCES} include/DiGraph.h src/GraphRepresentation.cpp include/GraphRepresentation.h include/AdjMatrix.h src/DiGraph.cpp src/AdjMatrix.cpp include/GraphException.h)