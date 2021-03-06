
#include <cassert>
#include <Vector.h>
#include <complex>

template <typename T> Vector<T>::Vector():Matrix<T>() {}
template <typename T> Vector<T>::~Vector<T>() = default;


template <typename T> Vector<T>::Vector(int n, T el):Matrix<T>(n,1,el) {} //vector is a matrix with n rows and 1 col
template <typename T> Vector<T>::Vector(int n, vector<T> vec):Matrix<T>(1, vec) {}
template <typename T> Vector<T>::Vector(vector<T> vec):Matrix<T>(1,vec) {}


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



template <typename T> T Vector<T>::operator()(size_t i) const {
    assert(i < this->rows);
    return this->matrix[i][0];
}
template <typename T> T& Vector<T>::operator[](size_t i) {
    assert( i < this->rows);
    return this->matrix[i][0];
}

template <typename T> Vector<T>& Vector<T>::operator=(const vector<T>& vec) {
    this->cols = vec.size();
    this->rows = 1;

    (*this) = Vector<T>(vec);

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

template <typename T> vector<T> Vector<T>::getValue() const {
    vector<T> val;
    for(auto el: this->matrix)
        val.push_back(el[0]);
    return val;
}

template class Vector<double>;
template class Vector<int>;
template class Vector<long int>;
template class Vector<long double>;
template class Vector<long long int>;
template class Vector<float>;
template class Vector<complex<float>>;
template class Vector<complex<double>>;
template class Vector<complex<long double>>;









