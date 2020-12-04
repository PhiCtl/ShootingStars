//
// Created by petronio@INTRANET.EPFL.CH on 03.12.20.
//

#include "Jacobi.h"
#include <iostream>
#include <complex>

template <typename T>
Jacobi<T>::Jacobi(const Vector<T>& vec, int nb_iters, double tol) : Iterative_Solver<T>(vec, nb_iters, tol){};

template <typename T>
Jacobi<T>::Jacobi() : Iterative_Solver<T>(){};

template <typename T>
Jacobi<T>::~Jacobi(){};

template <typename T>
Jacobi<T>::Jacobi(const Jacobi<T>& solver){
    this-> initial_guess = solver.initial_guess;
    this-> nb_iter = solver.nb_iter;
    this-> tol = solver.tol;
}

template <typename T>
Vector<T> Jacobi<T>::Solve(const Matrix<T>& A, const Vector<T>& b) {
    try {
        T r0 = b.Norm();
        if (fabs(r0) <0)
            r0 = 1;
        if (this->initial_guess.getRows() <=1)
            this->initial_guess = Vector<T>(A.getCols());

        int n = A.getCols(); //A must be a square matrix
        Vector<T> x = this->initial_guess;
        Vector<T> r = A*x - b;
        Vector<T> res(1, r.Norm()); //vector with column of size 1 and r.norm element
        size_t iter(0);

        while((fabs(res[res.getRows()-1] / r0) > this->tol) && (iter < this->nb_iter)){

            for(int i = 0; i < n; i++){
                x[i] = b(i);
                for(int j = 0; j < n; j++){
                    if(j != i){
                        x[i] = x(i) - A(i,j) * x(j);
                    }
                }
                x[i] = x(i) / A(i,i);
            }
            iter += 1;
        }
        return x;
    }catch(const runtime_error& e) {
    cout << e.what() << endl;
 }
}

//make compiler happy
template class Jacobi<int>;
template class Jacobi<double>;
template class Jacobi<long int>;
template class Jacobi<long long int>;
template class Jacobi<float>;
template class Jacobi<complex<double>>;
template class Jacobi<complex<float>>;