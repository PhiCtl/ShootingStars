//
// Created by descourt@INTRANET.EPFL.CH on 02.12.20.
//

#ifndef LINEAR_SOLVERS_CONJUGATE_GRADIENT_H
#define LINEAR_SOLVERS_CONJUGATE_GRADIENT_H

#include "Iterative_Solver.h"

template <typename T>
class Conjugate_Gradient: public Iterative_Solver<T>
{
public:
    //constructor destructor
    Conjugate_Gradient(const Vector<T>&, int, double);
    Conjugate_Gradient();
    ~Conjugate_Gradient() override;

    //copy constructor
    Conjugate_Gradient(const Conjugate_Gradient<T>&);

    //Linear algebra
    Vector<T> Solve(const  Matrix<T>& A, const Vector<T>& b) override;

};


#endif //LINEAR_SOLVERS_CONJUGATE_GRADIENT_H
