//
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
//

#ifndef LINEAR_SOLVERS_SOLVER_H
#define LINEAR_SOLVERS_SOLVER_H

#include "Vector.h"
/*! @brief LinearSolver: mother class for any linear solver
 *
 * @tparam T
 */
template <typename T> class LinearSolver{
public:

    /*! @brief Constructor
     *
     */
    LinearSolver() {};

    /*! @brief Destructor
     *
     */
    virtual ~LinearSolver() {};

    /*! @brief Solve (virtual and override in daughter classes)
     *
     * @param A : Matrix
     * @param b : Vector
     * @return x: Vector x such that Ax = b
     */
    virtual Vector<T> Solve(const Matrix<T>& A, const Vector<T>& b) {};
};

#endif //LINEAR_SOLVERS_SOLVER_H
