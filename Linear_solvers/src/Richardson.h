//
// Created by petronio@INTRANET.EPFL.CH on 03.12.20.
//

#ifndef LINEAR_SOLVERS_RICHARDSON_H
#define LINEAR_SOLVERS_RICHARDSON_H

#include "Iterative_Solver.h"
/*! @brief Richardson solver
 */
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

    /*! @brief Constructor
     * @param init: initial conditions
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

    //Destructor
    /*! @brief Destructor (default)
     */
    ~Richardson() override;

    //Linear algebra
    /*! @brief Solve
     * @param A: Matrix of same type T as solver
     * @param b: Vector of same type T as solver
     * @return x: a Vector x such that Ax = b
     */
    Vector<T> Solve(const Matrix<T>& A, const Vector<T>& b) override;


};


#endif //LINEAR_SOLVERS_JACOBI_H
