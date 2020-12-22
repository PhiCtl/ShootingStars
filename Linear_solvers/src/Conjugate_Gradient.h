//
// Created by descourt@INTRANET.EPFL.CH on 02.12.20.
//

#ifndef LINEAR_SOLVERS_CONJUGATE_GRADIENT_H
#define LINEAR_SOLVERS_CONJUGATE_GRADIENT_H

#include "Iterative_Solver.h"

/*! @brief Conjugate gradient solver
 */
template <typename T>
class Conjugate_Gradient: public Iterative_Solver<T>
{
public:
    /*! @brief Constructor
     * @param init: initial conditions
     * @param iter: number of iterations
     * @param threshold: stopping criteria (if residual error is below this threshold)
     */
    Conjugate_Gradient(const Vector<T>& init, int iter, double threshold);

    /*! @brief Constructor (default)
     */
    Conjugate_Gradient();

    /*! @brief Destructor (default)
     */
    ~Conjugate_Gradient() override;

    /*! @brief Copy constructor
     * @param solver: another Conjugate gradient solver of same type
     */
    Conjugate_Gradient(const Conjugate_Gradient<T>& solver);

    /*! @brief Solve
     * @param A: Matrix of same type T as solver
     * @param b: Vector of same type T as solver
     * @return x: a Vector x such that Ax = b
     */
    Vector<T> Solve(const  Matrix<T>& A, const Vector<T>& b) override;

};


#endif //LINEAR_SOLVERS_CONJUGATE_GRADIENT_H
