# Project 1: Linear systems

*Philippine des Courtils, Stella Petronio*

The project consists in the implementation of several direct and iterative methods for the solution of the linear systems taking advantage of the performing tools offerted by the C++ Object-Oriented Language. Precisely, regarding the direct methods we focused on the **LU factorization** and the **Cholesky factorization** and for the iterative ones we concentrated on the splitting methods **Jacobi** and **Gauss-Seidel** and then on the **Conjugate Gradient** and **Richardson** methods.

The project was built and run on CLion. 

## Table of contents
* [Installation](#installation)
* [How to compile](#how-to-compile)
* [Folders hierarchy](#folders-hierarchy)

## Installation
The following libraries are located under the folder `lib\` and already referenced in the CMakeLists file. 
- tclap-1.2.2
- googletest

## How to compile 

### Run the program
The following commands should be run in the folder `Linear_solvers\` :
```
mdkir build
cd build
cmake ..
make
./Linear_solver   //several options should be entered here, and are specified below
```
### Program options
The TCLAP library provides a convenient interface with the user. Below are listed the command line options.

* -C, -- terminal: 
specifies that both matrix and vector will be read from the command line.
* -I, --complex : 
specifies that there is at least one complex entry in the files. 
* **-D, --dimension** (unsigned integer): 
dimension of the square matrix (input), mandatory.
* -P, --precision (unsigned integer): 
significant digits of the solution.
* **-S, --solver** (0: LU,1: Cholesky, 2: Conjugate gradient, 3: Jacobi, 4: Gauss Seidel, 5: Richardson):
method chosen to solve the linear system, mandatory.
* -O, --out (string): 
name of the output file storing the solution.
* -B, --vector (string): 
name of the file storing vector B (should be located in `data/` ), mandatory if user chooses to read vector and matrix from a file.
* -A, --matrix (string): 
name of the file storing vector A (should be located in `data/`), mandatory if user chooses to read vector and matrix from files.

The following line represents an example that the user can write from the terminal in order to run the code:
```
./Linear_solver -D 4 -S 3 -A "../data/ItSolver/Mat4x4.txt" -B "../data/ItSolver/VecB4x1.txt" -O "sol.txt"
```
The expected outcome is: 
```
Solution saved to file sol.txt
```

### Create the doxygen documentation
The command `doxygen` should be run in the main folder `Linear_solvers\`. The created html documentation can be found under `doc\html\index.htlm`. 

## Folders hierarchy 
In general, our project is inside the main folder `Linear_Solvers` which it has been developed in the following subfolders:

```bash
├── Solutions
│   └──  sol.txt
├── data
│   ├── Interface
│   │   ├── Mat.mat
│   │   └──  Vec.mat
│   ├── ItSolver
│   │   ├── ComplexMatA.txt 
│   │   ├── ComplexVecB.txt 
│   │   ├── ComplexVecSol.txt
│   │   ├── Mat20x20.txt
│   │   ├── Mat2x2.txt 
│   │   ├── Mat4x4.txt 
│   │   ├── VecB20x1.txt 
│   │   ├── VecB2x1.txt 
│   │   ├── VecB4x1.txt  
│   │   ├── VecSol20x1.txt 
│   │   ├── VecSol2x1.txt 
│   │   └──  VecSol4x1.txt  
│   ├── NonItSolver
│   │   ├── B.mat 
│   │   ├── ComplexB.txt  
│   │   ├── ComplexCholA.txt 
│   │   ├── ComplexCholSol.txt
│   │   ├── ComplexLUPA.txt
│   │   ├── ComplexLU_sol.txt
│   │   ├── L_sparse.txt 
│   │   ├── Sol.txt 
│   │   ├── U_sparse.txt
│   │   ├── sparseA.txt
│   │   ├── sparseA2.txt 
│   │   └──  sparse_chol.txt
│   ├── Vector
│   │   ├── ComplexMat.mat
│   │   ├── ComplexVec.mat 
│   │   ├── Res1.txt  
│   │   └──  Res2.txt  
├── lib
│   ├── googletest 
│   └── tclap-1.2.2
├── src
│   ├── Cholesky.cpp 
│   ├── Cholesky.h 
│   ├── CommandLineReader.cpp 
│   ├── CommandLineReader.h
│   ├── Conjugate_Gradient.cpp
│   ├── Conjugate_Gradient.h
│   ├── FileReader.cpp
│   ├── FileReader.h
│   ├── Gauss_Seidel.cpp 
│   ├── Gauss_Seidel.h
│   ├── Iterative_Solver.cpp 
│   ├── Iterative_Solver.h
│   ├── Jacobi.cpp
│   ├── Jacobi.h
│   ├── LU.cpp 
│   ├── LU.h
│   ├── LinearSolver.h
│   ├── Matrix.cpp
│   ├── Matrix.h 
│   ├── NonIterative_Solver.cpp 
│   ├── NonIterative_Solver.h
│   ├── Reader.cpp
│   ├── Reader.h
│   ├── Richardson.cpp
│   ├── Richardson.h
│   ├── Solvers.cpp
│   ├── Vector.cpp
│   ├── Vector.h
│   ├── Writer.cpp 
│   ├── Writer.h 
│   └──  main.cpp 
├── test
│   ├── InterfaceTest.cpp
│   ├── ItSolverTest.cpp  
│   ├── MatrixTest.cpp
│   ├── NonItSolverTest.cpp 
    └──  VectorTest.cpp 
├── CMakeLists.txt
├── Doxyfile 
    
```

---




