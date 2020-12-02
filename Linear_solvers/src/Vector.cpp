//
// Created by descourt@INTRANET.EPFL.CH on 28.11.20.
//
#include <cassert>
#include <Vector.h>
#include <complex>

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
    auto func = [&it] (vector<T>& vec) {
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

template <typename T> T Vector<T>::operator*(const Vector<T>& vec) const {
    if(vec.getRows() != this->rows)
        throw runtime_error("Incorrect dimensions for vector multiplication.");
    T scalar_prod = 0.0;
    for(int i = 0; i < this->rows; ++i)
    {
        scalar_prod = scalar_prod + vec(i) * (*this)(i);
    }
    return scalar_prod;

}

template <typename T> Vector<T> Vector<T>::operator*(const T& val) {
    Vector<T> res = (*this);
    for(auto& el: res.matrix)
        el[0] *= val;
    return res;
}

//Utils functions
template <typename T> void Vector<T>::Push_back(const T& el) {
    this->matrix.push_back({el});
    ++this->rows;
}
template <typename T> double Vector<T>::Norm() const
{
    double norm_(0.0);
    for(int i = 0; i < this->rows; ++i)
    {
        auto real_part = real((*this)(i));
        auto im_part = imag((*this)(i));
        norm_ += pow(real_part,2);
        norm_ += pow(im_part, 2);
    }
    return sqrt(norm_);
}

//to make a happy compiler: supported types;
template class Vector<double>;
template class Vector<int>;
template class Vector<long int>;
template class Vector<long long int>;
template class Vector<float>;
template class Vector<complex<float>>;
template class Vector<complex<double>>;









