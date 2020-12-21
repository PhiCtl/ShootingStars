//
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
//

#ifndef LINEAR_SOLVERS_SOLVER_H
#define LINEAR_SOLVERS_SOLVER_H

#endif //LINEAR_SOLVERS_SOLVER_H

#include "Vector.h"

template <typename T> class LinearSolver{
public:
    LinearSolver() {};
    virtual ~LinearSolver() {};
    virtual Vector<T> Solve(const Matrix<T>&, const Vector<T>&) {};
};
