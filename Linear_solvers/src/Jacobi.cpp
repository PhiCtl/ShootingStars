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
        if (this->initial_guess.getRows() <=1)
            this->initial_guess = Vector<T>(A.getCols());

        int n = A.getCols(); //A must be a square matrix
        Vector<T> x = this->initial_guess;
        Vector<T> r = A*x - b;
        T res = r.Norm();
        size_t iter(0);

        while((res > this->tol) && (iter < this->nb_iter)){
            for(int i = 0; i < n; i++){
                auto sum = 0; //is it correct auto?
                for(int j = 0; j < n; j++){
                    if(j != i){
                        sum += A(i,j) + x(j);
                    }
                }
                x[i] = 1/A(i,i) * (b(i) - sum);
            }
            iter += 1;
        }

    }catch(const runtime_error& e) {
    cout << e.what() << endl;
 }
}


