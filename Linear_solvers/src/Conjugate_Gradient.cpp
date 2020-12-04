//
// Created by descourt@INTRANET.EPFL.CH on 27.11.20.
//

#include "Conjugate_Gradient.h"
#include <iostream>
#include <complex>

//constructors destructor copy constructor
template <typename T> Conjugate_Gradient<T>::Conjugate_Gradient(const Vector<T>& vec, int nb_iters, double tol):Iterative_Solver<T>(vec, nb_iters, tol) {};
template <typename T> Conjugate_Gradient<T>::Conjugate_Gradient():Iterative_Solver<T>() {};
template <typename T> Conjugate_Gradient<T>::~Conjugate_Gradient<T>() {};
template <typename T> Conjugate_Gradient<T>::Conjugate_Gradient(const Conjugate_Gradient<T>& solver) {
    this->initial_guess = solver.initial_guess;
    this->tol = solver.tol;
    this->nb_iter = solver.nb_iter;
}

//Linear algebra
template <typename T> Vector<T> Conjugate_Gradient<T>::Solve(const Matrix<T> &A, const Vector<T> &b)
{
    try {
        T r0 = b.Norm();
        if (fabs(r0) <0)
            r0 = 1;
        if (this->initial_guess.getRows() <=1)
            this->initial_guess = Vector<T>(A.getCols());

        Vector<T> x = this->initial_guess;
        Vector<T> r = b - A * x;
        Vector<T> p = r;
        vector<T> res(1, r.Norm());
        size_t iter(0);

        while (( fabs(res[res.size()-1] / r0) > this->tol) && (iter < this->nb_iter)) {
            Vector<T> w = A * p;
            T alpha = (p * r) / (p * w);
            x = x + p * alpha;
            r = r - w * alpha;

            T beta = (w * r) / (w * p);
            p = r - p * beta;

            iter += 1;
            res.push_back(r.Norm());
        }
        return x;

    } catch(const runtime_error& e)
    {
       cout << e.what() << endl;
    }

}

//make compiler happy
template class Conjugate_Gradient<int>;
template class Conjugate_Gradient<double>;
template class Conjugate_Gradient<long int>;
template class Conjugate_Gradient<long long int>;
template class Conjugate_Gradient<float>;
template class Conjugate_Gradient<complex<double>>;
template class Conjugate_Gradient<complex<float>>;