//
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
//

#ifndef LINEAR_SOLVERS_ITERATIVE_SOLVER_H
#define LINEAR_SOLVERS_ITERATIVE_SOLVER_H

#include "LinearSolver.h"

template <typename T> class Iterative_Solver : public LinearSolver<T>{
public:
    Iterative_Solver(const Vector<T>&, int, double);
    Iterative_Solver();
    virtual ~Iterative_Solver() override;
    void Set_parameters(const Vector<T>&, int, double);
    void Print_parameters();

protected:
    Vector<T> initial_guess;
    int nb_iter;
    double tol;
};

#endif //LINEAR_SOLVERS_ITERATIVE_SOLVER_H

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

template <typename T> void Iterative_Solver<T>::Set_parameters(const Vector<T> & x, int nb_it, double tol) {
    initial_guess = x;
    nb_iter = nb_it;
    tol = tol;
}

template <typename T> void Iterative_Solver<T>::Print_parameters() {
    cout << "Maximal number of iterations: " << nb_iter << endl;
    cout << "Tolerance: " << tol << endl;
    cout << "Initial guess: " << endl;
    initial_guess.Print(cout);
}

