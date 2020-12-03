//
// Created by descourt@INTRANET.EPFL.CH on 02.12.20.
//

#ifndef LINEAR_SOLVERS_CHOLESKY_H
#define LINEAR_SOLVERS_CHOLESKY_H

#include "NonIterative_Solver.h"

template <typename T> class Cholesky: public NonIterative_Solver<T>{
public:

    //constructor etc...
    Cholesky();
    ~Cholesky() override;
    Cholesky(const Cholesky<T>&);

    //Linear algebra
    void Decomposition(const Matrix<T>&) override;
    Vector<T> Solve(const  Matrix<T>& A, const Vector<T>& b) override;

};

#endif //LINEAR_SOLVERS_CHOLESKY_H
