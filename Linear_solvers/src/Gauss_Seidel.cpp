//
// Created by petronio@INTRANET.EPFL.CH on 03.12.20.
//

#include "Gauss_Seidel.h"
#include <iostream>
#include <complex>

template <typename T>
Gauss_Seidel<T>::Gauss_Seidel(const Vector<T>& vec, int nb_iters, double tol) : Iterative_Solver<T>(vec, nb_iters, tol){};

template <typename T>
Gauss_Seidel<T>::Gauss_Seidel() : Iterative_Solver<T>(){};

template <typename T>
Gauss_Seidel<T>::~Gauss_Seidel(){};

template <typename T>
Gauss_Seidel<T>::Gauss_Seidel(const Gauss_Seidel<T>& solver){
    this-> initial_guess = solver.initial_guess;
    this-> nb_iter = solver.nb_iter;
    this-> tol = solver.tol;
}

template <typename T>
Vector<T> Gauss_Seidel<T>::Solve(const Matrix<T>& A, const Vector<T>& b) {

}