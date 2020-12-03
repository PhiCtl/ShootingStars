//
// Created by petronio@INTRANET.EPFL.CH on 03.12.20.
//

#ifndef LINEAR_SOLVERS_JACOBI_H
#define LINEAR_SOLVERS_JACOBI_H

#include "Iterative_Solver.h"

template <typename T>
class Jacobi : public Iterative_Solver<T>{
public:
    /*
     * Constructors:
     * three paramenters: initial guess vector, number of iterations, tolerance
     * default
     * copy constructor
     *
    */

    Jacobi(const Vector<T>&, int, double);
    Jacobi();
    Jacobi(const Jacobi<T>&);

    //Destructor
    ~Jacobi() override;

    //Linear algebra
    Vector<T> Solve(const Matrix<T>& A, const Vector<T>& b) override;


};


#endif //LINEAR_SOLVERS_JACOBI_H
