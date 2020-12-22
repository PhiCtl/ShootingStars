//
// Created by petronio@INTRANET.EPFL.CH on 03.12.20.
//

#ifndef LINEAR_SOLVERS_JACOBI_H
#define LINEAR_SOLVERS_JACOBI_H

#include "Iterative_Solver.h"
/*! @brief Jacobi solver
 */
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
    /*! @brief Constructor
     * @param init: initial conditions
     * @param iter: number of iterations
     * @param threshold: stopping criteria (if residual error is below this threshold)
     */
    Jacobi(const Vector<T>&, int, double);

    /*! @brief Constructor (default)
     */
    Jacobi();

    /*! @brief Copy constructor
     * @param solver: another Jacobi solver of same type
     */
    Jacobi(const Jacobi<T>&);

    //Destructor
    /*! @brief Destructor (default)
     */
    ~Jacobi() override;

    //Linear algebra
    /*! @brief Solve
     * @param A: Matrix of same type T as solver
     * @param b: Vector of same type T as solver
     * @return x: a Vector x such that Ax = b
     */
    Vector<T> Solve(const Matrix<T>& A, const Vector<T>& b) override;


};


#endif //LINEAR_SOLVERS_JACOBI_H
