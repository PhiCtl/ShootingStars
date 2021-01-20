#include<iostream>
#include <exception>
#include <algorithm>
#include <complex>
using namespace std;
#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(){
    rows = 0;
    cols = 0;

}

template<typename T>
Matrix<T>::Matrix(int r, int c, const T& value){
    if(r < 0 || c < 0){
        throw invalid_argument("Error: negative dimension!");
    } else {
        rows = r;
        cols = c;

        matrix.resize(rows);

        for (int i = 0; i < matrix.size(); i++){
            matrix[i].resize(cols,value);
        }
    }

}

//Constructor with the same vector for each column
template<typename T>
Matrix<T>::Matrix(int r, vector<T> vec){
    if(r < 0){
        throw invalid_argument("Error: negative dimension!");
    }else{
        cols = r;
        rows = vec.size();
        matrix.resize(rows);
        auto it = vec.begin();
        auto func = [&it, r] (vector<T>& vec) {
            vec.resize(r);
            for(auto& el: vec)
                el = *it;
            ++it;
        };
        for_each(matrix.begin(), matrix.end(), func);
    }

}

template<typename T>
Matrix<T>::Matrix(vector<vector<T>> mat){
    rows = mat.size();
    cols = mat[0].size();
    matrix = mat;
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& mat){
    matrix = mat.matrix;
    rows = mat.getRows();
    cols = mat.getCols();
}

template<typename T>
Matrix<T>::~Matrix() {};

template<typename T>
int Matrix<T>::getRows() const{
    return (*this).rows;
}

template<typename T>
int Matrix<T>::getCols() const{
    return (*this).cols;
}

template <typename T>
vector<vector<T>> Matrix<T>::getValue() const {
    return matrix;
}

template<typename T>
vector<T>& Matrix<T>::operator[](int i){
    return matrix[i];
}

template<typename T>
T Matrix<T>::operator()(int i, int j) const{
    return matrix[i][j];
}


template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &mat) const {

    if((rows != mat.getRows()) || (cols != mat.getCols())){
        throw invalid_argument("Error: the matrices must have the same number of rows and columns.");
    }else{

        Matrix res(rows,cols,0.0);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                res[i][j] = this->matrix[i][j] + mat(i,j);
            }
        }
        return res;
    }
}


template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &mat) const{

    if((rows != mat.getRows()) || (cols != mat.getCols())){
        throw invalid_argument("Error: the matrices must have the same number of rows and columns.");
    }else{
        Matrix res(rows,cols,0.0);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                res[i][j] = this->matrix[i][j] - mat(i,j);
            }
        }
        return res;
    }
}


template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &mat) const {
    if(cols != mat.getRows()){
        throw invalid_argument("Error: for matrix multiplication, the number of columns in the first matrix must be equal to the number of rows in the second matrix. ");
    } else {

        Matrix res(rows,mat.getCols(),0.0);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < mat.getCols(); j++){
                for(int k = 0; k < cols; ++k)
                    res[i][j] += this->matrix[i][k] * mat(k,j);
            }
        }
        return res;
    }

}


template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& mat) {

    rows = mat.getRows();
    cols = mat.getCols();

    this->matrix = mat.matrix;
    return *this;
}


template<typename T>
Matrix<T> Matrix<T>::operator*(const T& value) const{
    Matrix res(rows,cols,0.0);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            res[i][j] = this->matrix[i][j] * value;
        }
    }
    return res;
}

template <typename T> T Matrix<T>::operator/(const Matrix<T>& mat) const {
    if( (this->getRows() !=1) and (mat.getRows() !=1) )
    {
        throw runtime_error("Cannot divide matrices of size larger than 1");
    }
    return this->matrix[0][0] / mat.matrix[0][0];
}


template<typename T> T Matrix<T>::To_scalar() const {
    if(this->cols == 1 && this->rows == 1)
        return this->matrix[0][0];
    else
        throw invalid_argument("This matrix is not a scalar.");
}

template<typename T>
Matrix<T> Matrix<T>::transpose() const{
    Matrix mat_T(cols, rows, 0.0);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j)
            mat_T[j][i] = conjug(matrix[i][j]);
    }
    return mat_T;
}


template<typename T>
Matrix<T> Matrix<T>::LowerTriangularMatrix() const{
    Matrix mat_lower(cols, rows, 0.0);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            if (i < j){
                mat_lower[i][j] = 0.0;
            }else{
                mat_lower[i][j] = matrix[i][j];
            }
        }
    }
    return mat_lower;
}


template<typename T>
Matrix<T> Matrix<T>::UpperTriangularMatrix() const{
    Matrix mat_upper(cols, rows, 0.0);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            if (i > j){
                mat_upper[i][j] = 0.0;
            }else{
                mat_upper[i][j] = matrix[i][j];
            }
        }
    }
    return mat_upper;
}

template<typename T>
Matrix<T> Matrix<T>::DiagonalMatrix() const{
    Matrix mat_diagonal(cols, rows, 0.0);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            if (i == j){
                mat_diagonal[i][j] = matrix[i][j];
            }else{
                mat_diagonal[i][j] = 0.0;
            }
        }
    }
    return mat_diagonal;
}


template<typename T>
void Matrix<T>::Print(std::ostream &s) const{
    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j++){
            s << matrix[i][j] << " ";
        }
        s << std::endl;
    }
}



template class Matrix<int>;
template class Matrix<double>;
template class Matrix<long long int>;
template class Matrix<long int>;
template class Matrix<long double>;
template class Matrix<float>;
template class Matrix<complex<float>>;
template class Matrix<complex<long double>>;
template class Matrix<complex<double>>;

