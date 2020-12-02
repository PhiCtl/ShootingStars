//
// Created by descourt@INTRANET.EPFL.CH on 30.11.20.
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
    Vector<T> operator*(const T&);

    T operator*(const Vector&) const;

    //Utils
    void Push_back(const T&);
    T Norm() const;
};

#endif //LINEAR_SOLVERS_VECTOR_H