 //
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
//

#include "Cholesky.h"

#include <complex>
#include <iostream>
using namespace std;

//constructor destructor
template <typename T> Cholesky<T>::Cholesky():NonIterative_Solver<T>() {};
template <typename T> Cholesky<T>::~Cholesky<T>() {};
template <typename T> Cholesky<T>::Cholesky(const Cholesky<T>& solver) {
    this->L = solver.L;
    this->U = solver.U;
}

template <typename T> void Cholesky<T>::Decomposition(const Matrix<T>& A) {
    int n = A.getCols();
    this->L = Matrix<T>(n,n,0.0);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            T sum(0.0);
            if (i == j)
            {
                for (int k = 0; k < j; ++k)
                    sum += this->L(j,k) * conjug(this->L(j,k));
                this->L[j][j] = sqrt(A(j,j) - sum);

            }
            else{
                for(int k = 0; k < j; ++k)
                    sum += this->L(i,k) * conjug(this->L(j,k));
                if(fabs(this->L(j,j)) < 1e-10)
                    throw runtime_error("Division by 0 in Cholesky decomposition. "
                                        "Matrix A doesn't fulfill requirements.");
                this->L[i][j] = (A(i,j) - sum)/(this->L(j,j));
            }
        }
    }

    this->U = this->L.transpose();
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

template class Cholesky<int>;
template class Cholesky<double>;
template class Cholesky<long double>;
template class Cholesky<long int>;
template class Cholesky<long long int>;
template class Cholesky<float>;
template class Cholesky<complex<double>>;
template class Cholesky<complex<long double>>;
template class Cholesky<complex<float>>;