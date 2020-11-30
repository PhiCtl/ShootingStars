//
// Created by descourt@INTRANET.EPFL.CH on 28.11.20.
//
#ifndef LINEAR_SOLVERS_VECTOR_H
#define LINEAR_SOLVERS_VECTOR_H
#include "Matrix.cpp"
#include <vector>

template <typename T = double> class Vector: public Matrix<T>{
public:
    Vector();
    Vector(int n, T el= 0.0);
    Vector(int n, int m, T el = 0.0);
    Vector(int n, vector<T> vec);
    Vector(vector<T>);
    Vector(const Vector&);

    ~Vector();

    T& operator[](size_t);
    T operator()(size_t) const;
    T operator/(const Vector&) const;
    void Push_back(const T&);
};

#endif //LINEAR_SOLVERS_VECTOR_H

#include <cassert>

//a vector is defined as a column vector (cols = 1)

template <typename T> Vector<T>::Vector():Matrix<T>() {}

//redefining the constructors
template <typename T> Vector<T>::Vector(int n, T el):Matrix<T>(n,1,el) {} //vector is a matrix with n rows and 1 col
template <typename T> Vector<T>::Vector(int n, int m, T el):Matrix<T>(n,1,el) {} //correction
template <typename T> Vector<T>::Vector(int n, vector<T> vec):Matrix<T>(1, vec) {} //make sure this is cect
template <typename T> Vector<T>::Vector(vector<T> vec):Matrix<T>(1,vec) {}

//copy constructor
template <typename T> Vector<T>::Vector(const Vector& vec){
    this->matrix = vec.matrix;
    this->cols = vec.cols;
    this->rows = vec.rows;
}


//operators
template <typename T> T Vector<T>::operator()(size_t i) const {
    assert(i < this->rows);
    return this->matrix[i][0];
}
template <typename T> T& Vector<T>::operator[](size_t i) {
    assert( i < this->rows);
    return this->matrix[i][0];
}

template <typename T> T Vector<T>::operator/(const Vector<T>& vec) const {
    if( ((*this)->getCols() !=1) and (vec.getCols() !=1) )
    {
        throw runtime_error("Cannot divide vectors of size larger than 1");
    }
    return (*this)->matrix[0][0] / vec.matrix[0][0];
}

template <typename T> void Vector<T>::Push_back(const T& el) {
    this->matrix.push_back({el});
}







