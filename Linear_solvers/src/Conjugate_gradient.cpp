//
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
//

#ifndef LINEAR_SOLVERS_CONJUGATE_GRADIENT_H
#define LINEAR_SOLVERS_CONJUGATE_GRADIENT_H
#include "Iterative_Solver.cpp"
#include <iostream>

template <typename T> class Conjugate_Gradient: public Iterative_Solver<T>
{
public:
    Conjugate_Gradient(const Vector<T>&, int, double);
    ~Conjugate_Gradient() override;

    Vector<T> Solve(const  Matrix<T>& A, const Vector<T>& b) override;

};

#endif //LINEAR_SOLVERS_CONJUGATE_GRADIENT_H

template <typename T> Conjugate_Gradient<T>::Conjugate_Gradient(const Vector<T>& vec, int nb_iters, double tol):Iterative_Solver<T>(vec, nb_iters, tol) {};
template <typename T> Conjugate_Gradient<T>::~Conjugate_Gradient<T>() {};

template <typename T> Vector<T> Conjugate_Gradient<T>::Solve(const Matrix<T> &A, const Vector<T> &b)
{
    try {
        auto r0 = b.Norm(); //te be redefined
        if (r0 == 0)
            r0 = 1;
        if (this->initial_guess.getRows() < 1)
            this->initial_guess = Vector<T>(A.getCols());

        Vector<T> x = this->initial_guess;
        Vector<T> r = b - A * x;
        Vector<T> p = r;
        Vector<T> res(1, r.Norm());
        size_t iter(0);

        while ((res[res.size()] / r0 > this->tol) && (iter < this->nb_iter)) {
            Vector<T> w = A * p;
            auto alpha = (p.transpose() * r) / (p.transpose() * w);
            x = x + p * alpha;
            r = r - w * alpha;

            auto beta = (w.transpose() * r) / (w.transpose() * p);
            p = r - p * beta;

            iter += 1;
            res.Push_back(r.Norm());
        }

    } catch(const runtime_error& e)
    {
       cout << e.what() << endl;
    }

}