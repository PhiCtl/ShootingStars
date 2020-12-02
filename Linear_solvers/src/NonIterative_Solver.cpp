//
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
//

#include "NonIterative_Solver.h"
#include <iostream>
#include <complex>

using namespace std;

//constructor and destructor
template <typename T> NonIterative_Solver<T>::NonIterative_Solver():LinearSolver<T>() {}

template <typename T> NonIterative_Solver<T>::~NonIterative_Solver() {}

//copy constructor which isn't really useful in practise
template <typename T> NonIterative_Solver<T>::NonIterative_Solver(const NonIterative_Solver<T>& solver) {
    this->L = solver.L;
    this->U = solver.U;

}

//Linear algebra methods common to both derived classes
template <typename T> Vector<T> NonIterative_Solver<T>::Backward_subst(const Matrix<T> &A, const Vector<T> &b) {
    int n = A.getCols(); //A is upper triangular
    Vector<T> x(n);

    for (int i = n - 1; i >= 0; --i) {
        x[i] = b(i);
        for (int j = i + 1; j < n; ++j) {
            x[i] = x(i) - A(i,j) * x(j);
        }
        if (fabs(A(i,i)) < 1e-10)
            throw runtime_error("Division by 0 in backward substitution."
                                "Matrix A doesn't fulfill requirements.");
        x[i] /= A(i,i);
    }
    return x;
}

template <typename T> Vector<T> NonIterative_Solver<T>::Forward_subst(const Matrix<T> &A, const Vector<T> &b) {
    int n = A.getCols(); //A is lower triangular
    Vector<T> x(n);
    if (fabs(A(0,0)) < 1e-10)
        throw runtime_error("Division by 0 in forward substitution."
                            "Matrix A doesn't fulfill requirements.");
    x[0] = b(0) / A(0,0);
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            x[i] -= A(i,j)*x(j);
        }
        if (fabs(A(i,i)) < 1e-10)
            throw runtime_error("Division by 0 in forward substitution."
                                "Matrix A doesn't fulfill requirements.");
        x[i] = (x(i) + b(i)) / A(i,i);
    }

    return x;
}

//getters
template <typename T> Matrix<T> NonIterative_Solver<T>::getL() {
    return this->L;
}
template <typename T> Matrix<T> NonIterative_Solver<T>::getU() {
    return this->U;
}

//make the compiler happy
template class NonIterative_Solver<int>;
template class NonIterative_Solver<double>;
template class NonIterative_Solver<long int>;
template class NonIterative_Solver<long long int>;
template class NonIterative_Solver<float>;
template class NonIterative_Solver<complex<double>>;
template class NonIterative_Solver<complex<float>>;

