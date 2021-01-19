//
// Created by petronio@INTRANET.EPFL.CH on 03.12.20.
//

#ifndef LINEAR_SOLVERS_GAUSS_SEIDEL_H
#define LINEAR_SOLVERS_GAUSS_SEIDEL_H
#include "Iterative_Solver.h"

/*! @brief Gauss Seidel solver: daughter class of Iterative Solver.
 * The iterative Gauss Seidel method can be used for a nonsingular matrix A with nonzero diagonal entries. It consists in setting the preconditioning matrix P
 * as the lower triangular matrix extracted from A.
 * @tparam T
 */

template <typename T>
class Gauss_Seidel : public Iterative_Solver<T>{
public:
    /*! @brief Constructor
     * @param init: initial condition
     * @param iter: number of iterations
     * @param threshold: stopping criteria (if residual error is below this threshold)
     */
    Gauss_Seidel(const Vector<T>&, int, double);

    /*! @brief Constructor (default)
     */
    Gauss_Seidel();

    /*! @brief Copy constructor
     * @param solver: another Gauss Seidel solver of same type
     */
    Gauss_Seidel(const Gauss_Seidel<T>&);

    /*! @brief Destructor (default)
    */
    ~Gauss_Seidel() override;

    /*! @brief Solve
    * @param A: Matrix of same type T as solver
    * @param b: Vector of same type T as solver
    * @return x: a Vector x such that Ax = b
    */
    Vector<T> Solve(const Matrix<T>& A, const Vector<T>& b) override;


};

#endif //LINEAR_SOLVERS_GAUSS_SEIDEL_H
