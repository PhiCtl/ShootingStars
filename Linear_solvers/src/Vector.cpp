//
// Created by descourt@INTRANET.EPFL.CH on 28.11.20.
//
#ifndef LINEAR_SOLVERS_VECTOR_H
#define LINEAR_SOLVERS_VECTOR_H
#include "Matrix.cpp"
#include <vector>
#include <cmath>

template <typename T = double> class Vector: public Matrix<T>{
public:
    //constructors
    Vector();
    Vector(int n, T el= 0.0);
    Vector(int n, vector<T> vec);
    Vector(vector<T>); //needed for equal operator (cannot be called by itself since ambiguous call)
    Vector(const Vector&);
    Vector(const Matrix<T>&); //to check

    //Destructor
    ~Vector();

    //overload operators
    T& operator[](size_t);
    T operator()(size_t) const;
    T operator/(const Vector&) const;
    Vector<T>& operator=(const vector<T>&);
    Vector<T>& operator=(const Matrix<T>&) override;
    Vector<T>& operator=(const Vector&);

    //
    void Push_back(const T&);
    T Norm();
};

#endif //LINEAR_SOLVERS_VECTOR_H

#include <cassert>

//a vector is defined as a column vector (cols = 1)

template <typename T> Vector<T>::Vector():Matrix<T>() {}
template <typename T> Vector<T>::~Vector<T>() = default;;

//redefining the constructors
template <typename T> Vector<T>::Vector(int n, T el):Matrix<T>(n,1,el) {} //vector is a matrix with n rows and 1 col
//template <typename T> Vector<T>::Vector(int n, int m, T el):Matrix<T>(n,1,el) {} //correction
template <typename T> Vector<T>::Vector(int n, vector<T> vec):Matrix<T>(1, vec) {
    //std::cerr << "Ambiguous call to constructor. Vector size will be automatically set to size of parameter." << std::endl;
}
template <typename T> Vector<T>::Vector(vector<T> vec):Matrix<T>(1,vec) {}

//copy constructors
template <typename T>
Vector<T>::Vector(const Vector& vec){
    this->matrix = vec.matrix;
    this->cols = vec.cols;
    this->rows = vec.rows;
}

template <typename T> Vector<T>::Vector(const Matrix<T>& mat)
{
    if(mat.getCols() !=1 )
        throw runtime_error("Cannot assign non unicolumn matrix to a unicolumn vector.");
    this->matrix = mat.getValue();
    this->rows = mat.getRows();
    this->cols = 1;
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
    if( (this->getCols() !=1) and (vec.getCols() !=1) )
    {
        throw runtime_error("Cannot divide vectors of size larger than 1");
    }
    return this->matrix[0][0] / vec.matrix[0][0];
}

template <typename T> Vector<T>& Vector<T>::operator=(const vector<T>& vec) {
    this->cols = vec.size();
    this->rows = 1;

    this->matrix.clear();
    this->matrix.resize(this->cols);
    auto it = vec.begin();
    auto func = [&it] (Vector& vec) {
        vec.push_back(*it);
        ++it;
    };
    for_each(this->matrix.begin(), this->matrix.end(), func);
    return (*this);
}

template <typename T> Vector<T>& Vector<T>::operator=(const Matrix<T> & mat) {
    if(mat.getCols() !=1 )
        throw runtime_error("Cannot assign non unicolumn matrix to a unicolumn vector.");
    this->rows = mat.getRows();
    this->cols = 1;
    this->matrix = mat.getValue();
    return *this;
}

template <typename T> Vector<T>& Vector<T>::operator=(const Vector<T> & vec) {
    this->rows = vec.rows;
    this->cols = 1;
    this->matrix = vec.matrix;
    return *this;
}

//useful functions
template <typename T> void Vector<T>::Push_back(const T& el) {
    this->matrix.push_back({el});
}
template <typename T> T Vector<T>::Norm()
{
    T norm_;
    for(int i = 0; i < this->rows; ++i)
    {
        norm_ += pow((*this)[i],2);
    }
    return sqrt(norm_);
}











