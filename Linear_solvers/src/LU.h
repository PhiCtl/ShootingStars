//
// Created by descourt@INTRANET.EPFL.CH on 02.12.20.
//

#ifndef LINEAR_SOLVERS_LU_H
#define LINEAR_SOLVERS_LU_H

#include "NonIterative_Solver.h"

template < typename T > class LU: public NonIterative_Solver<T>{
public:

    //constructor destructor copy constructor
    LU();
    ~LU() override;
    LU(const LU<T>&);

    void Decomposition(const Matrix<T>&) override;
    Vector<T> Solve(const  Matrix<T>& A, const Vector<T>& b) override;
};


#endif //LINEAR_SOLVERS_LU_H
