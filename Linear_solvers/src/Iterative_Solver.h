//
// Created by descourt@INTRANET.EPFL.CH on 02.12.20.
//

#ifndef LINEAR_SOLVERS_ITERATIVE_SOLVER_H
#define LINEAR_SOLVERS_ITERATIVE_SOLVER_H

#include "LinearSolver.h"

template <typename T> class Iterative_Solver : public LinearSolver<T>{
public:

    //constructors destructors
    Iterative_Solver(const Vector<T>&, int, double);
    Iterative_Solver();
    virtual ~Iterative_Solver() override;

    //copy constructor
    Iterative_Solver(const Iterative_Solver<T>&);

    //setters and getters
    void Set_parameters(const Vector<T>&, int, double);
    void Print_parameters();

protected:
    Vector<T> initial_guess;
    int nb_iter;
    double tol;
};

#endif //LINEAR_SOLVERS_ITERATIVE_SOLVER_H
