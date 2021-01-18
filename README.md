# Project 1: Linear systems

*Philippine des Courtils, Stella Petronio*

The project consists in the implementation of several direct and iterative methods for the solution of the linear systems taking advantage of the performing tools offerted by the C++ Object-Oriented Language. Precisely, regarding the direct methods we focused on the **LU factorization** and the **Cholesky factorization** and for the iterative ones we concentrated on the splitting methods **Jacobi** and **Gauss-Seidel** and then on the **Conjugate Gradient** and **Richardson** methods.

The project was build and run on CLion. 

## How to compile 

--- 

The project has been developed with the following structure based on the coming mothers and daughters classes:

## (Mother) Classes
**Matrix** class (header file: `Matrix.h`, implementation class file: `Matrix.cpp`): Matrix is a template class which takes as members the number of rows (*rows*) and columns (*cols*), both of type int, and a matrix (*matrix*) of type STL vector of STL vector. All these members are declared protected.
The class, moreover, contains the following public methods or functions:
- A default constructor: *Matrix();*
- A constructor with the numbers of rows, columns and an initial value as parameters: *Matrix(int r, int c, const T& value = 0.0);*
- A constructor with the number of rows and a STL vector as parameters: *Matrix(int c, vector <T> vec);* 
- A constuctor with a matrix as a STL vector of STL vector as unique parameter:* Matrix(vector<vector<T>> mat);*
- A copy constructor: *Matrix(const Matrix<T>& mat);*
- A destructor: *virtual ~Matrix();* 
- A read and write operator: *vector<T>& operator[](int i);*
- A read operator: *T operator()(int i, int j) const;*
- A overloading operator =: *virtual Matrix<T>& operator=(const Matrix<T> &mat);*
- A overloading operator +: *Matrix<T> operator+(const Matrix<T> &mat) const;*
- A overloading operator -: *Matrix<T> operator-(const Matrix<T> &mat) const;*
- A overloading operator * between two matrices: *Matrix<T> operator*(const Matrix<T> &mat) const;*
- A overloading operator * between a matrix and a scalar: *Matrix<T> operator*(const T& value) const;*
- A function that returns the transpose matrix: *Matrix<T> transpose() const;*
- A function that returns a diagonal matrix: *Matrix<T> DiagonalMatrix() const;*
- A function that returns a lower triangular matrix: *Matrix<T> LowerTriangularMatrix() const;*
- A function that returns an upper triangular matrix: *Matrix<T> UpperTriangularMatrix() const;*
- A friend function that returns a identity matrix: *friend Matrix<R> Identity(int);* 
- A friend overloading operator ==: *friend bool operator==(const Matrix<R>&, const Matrix<R>&);*
- A get method for the rows: *int getRows() const;*
- A get method for the columns: *int getCols() const;*
- A get method??: *vector<vector<T>> getValue() const;*

 
  
--- 

**LinearSolver** class (header file: `LinearSolver.h`): The LinearSolver class is a template mother class for any linear solver. It is formed by:
- A default constructor: *LinearSolver() {};*
- A destructor: *virtual ~LinearSolver() {};*
- A Solve overridden method which takes as input a Matrix A, a Vector b and returns a Vector x, which represents the solution of the linear system Ax = b:  *virtual Vector<T> Solve(const Matrix<T>& A, const Vector<T>& b) {};*

---   

**Reader** class (header file: `Reader.h`, implementation class file: `Reader.cpp`): Reader is a generic reader class from any istream. It has a boolean complex entry as a protected memeber of the class, which indicates the presence of any complex entries in the input. The Reader class displays:
- A constructor with a boolean as a parameter: *Reader(bool complex);*
- A destructor: *~Reader();*
- A void Matrix_Reader method which reads a matrix from a stream: *void Matrix_Reader(Matrix<T>& A, istream& f, int dim);*
- A void Vector_Reader method which reads a vector from a stream: *void Vector_Reader(Vector<T>& b, istream& f, int dim);*
- *bool found_complex(string input);*

--- 

**Writer** class (header file: `Writer.h`, implementation class file: `Writer.cpp`):

--- 
  
## Daughter Classes
**Vector** class (header file: `Vector.h`, implementation class file: `Vector.cpp`): The Vector class is a template daugher class from the mother Matrix class

--- 

**NonIterarive_Solver** class (header file: `NonIterative_Solver.h`, implementation class file: `NonIterative_Solver.cpp`): The NonIterative_Solver class is a template daugher class from the mother LinearSolver class

--- 

**Iterative_Solver** class (header file: `Iterative_Solver.h`, implementation class file: `Iterative_Solver.cpp`):  The Iterative_Solver class is a template daugher class from the mother LinearSolver class

--- 

**CommandLineReader** class (header file: `CommandLineReader.h`, implementation class file: `CommandLineReader.cpp`):  The CommandLineReader class is a daugher class from the mother Reader class

--- 

**FileReader** class (header file: `FileReader.h`, implementation class file: `FileReader.cpp`):  The FileReader class is a daugher class from the mother Reader class

## Daughter of Daughter Classes
* **LU** class (header file: `LU.h`, implementation class file: `LU.cpp`): The LU class is a template daugher class from the daugher NonIterarive_Solver class
* **Cholesky** class (header file: `Cholesky.h`, implementation class file: `Cholesky.cpp`): The Cholesky class is a template daugher class from the daugher NonIterarive_Solver class
* **Jacobi** class (header file: `Jacobi.h`, implementation class file: `Jacobi.cpp`): The Jacobi class is a template daugher class from the daugher Iterarive_Solver class
* **Gauss_Seidel** class (header file: `Gauss_Seidel.h`, implementation class file: `Gauss_Seidel.cpp`): The Gauss_Seidel class is a template daugher class from the daugher Iterarive_Solver class
* **Richardson** class (header file: `Richardson.h`, implementation class file: `Richardson.cpp`): The Richardson class is a template daugher class from the daugher Iterarive_Solver class
* **Conjugate_Gradient** class (header file: `Conjugate_Gradient.h`, implementation class file: `Conjugate_Gradient.cpp`): The Conjugate_Gradient class is a template daugher class from the daugher Iterarive_Solver class







