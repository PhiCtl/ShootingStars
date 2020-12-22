//
// Created by descourt@INTRANET.EPFL.CH on 02.12.20.
//

#ifndef LINEAR_SOLVERS_ITERATIVE_SOLVER_H
#define LINEAR_SOLVERS_ITERATIVE_SOLVER_H

#include "LinearSolver.h"

/*! @brief Iterative_Solver class: generic class for any iterative solver
 *
 * @tparam T
 */
template <typename T> class Iterative_Solver : public LinearSolver<T>{
public:

    /*! @brief Constructor
     *
     * @param init: Vector initial solution
     * @param iter: int max number of iterations
     * @param thres: double threshold for stopping criterion
     */
    Iterative_Solver(const Vector<T>& init, int iter, double thres);

    /*! @brief Constructor (default)
     *
     */
    Iterative_Solver();

    /*! @brief destructor
     *
     */
    virtual ~Iterative_Solver() override;

    /*! @brief Copy constructor
     *
     * @param solver : another Iterative_Solver of same type T
     */
    Iterative_Solver(const Iterative_Solver<T>& solver);

    /*! @brief Set_parameters_vec: set initial conditions
     *
     * @param vec: Vector initial condition
     */
    void Set_parameters_vec(const Vector<T>& vec);

    /*! @brief Set_parameters_it: set iteration max number
     * @param it: number of max iterations
     */
    void Set_parameters_it(int it);

    /*! @brief Set_parameters_tol: set threshol
     *
     * @param thres: double threshold for stopping criterion
     */
    void Set_parameters_tol(double thres);

    /*! @brief Print_parameters: print the set parameters
     *
     */
    void Print_parameters();

protected:
    /** @brief initial_guess: store initial conditions */
    Vector<T> initial_guess;
    /** @brief nb_iter: maximum number of iterations */
    int nb_iter;
    /** @brief tol: stopping criterion */
    double tol;
};

#endif //LINEAR_SOLVERS_ITERATIVE_SOLVER_H
