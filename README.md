# Project 1: Linear systems

*Philippine des Courtils, Stella Petronio*

The project consists in the implementation of several direct and iterative methods for the solution of the linear systems using Matrix operations. More precisely, regarding the direct methods we focused on the **LU factorization** and the **Cholesky factorization** and for the iterative ones we concentrated on the splitting methods **Jacobi** and **Gauss-Seidel** and then on the **Conjugate Gradient** and **Richardson** methods.

The project was build and run on CLion. 

## How to compile 


The project has been developed with the following structure based on the coming mothers and daughters classes:

## (Mother) Classes
* **Matrix** class (header file: `Matrix.h`, implementation class file: `Matrix.cpp`): Matrix is a template class which takes as members 
* **LinearSolver** class (header file: `LinearSolver.h`, implementation class file: ??):
* **Reader** class (header file: `Reader.h`, implementation class file: `Reader.cpp`): 
* **Writer** class (header file: `Writer.h`, implementation class file: `Writer.cpp`):

## Daughter Classes
* **Vector** class (header file: `Vector.h`, implementation class file: `Vector.cpp`): The Vector class is a template daugher class from the mother Matrix class
* **NonIterarive_Solver** class (header file: `NonIterative_Solver.h`, implementation class file: `NonIterative_Solver.cpp`): The NonIterative_Solver class is a template daugher class from the mother LinearSolver class
* **Iterative_Solver** class (header file: `Iterative_Solver.h`, implementation class file: `Iterative_Solver.cpp`):  The Iterative_Solver class is a template daugher class from the mother LinearSolver class
* **CommandLineReader** class (header file: `CommandLineReader.h`, implementation class file: `CommandLineReader.cpp`):  The CommandLineReader class is a daugher class from the mother Reader class

## Daughter of Daughter Classes
* **LU** class (header file: `LU.h`, implementation class file: `LU.cpp`): The LU class is a template daugher class from the daugher NonIterarive_Solver class
* **Cholesky** class (header file: `Cholesky.h`, implementation class file: `Cholesky.cpp`): The Cholesky class is a template daugher class from the daugher NonIterarive_Solver class
* **Jacobi**class (header file: `Jacobi.h`, implementation class file: `Jacobi.cpp`): The Jacobi class is a template daugher class from the daugher Iterarive_Solver class
* **Gauss_Seidel**class (header file: `Gauss_Seidel.h`, implementation class file: `Gauss_Seidel.cpp`): The Gauss_Seidel class is a template daugher class from the daugher Iterarive_Solver class
* **Richardson**class (header file: `Richardson.h`, implementation class file: `Richardson.cpp`): The Richardson class is a template daugher class from the daugher Iterarive_Solver class
* **Conjugate_Gradient** class (header file: `Conjugate_Gradient.h`, implementation class file: `Conjugate_Gradient.cpp`): The Conjugate_Gradient class is a template daugher class from the daugher Iterarive_Solver class


