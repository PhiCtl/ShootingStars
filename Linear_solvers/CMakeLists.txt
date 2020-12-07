cmake_minimum_required(VERSION 3.17)
project(Linear_solvers)

set(CMAKE_CXX_STANDARD 20)
INCLUDE_DIRECTORIES( BEFORE tclap-1.2.2/include )

#add_executable(Linear_solvers main.cpp)
include_directories(${GTEST_INCLUDE_DIRS}/test ${CMAKE_SOURCE_DIR}/src)
#add_executable(test test.cpp Test.cpp)
add_executable(Matrix Matrix.cpp test/MatrixTest.cpp)
add_executable(Solvers src/Solvers.cpp)
add_executable(TestVector src/TestVector.cpp Matrix.cpp src/Vector.cpp)
add_executable(TestNonIterative src/TestNonIterative.cpp src/Vector.cpp Matrix.cpp src/LinearSolver.h src/LU.cpp src/Cholesky.cpp src/NonIterative_Solver.cpp)
add_executable(TestIterativeSolver src/TestIterativeSolver.cpp src/Vector.cpp Matrix.cpp src/LinearSolver.h src/Iterative_Solver.cpp src/Conjugate_Gradient.cpp src/Jacobi.cpp src/Gauss_Seidel.cpp src/Richardson.cpp)
