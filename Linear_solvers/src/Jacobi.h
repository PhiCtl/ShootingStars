//
// Created by petronio@INTRANET.EPFL.CH on 03.12.20.
//

#ifndef LINEAR_SOLVERS_JACOBI_H
#define LINEAR_SOLVERS_JACOBI_H

#include "Iterative_Solver.h"

/*! @brief Jacobi solver: daughter class of Iterative Solver
 * The iterative Jacobi method can be used for a nonsingular matrix A with nonzero diagonal entries. It consists in setting the preconditioning matrix P
 * as the diagonal matrix extracted from A.
 * @tparam T
 */

template <typename T>
class Jacobi : public Iterative_Solver<T>{
public:

    /*! @brief Constructor
     * @param init: initial condition
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


    /*! @brief Destructor (default)
     */
    ~Jacobi() override;


    /*! @brief Solve
     * @param A: Matrix of same type T as solver
     * @param b: Vector of same type T as solver
     * @return x: a Vector x such that Ax = b
     */
    Vector<T> Solve(const Matrix<T>& A, const Vector<T>& b) override;


};


#endif //LINEAR_SOLVERS_JACOBI_H
