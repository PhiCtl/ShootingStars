//
// Created by petronio@INTRANET.EPFL.CH on 03.12.20.
//

#include "Gauss_Seidel.h"
#include <iostream>
#include <complex>

template <typename T>
Gauss_Seidel<T>::Gauss_Seidel(const Vector<T>& vec, int nb_iters, double tol) : Iterative_Solver<T>(vec, nb_iters, tol){};

template <typename T>
Gauss_Seidel<T>::Gauss_Seidel() : Iterative_Solver<T>(){};

template <typename T>
Gauss_Seidel<T>::~Gauss_Seidel(){};

template <typename T>
Gauss_Seidel<T>::Gauss_Seidel(const Gauss_Seidel<T>& solver){
    this-> initial_guess = solver.initial_guess;
    this-> nb_iter = solver.nb_iter;
    this-> tol = solver.tol;
}

template <typename T>
Vector<T> Gauss_Seidel<T>::Solve(const Matrix<T>& A, const Vector<T>& b) {
    try {
        T r0 = b.Norm();
        if (fabs(r0) <0)
            r0 = 1;
        if (this->initial_guess.getRows() <=1)
            this->initial_guess = Vector<T>(A.getCols());

        int n = A.getCols();
        Vector<T> x = this->initial_guess;
        Vector<T> y = Vector<T>(A.getCols());
        Vector<T> r = A*x - b;
        vector<T> res(1, r.Norm());
        size_t iter(0);

        while((fabs(res[res.size()-1] / r0) > this->tol) && (iter < this->nb_iter)){
            for(int i = 0; i < n; i ++){
                T sum = 0.0;
                y[i] = b(i) / A(i,i);
                for(int j = 0; j < n; j++){
                    if(j!=i){
                        sum += A(i,j) * x(j);
                    }
                }
                x[i] = y(i) - sum/A(i,i);
            }
            iter += 1;
            res.push_back(r.Norm());
        }
        return x;
    }catch(const runtime_error& e) {
    cout << e.what() << endl;
}

}


template class Gauss_Seidel<int>;
template class Gauss_Seidel<double>;
template class Gauss_Seidel<long double>;
template class Gauss_Seidel<long int>;
template class Gauss_Seidel<long long int>;
template class Gauss_Seidel<float>;
template class Gauss_Seidel<complex<double>>;
template class Gauss_Seidel<complex<long double>>;
template class Gauss_Seidel<complex<float>>;