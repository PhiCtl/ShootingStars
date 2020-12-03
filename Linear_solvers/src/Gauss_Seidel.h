//
// Created by petronio@INTRANET.EPFL.CH on 03.12.20.
//

#ifndef LINEAR_SOLVERS_GAUSS_SEIDEL_H
#define LINEAR_SOLVERS_GAUSS_SEIDEL_H
#include "Iterative_Solver.h"

template <typename T>
class Gauss_Seidel : public Iterative_Solver<T>{
public:
    /*
     * Constructors:
     * three paramenters: initial guess vector, number of iterations, tolerance
     * default
     * copy constructor
     *
    */

    Gauss_Seidel(const Vector<T>&, int, double);
    Gauss_Seidel();
    Gauss_Seidel(const Gauss_Seidel<T>&);

    //Destructor
    ~Gauss_Seidel() override;

    //Linear algebra
    Vector<T> Solve(const Matrix<T>& A, const Vector<T>& b) override;


};

#endif //LINEAR_SOLVERS_GAUSS_SEIDEL_H
