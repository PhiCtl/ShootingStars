//
// Created by petronio@INTRANET.EPFL.CH on 03.12.20.
//

#include "Richardson.h"
#include <iostream>
#include <complex>

template <typename T>
Richardson<T>::Richardson(const Vector<T>& vec, int nb_iters, double tol) : Iterative_Solver<T>(vec, nb_iters, tol){};

template <typename T>
Richardson<T>::Richardson() : Iterative_Solver<T>(){};

template <typename T>
Richardson<T>::~Richardson(){};

template <typename T>
Richardson<T>::Richardson(const Richardson<T>& solver){
    this-> initial_guess = solver.initial_guess;
    this-> nb_iter = solver.nb_iter;
    this-> tol = solver.tol;
}

template <typename T>
Vector<T> Richardson<T>::Solve(const Matrix<T>& A, const Vector<T>& b) {}

//make compiler happy
template class Gauss_Seidel<int>;
template class Gauss_Seidel<double>;
template class Gauss_Seidel<long int>;
template class Gauss_Seidel<long long int>;
template class Gauss_Seidel<float>;
template class Gauss_Seidel<complex<double>>;
template class Gauss_Seidel<complex<float>>;