
#ifndef LINEAR_SOLVERS_LU_H
#define LINEAR_SOLVERS_LU_H

#include "NonIterative_Solver.h"

/*! @brief LU class : LU-decomposition based solver
 *
 * @tparam T
 */
template < typename T > class LU: public NonIterative_Solver<T>{
public:

    /*! @brief Constructor
     *
     */
    LU();
    /*! @brief Destructor
     *
     */
    ~LU() override;
    /*! @brief Copy Constructor
     *
     * @param solver: another LU solver of same type T
     */
    LU(const LU<T>& solver);

    /*! @brief Decomposition: compute LU decomposition
     * @param A: Matrix from which we will derive the LU decomposition
     */
    void Decomposition(const Matrix<T>& A) override;

    /*! @brief Solve (override)
     * @param A : Matrix
     * @param b : Vector
     * @return x: Vector such that Ax = b
     */
    Vector<T> Solve(const  Matrix<T>& A, const Vector<T>& b) override;
};


#endif //LINEAR_SOLVERS_LU_H
