//
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
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

};

#endif //LINEAR_SOLVERS_VECTOR_H
