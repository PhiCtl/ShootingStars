cmake_minimum_required(VERSION 3.17)
#project(Linear_solvers)

set(CMAKE_CXX_STANDARD 14)
INCLUDE_DIRECTORIES( BEFORE tclap-1.2.2/include )

#add_executable(Linear_solvers main.cpp)
include_directories(${GTEST_INCLUDE_DIRS}/test ${CMAKE_SOURCE_DIR}/src)
add_executable(test test.cpp Test.cpp)
add_executable(Matrix src/Matrix.cpp)
add_executable(Solvers src/Solvers.cpp)
