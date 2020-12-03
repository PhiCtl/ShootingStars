//
// Created by descourt@INTRANET.EPFL.CH on 02.12.20.
//

#ifndef LINEAR_SOLVERS_NONITERATIVE_SOLVER_H
#define LINEAR_SOLVERS_NONITERATIVE_SOLVER_H

#include "LinearSolver.h"
template <typename T> class NonIterative_Solver: public LinearSolver<T>{
public:
    //constructor and destructor
    NonIterative_Solver();
    virtual ~NonIterative_Solver() override;
    NonIterative_Solver(const NonIterative_Solver<T>&);

    //Linear algebra methods
    Vector<T> Forward_subst(const Matrix<T>& A, const Vector<T>& b);
    Vector<T> Backward_subst(const Matrix<T>& A, const Vector<T>& b);
    virtual void Decomposition(const Matrix<T>&) = 0;

    //getters
    Matrix<T> getL();
    Matrix<T> getU();

protected:
    //decomposition matrices
    Matrix<T> L;
    Matrix<T> U;

};

#endif //LINEAR_SOLVERS_NONITERATIVE_SOLVER_H
