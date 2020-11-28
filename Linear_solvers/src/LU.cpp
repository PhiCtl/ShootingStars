//
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
//

#ifndef LINEAR_SOLVERS_LU_H
#define LINEAR_SOLVERS_LU_H

#include "NonIterative_Solver.cpp"

template < typename T > class LU: public NonIterative_Solver<T>{
public:
    LU(int);
    ~LU() override;

    void Decomposition(const Matrix<T>&) override;
    Vector<T> Solve(const  Matrix<T>& A, const Vector<T>& b) override;
};

#endif //LINEAR_SOLVERS_LU_H

#include <iostream>
using namespace std;

template <typename T> LU<T>::LU(int n):NonIterative_Solver<T>(n) {}
template <typename T> LU<T>::~LU<T>() {}

template <typename T> void LU<T>::Decomposition(const Matrix<T>& A) {
    int n = A.getCols();
    this->L = Identity(n);
    for(int i = 0; i < n; ++i)
    {
        for(int k = i; k < n; ++k)
        {
            auto tot = 0.0;
            for(int j = 0; j < i; ++j)
            {
                tot += (this->L[i][j] * this->U[j][k]);
            }
            this->U[i][k] = A[i][k] - tot;
        }

        for(int k = i; k < n; ++k)
        {
            auto tot =  0.0;
            for(int j = 0; j < i; ++j)
            {
                tot += (this->L[k][j] * this->U[j][i]);
            }
            if(fabs(this->U[i][i]) < 1e-10)
                throw runtime_error("Division by 0 in LU decomposition."
                                    "Matrix A doesn't fulfill requirements");
            this->L[k][i] = (A[k][i] - tot) / (this->U[i][i]);
        }
    }
}

template <typename T> Vector<T> LU<T>::Solve(const Matrix<T> &A, const Vector<T> &b) {
    try {
        LU_decomposition(A,this->L,this->U);
        Vector<T> y = forward_subst(this->L,b);
        Print(y);
        Vector<T> sol = backward_subst(this->U,y);
        return sol;
    }
    catch(const runtime_error& e)
    {
        throw e;
    }
}


