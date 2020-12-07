//
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
//


#include "LU.h"
#include <iostream>
#include <complex>
using namespace std;

//constructor destructor etc..

template <typename T> LU<T>::LU():NonIterative_Solver<T>() {}
template <typename T> LU<T>::~LU<T>() {}
template <typename T> LU<T>::LU(const LU<T>& solver) {
    this->L = solver.L;
    this->U = solver.U;
}

//linear algebra

template <typename T> void LU<T>::Decomposition(const Matrix<T>& A) {
    int n = A.getCols();
    this->L = Matrix<T>(Identity<T>(n));
    this->U = Matrix<T>(n,n);
    for(int i = 0; i < n; ++i)
    {
        for(int k = i; k < n; ++k)
        {
            T tot = 0.0;
            for(int j = 0; j < i; ++j)
            {
                tot += (this->L(i,j) * this->U(j,k));
            }
            this->U[i][k] = A(i,k) - tot;
        }

        for(int k = i; k < n; ++k)
        {
            T tot =  0.0;
            for(int j = 0; j < i; ++j)
            {
                tot += (this->L(k,j) * this->U(j,i));
            }
            if(fabs(this->U(i,i)) < 1e-10)
                throw runtime_error("Division by 0 in LU decomposition."
                                    "Matrix A doesn't fulfill requirements");
            this->L[k][i] = (A(k,i) - tot) / (this->U(i,i));
        }
    }
}

template <typename T> Vector<T> LU<T>::Solve(const Matrix<T> &A, const Vector<T> &b) {
    try {
        this->Decomposition(A);
        Vector<T> y = this->Forward_subst(this->L,b);
        y.Print(cout);
        Vector<T> sol = this->Backward_subst(this->U,y);
        return sol;
    }
    catch(const runtime_error& e)
    {
        throw e;
    }
}

template class LU<int>;
template class LU<double>;
template class LU<long int>;
template class LU<long long int>;
template class LU<float>;
template class LU<complex<double>>;
template class LU<complex<float>>;


