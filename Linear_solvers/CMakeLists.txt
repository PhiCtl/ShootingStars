cmake_minimum_required(VERSION 3.0)
project(Linear_solvers)
set(CMAKE_CXX_STANDARD 20)

#DIRECTORIES
include_directories(${GTEST_INCLUDE_DIRS}/test ${CMAKE_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES( BEFORE lib/tclap-1.2.2/include )
add_subdirectory(lib/googletest)


#LIBRARIES
add_library(Matrix src/Matrix.cpp)
add_library(Vector src/Vector.cpp)
add_library(NonItSolvers src/LinearSolver.h src/NonIterative_Solver.cpp src/Cholesky.cpp  src/LU.cpp)
add_library(ItSolvers src/LinearSolver.h src/Iterative_Solver.cpp src/Conjugate_Gradient.cpp src/Jacobi.cpp src/Gauss_Seidel.cpp src/Richardson.cpp)
add_library(ReadWrite src/Reader.cpp src/Writer.cpp src/CommandLineReader.cpp src/FileReader.cpp)


#MAIN
add_executable(main src/main.cpp)
target_link_libraries(main Matrix Vector ItSolvers ReadWrite)

#TESTS
add_executable(test_Vector test/VectorTest.cpp)
add_executable(test_nonItSol test/NonItSolverTest.cpp)
add_executable(test_Matrix test/MatrixTest.cpp)
add_executable(test_interface test/InterfaceTest.cpp)
add_executable(test_ItSol test/ItSolverTest.cpp)

target_link_libraries(test_Vector gtest_main gtest pthread Vector Matrix ReadWrite)
target_link_libraries(test_Matrix gtest_main gtest pthread Matrix)
target_link_libraries(test_nonItSol gtest_main gtest pthread Vector Matrix NonItSolvers ReadWrite)
target_link_libraries(test_interface gtest_main gtest pthread  Vector Matrix ReadWrite)
target_link_libraries(test_ItSol gtest_main gtest pthread Vector Matrix ItSolvers)

add_custom_target(test1 ./test_Vector DEPENDS test_Vector)
add_custom_target(test2 ./test_nonItSol DEPENDS test_nonItSol)
add_custom_target(test3 ./test_Matrix DEPENDS test_Matrix)
add_custom_target(test4 ./test_interface DEPENDS test_interface)
add_custom_target(test5 ./test_ItSol DEPENDS test_ItSol)



