//
// Created by petronio@INTRANET.EPFL.CH on 03.12.20.
//

#ifndef LINEAR_SOLVERS_RICHARDSON_H
#define LINEAR_SOLVERS_RICHARDSON_H

#include "Iterative_Solver.h"

/*! @brief
 * Richardson solver class: daughter class of Iterative Solver.
 * Generalization of the iterative method, reading:
 * given the initial guess x0, solve P*z^(k) = r^(k) and set x^(k+1) = x^(k) + alpha_k * z^(k) for a nonsingular preconditioning matrix P
 * @tparam T
 */

template <typename T>
class Richardson : public Iterative_Solver<T>{
public:

    /*! @brief Constructor
     * @param init: initial condition
     * @param iter: number of iterations
     * @param threshold: stopping criteria (if residual error is below this threshold)
     */
    Richardson(const Vector<T>&, int, double);

    /*! @brief Constructor (default)
     */
    Richardson();

    /*! @brief Copy constructor
     * @param solver: another Richardson solver of same type
     */
    Richardson(const Richardson<T>&);


    /*! @brief Destructor (default)
     */
    ~Richardson() override;


    /*! @brief Solve
     * @param A: Matrix of same type T as solver
     * @param b: Vector of same type T as solver
     * @return x: a Vector x such that Ax = b
     */
    Vector<T> Solve(const Matrix<T>& A, const Vector<T>& b) override;


};


#endif //LINEAR_SOLVERS_JACOBI_H
