//
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
//
#ifndef LINEAR_SOLVERS_CHOLESKY_H
#define LINEAR_SOLVERS_CHOLESKY_H

#include "NonIterative_Solver.cpp"

template <typename T> class Cholesky: public NonIterative_Solver<T>{
public:
    Cholesky(int);
    ~Cholesky() override;

    void Decomposition(const Matrix<T>&) override;
    Vector<T> Solve(const  Matrix<T>& A, const Vector<T>& b) override;

};

#endif //LINEAR_SOLVERS_CHOLESKY_H

#include <iostream>
using namespace std;

template <typename T> Cholesky<T>::Cholesky(int n):NonIterative_Solver<T>(n) {};
template <typename T> Cholesky<T>::~Cholesky<T>() {};

template <typename T> void Cholesky<T>::Decomposition(const Matrix<T>& A) {
    int n = A.getCols();
    this->L = Matrix<T>(n,n,0.0);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            auto sum(0.0);
            if (i == j)
            {
                for (int k = 0; k < j; ++k)
                    sum += (this->L[j][k] * this->L[j][k]);
                /*if(A[j][j] - sum < 0 )
                    L[j][j] = ComplexNumber(0.0, A[j][j] - sum);*/
                this->L[j][j] = sqrt(A[j][j] - sum);
            }
            else{
                for(int k = 0; k < j; ++k)
                    sum += this->L[i][k] * this->L[j][k];
                if(fabs(this->L[j][j]) < 1e-10)
                    throw runtime_error("Division by 0 in Cholesky decomposition. "
                                        "Matrix A doesn't fulfill requirements.");
                this->L[i][j] = 1/this->L[j][j]*(A[i][j] - sum);
            }
        }
    }

    this->U = this->L.Transpose();
}

template <typename T> Vector<T> Cholesky<T>::Solve(const Matrix<T> &A, const Vector<T> &b) {
    try {
            Decomposition(A);
            Vector<T> y = this->Forward_subst(this->L,b);
            Vector<T> x = this->Backward_subst(this->U, y);
            return x;
    }
    catch(const runtime_error& e)
    {
        throw e;
    }

}