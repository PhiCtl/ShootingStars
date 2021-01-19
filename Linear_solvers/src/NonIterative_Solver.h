#ifndef LINEAR_SOLVERS_NONITERATIVE_SOLVER_H
#define LINEAR_SOLVERS_NONITERATIVE_SOLVER_H

#include "LinearSolver.h"

/*! @brief NonIterative_Solver: generic class for non iterative solvers
 *
 * @tparam T
 */
template <typename T> class NonIterative_Solver: public LinearSolver<T>{
public:
    /*! @brief Constructor
     *
     */
    NonIterative_Solver();

    /*! @brief Destructor
     *
     */
    virtual ~NonIterative_Solver() override;

    /*! @brief Copy constructor
     *
     * @param solver: NonIterative_Solver of same type T
     */
    NonIterative_Solver(const NonIterative_Solver<T>& solver);

    /*! @brief Forward_subst: compute forward substitution
     *
     * @param A : lower triangular Matrix
     * @param b : Vector
     * @return x: Vector x such that Ax = b
     */
    Vector<T> Forward_subst(const Matrix<T>& A, const Vector<T>& b);

    /*! @brief Backward_subst: compute backward substitution
     *
     * @param A: upper triangular Matrix
     * @param b : Vector
     * @return x: Vector x such that Ax = b
     */
    Vector<T> Backward_subst(const Matrix<T>& A, const Vector<T>& b);

    /*! @brief Decomposition (pure abstract)
     *
     * @param A : Matrix from which we compute the decomposition
     * lower and upper triangular matrices
     */
    virtual void Decomposition(const Matrix<T>& A) = 0;

    //getters
    /*! @brief getL
     * @return L: lower triangular Matrix
     */
    Matrix<T> getL();

    /*! @brief getU
     *
     * @return U: upper triangular Matrix
     */
    Matrix<T> getU();

protected:
    /** @brief lower triangular Matrix from LU decomposition*/
    Matrix<T> L;
    /** @brief upper triangular Matrix from LU decomposition */
    Matrix<T> U;

};

#endif //LINEAR_SOLVERS_NONITERATIVE_SOLVER_H
