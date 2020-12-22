//
// Created by descourt@INTRANET.EPFL.CH on 02.12.20.
//

#ifndef LINEAR_SOLVERS_CHOLESKY_H
#define LINEAR_SOLVERS_CHOLESKY_H

#include "NonIterative_Solver.h"

/** @brief
 * Cholesky solver class
 * Solves linear systems for which the matrix is Hermitian
 * positive semi-definite, and computes the Cholesky decomposition
 * @tparam T
 */

template <typename T> class Cholesky: public NonIterative_Solver<T>{
public:

    /*! @brief Constructor */
    Cholesky();
    /*! @brief Destructor */
    ~Cholesky() override;
    /*! @brief Copy Constructor*/
    Cholesky(const Cholesky<T>&);

    /*! @brief  Decomposition
     * @param Matrix : positive semidefinite square Matrix
     * @return lower triangular matrix and its transposed
     */
    void Decomposition(const Matrix<T>&) override;

    /*! @brief Solver
     * @param A: positive semidefinite square matrix
     * @param b: vector of same dimensions
     * @return x such that A*x = b
     */
    Vector<T> Solve(const  Matrix<T>& A, const Vector<T>& b) override;

};

#endif //LINEAR_SOLVERS_CHOLESKY_H
