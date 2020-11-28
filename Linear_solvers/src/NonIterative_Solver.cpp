//
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
//
#ifndef LINEAR_SOLVERS_NONITERATIVE_SOLVER_H
#define LINEAR_SOLVERS_NONITERATIVE_SOLVER_H

#include "LinearSolver.h"

template <typename T> class NonIterative_Solver: public LinearSolver<T>{
public:
    NonIterative_Solver(int);
    virtual ~NonIterative_Solver() override;

    Vector<T> Forward_subst(const Matrix<T>& A, const Vector<T>& b);
    Vector<T> Backward_subst(const Matrix<T>& A, const Vector<T>& b);
    virtual void Decomposition() = 0;

protected:
    Matrix<T> L;
    Matrix<T> U;

};

#endif //LINEAR_SOLVERS_NONITERATIVE_SOLVER_H
#include <iostream>

using namespace std;

template <typename T> NonIterative_Solver<T>::NonIterative_Solver(int n):LinearSolver<T>() {
    L = Matrix<T>(n,n,0);
    U = Matrix<T>(n,n,0);
}

template <typename T> NonIterative_Solver<T>::~NonIterative_Solver() {}

template <typename T> Vector<T> NonIterative_Solver<T>::Backward_subst(const Matrix<T> &A, const Vector<T> &b) {
    int n = A.getCols(); //A is upper triangular
    Vector<T> x(n);

    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] = x[i] - A[i][j] * x[j];
        }
        if (fabs(A[i][i]) < 1e-10)
            throw runtime_error("Division by 0 in backward substitution."
                                "Matrix A doesn't fulfill requirements.");
        x[i] /= A[i][i];
    }
    return x;
}

template <typename T> Vector<T> NonIterative_Solver<T>::Forward_subst(const Matrix<T> &A, const Vector<T> &b) {
    int n = A.getCols(); //
    Vector<T> x(n);
    if (fabs(A[0][0]) < 1e-10)
        throw runtime_error("Division by 0 in forward substitution."
                            "Matrix A doesn't fulfill requirements.");
    x[0] = b[0] / A[0][0];
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            x[i] -= A[i][j]*x[j];
        }
        if (fabs(A[i][i]) < 1e-10)
            throw runtime_error("Division by 0 in forward substitution."
                                "Matrix A doesn't fulfill requirements.");
        x[i] = (x[i] + b[i]) / A[i][i];
    }

    return x;
}


