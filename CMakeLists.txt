cmake_minimum_required(VERSION 3.15)
project(QueensPuzzleSATwithC__)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)
link_directories(libs)
link_libraries("libcadical.a")
add_executable(QueensPuzzleSATwithC__ src/main.cpp src/generateSAT.cpp include/generateSAT.h)
#target_link_libraries(QueensPuzzleSATwithC__ "libs/libcadical.a")