//
// Created by petronio@INTRANET.EPFL.CH on 03.12.20.
//

#ifndef LINEAR_SOLVERS_RICHARDSON_H
#define LINEAR_SOLVERS_RICHARDSON_H

#include "Iterative_Solver.h"

template <typename T>
class Richardson : public Iterative_Solver<T>{
public:
    /*
     * Constructors:
     * three parameters: initial guess vector, number of iterations, tolerance
     * default
     * copy constructor
     *
    */

    Richardson(const Vector<T>&, int, double);
    Richardson();
    Richardson(const Richardson<T>&);

    //Destructor
    ~Richardson() override;

    //Linear algebra
    Vector<T> Solve(const Matrix<T>& A, const Vector<T>& b) override;


};


#endif //LINEAR_SOLVERS_JACOBI_H
