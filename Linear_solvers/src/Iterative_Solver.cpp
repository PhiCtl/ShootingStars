//
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
//

#include "Iterative_Solver.h"
#include <complex>

//constructors destructor
template <typename T> Iterative_Solver<T>::Iterative_Solver(const Vector<T>& Vec, int nb, double thresh):LinearSolver<T>() {
    initial_guess = Vec;
    nb_iter = nb;
    tol = thresh;
}

template <typename T> Iterative_Solver<T>::Iterative_Solver() {
    nb_iter = 100;
    tol = 1e-10;
}
template <typename T> Iterative_Solver<T>::~Iterative_Solver<T>() {};

//copy constructor
template <typename T> Iterative_Solver<T>::Iterative_Solver(const Iterative_Solver<T>& solver) {
    this->initial_guess = solver.initial_guess;
    this->nb_iter = solver.nb_iter;
    this->tol = solver.tol;
}

//getters setters
template <typename T>
void Iterative_Solver<T>::Set_parameters_vec(const Vector<T> & x){
    initial_guess = x;
}

template <typename T>
void Iterative_Solver<T>::Set_parameters_it(int nb_it){
    nb_iter = nb_it;
}

template <typename T>
void Iterative_Solver<T>::Set_parameters_tol(double tol){
    tol = tol;
}

template <typename T> void Iterative_Solver<T>::Print_parameters() {
    cout << "Maximal number of iterations: " << nb_iter << endl;
    cout << "Tolerance: " << tol << endl;
    cout << "Initial guess: " << endl;
    initial_guess.Print(cout);
}

template class Iterative_Solver<int>;
template class Iterative_Solver<double>;
template class Iterative_Solver<long int>;
template class Iterative_Solver<long long int>;
template class Iterative_Solver<float>;
template class Iterative_Solver<complex<double>>;
template class Iterative_Solver<complex<float>>;

