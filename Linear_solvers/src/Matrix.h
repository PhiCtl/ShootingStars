//
// Created by descourt@INTRANET.EPFL.CH on 02.12.20.
//

#ifndef LINEAR_SOLVERS_MATRIX_H
#define LINEAR_SOLVERS_MATRIX_H
#include <vector>
#include <iostream>
#include <complex>
using namespace std;
//Template declaration class Matrix
/*! @brief Matrix class: template class
 *
 * @tparam T
 */
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
    /*! @brief Constructor (default)
     *
     */
    Matrix();

    /*! @brief Constructor
     *
     * @param r : number of rows
     * @param c : number of columns
     * @param value : initial value for each entry
     */
    Matrix(int r, int c, const T& value = 0.0);

    /*! @brief Constructor
     *
     * @param c: number of columns
     * @param vec : STL vector as a value for each column of the Matrix
     */
    Matrix(int c, vector <T> vec);

    /*! @brief Constructor
     *
     * @param mat : matrix as a STL vector of STL vector
     */
    Matrix(vector<vector<T>> mat);

    /*! @brief Copy Constructor
     * @param mat: another Matrix of same type T
     */
    Matrix(const Matrix<T>& mat);

    //Destructor
    /** @brief Destructor */
    virtual ~Matrix();

    //Read and write operator
    /*! @brief overloading read/write operator
    *
    * @param i : int index of requested vector in the Matrix (??)
    * @return reference to ith STL vector
    */
    vector<T>& operator[](int i);

    //Read operator
    /*! @brief overloading read only operator
    *
    * @param i : int index of requested row in the Matrix
    * @param j : int index of requested column in the Matrix
    * @return (i,j)th entry of the Matrix
    */
    T operator()(int i, int j) const;

    /*
     * Operations between matrices:
     * -Equal operator
     * -Addition
     * -Subtraction
     * -Multiplication
    */

    /*! @brief overloading operator =
     *
     * @param mat: matrix
     * @return reference to this
     */
    virtual Matrix<T>& operator=(const Matrix<T> &mat);
    /*! @brief overloading operator +
     *
     * @param mat: matrix
     * @return addition between the matrix this and matrix mat
     */
    Matrix<T> operator+(const Matrix<T> &mat) const;
    /*! @brief overloading operator *
     *
     * @param mat: matrix
     * @return multiplication between the matrix this and matrix mat
     */
    Matrix<T> operator*(const Matrix<T> &mat) const;
    /*! @brief overloading operator -
     *
     * @param mat: matrix
     * @return subtraction between the matrix this and matrix mat
     */
    Matrix<T> operator-(const Matrix<T> &mat) const;

    //Multiplication between matrix and scalar
    /*! @brief overloading operator *
     *
     * @param value: scalar
     * @return multiplication between the matrix this and a scalar
     */
    Matrix<T> operator*(const T& value) const;


    //Return a transpose matrix
    /** @brief transpose: returns the transpose of this Matrix */
    Matrix<T> transpose() const;

    //Return a lower triangular matrix
    /** @brief LowerTriangularMatrix: returns the lower triangular matrix of this Matrix */
    Matrix<T> LowerTriangularMatrix() const;

    //Return a upper triangular matrix
    /** @brief UpperTriangularMatrix: returns the upper triangular matrix of this Matrix */
    Matrix<T> UpperTriangularMatrix() const;

    //Return a diagonal matrix (with the main diagonal)
    /** @brief DiagonalMatrix: returns the diagonal matrix of this Matrix */
    Matrix<T> DiagonalMatrix() const;

    //Return Identity Matrix
    /*! @brief Identity
    *
    * @param n: dimension of the square matrix
    * @return returns an identity matrix
    */
    template <typename R>
    friend Matrix<R> Identity(int);

    //== operator overloading
    /*! @brief overloading operator ==
     *
     * @param A: matrix A
     * @param B: matrix B
     * @return returns true or false depending to the fact if the two matrices are equal
     */
    template <typename R>
    friend bool operator==(const Matrix<R>&, const Matrix<R>&);


    //Get rows size
    /*! @brief getRows
     *
     * @return returns the size of the rows
     */
    int getRows() const;

    //Get cols size
    /*! @brief getCols
     *
     * @return returns the size of the columns
     */
    int getCols() const;

    //Get matrix value as a vector of vector of T
    /*! @brief getValue
     *
     * @return get matrix value as a STL vector of STL vector of type T
     */
    vector<vector<T>> getValue() const;

    //Print the matrix
    /*! @brief Print
     *
     * @return print the matrix
     */
    void Print(std::ostream &s) const;
};

//friend function

template <typename T>
Matrix<T> Identity(int n)
{
    Matrix<T> I(n,n);
    for(int i = 0; i < n; ++i)
    {
        I.matrix[i][i] = 1;
    }
    return I;
}


template <typename T>
bool operator==(const Matrix<T>& A, const Matrix<T>& B)
{
    return ((A.matrix == B.matrix) && (A.getCols() == B.getCols()) &&(A.getRows() == B.getRows()) );
}

//specialization
template<typename T>
complex<T> conjug(const complex<T>& el)
{
    return conj(el);
}

template <typename T>
T conjug(const T& el)
{
    return el;
}

#endif //LINEAR_SOLVERS_MATRIX_H
