//
// Created by descourt@INTRANET.EPFL.CH on 02.12.20.
//

#ifndef LINEAR_SOLVERS_MATRIX_H
#define LINEAR_SOLVERS_MATRIX_H

//Template declaration class Matrix
template<typename T = double>
class Matrix{
protected:
    int rows; //number of rows
    int cols; //number of columns
    vector<vector<T>> matrix; //matrix
public:
    /*
     * Constructors:
     * -default constructor
     * -three parameters: number of rows, number of columns, and initial value of tzpe T
     * -one parameter: a vector of vector of type T
     * -two parameters: rows and a vector
     * -a copy constructor
    */
    Matrix();
    Matrix(int r, int c, const T& value = 0.0);
    Matrix(int r, vector <T> vec);
    Matrix(vector<vector<T>> mat);
    Matrix(const Matrix<T>& mat);
    //Matrix(initializer_list<T>);

    //Destructor
    virtual ~Matrix();

    //Read and write operator
    vector<T>& operator[](int i);
    //Read operator
    T operator()(int i, int j) const;

    /*
     * Operations between matrices:
     * -Equal operator
     * -Addition
     * -Subtraction
     * -Multiplication
    */
    virtual Matrix<T>& operator=(const Matrix<T> &mat);
    Matrix<T> operator+(const Matrix<T> &mat) const;
    Matrix<T> operator*(const Matrix<T> &mat) const;
    Matrix<T> operator-(const Matrix<T> &mat) const;

    //Multiplication between matrix and scalar
    Matrix<T> operator*(const T& value) const;

    //Return a transpose matrix
    Matrix<T> transpose() const;
    //Return a lower triangular matrix
    Matrix<T> LowerTriangularMatrix() const;
    //Return a upper triangular matrix
    Matrix<T> UpperTriangularMatrix() const;
    //Return a diagonal matrix (with the main diagonal)
    Matrix<T> DiagonalMatrix() const;

    //Return Identity Matrix
    template <typename R> friend Matrix<R> Identity(int);

    //vector<T> solve(const vector<T>& vec);

    //Get rows size
    int getRows() const;
    //Get cols size
    int getCols() const;
    //Get matrix value as a vector or vector of T
    vector<vector<T>> getValue() const;

    //Print the matrix
    void Print(std::ostream &s) const;
};

#endif //LINEAR_SOLVERS_MATRIX_H
