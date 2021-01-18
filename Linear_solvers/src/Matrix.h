//
// Created by descourt@INTRANET.EPFL.CH on 02.12.20.
//

#ifndef LINEAR_SOLVERS_MATRIX_H
#define LINEAR_SOLVERS_MATRIX_H
#include <vector>
#include <iostream>
#include <complex>
using namespace std;

/*! @brief Matrix class: template class
 *
 * @tparam T
 */

template<typename T = double>
class Matrix{
protected:
    int rows;
    int cols;
    vector<vector<T>> matrix;
public:

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
    * @param i : int index of the requested row's entry in the Matrix
    * @param j : int index of the requested column's entry in the Matrix
    * @return (i,j)th entry of the Matrix
    */
    T operator()(int i, int j) const;

    /*! @brief overloading operator =
     *
     * @param mat: matrix
     * @return reference to this
     */
    virtual Matrix<T>& operator=(const Matrix<T> &mat);

    /*! @brief overloading operator +
     *
     * @param mat: matrix
     * @return a Matrix which is the addition between the Matrix this and the Matrix mat
     */
    Matrix<T> operator+(const Matrix<T> &mat) const;

    /*! @brief overloading operator *
     *
     * @param mat: matrix
     * @return a Matrix which is the multiplication between the Matrix this and the Matrix mat
     */
    Matrix<T> operator*(const Matrix<T> &mat) const;

    /*! @brief overloading operator -
     *
     * @param mat: matrix
     * @return a Matrix which is the subtraction between the Matrix this and Matrix mat
     */
    Matrix<T> operator-(const Matrix<T> &mat) const;

    /*! @brief overloading operator *
     *
     * @param value: scalar
     * @return a Matrix which is the multiplication between the Matrix this and a scalar
     */
    Matrix<T> operator*(const T& value) const;

    /** @brief transpose: returns a Matrix which is the transpose of Matrix this */
    Matrix<T> transpose() const;

    /** @brief LowerTriangularMatrix: returns a Matrix which is the Lower Triangular matrix of Matrix this */
    Matrix<T> LowerTriangularMatrix() const;

    /** @brief UpperTriangularMatrix: returns a Matrix which is the Upper Triangular matrix of Matrix this */
    Matrix<T> UpperTriangularMatrix() const;

    //Return a diagonal matrix (with the main diagonal)
    /** @brief DiagonalMatrix: returns a Matrix which is the diagonal matrix of Matrix this */
    Matrix<T> DiagonalMatrix() const;

    /*! @brief Identity (friend function)
    *
    * @param n: dimension of the square matrix
    * @return returns a Matrix which is an identity matrix
    */
    template <typename R>
    friend Matrix<R> Identity(int);


    /*! @brief overloading operator == (friend function)
     *
     * @param A: matrix A
     * @param B: matrix B
     * @return returns true or false depending to the fact if the two matrices are equal
     */
    template <typename R>
    friend bool operator==(const Matrix<R>&, const Matrix<R>&);

    /*! @brief getRows
     *
     * @return returns the size of the rows
     */
    int getRows() const;

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
