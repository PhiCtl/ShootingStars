//
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
//

#ifndef LINEAR_SOLVERS_SOLVER_H
#define LINEAR_SOLVERS_SOLVER_H

#endif //LINEAR_SOLVERS_SOLVER_H

#include "Vector.cpp"

template <typename T> class LinearSolver{
public:
    LinearSolver() = default;
    virtual ~LinearSolver() = default;
    virtual Vector<T> Solve(const Matrix<T>&, const Vector<T>&) = 0;
};
