//
// Created by petronio@INTRANET.EPFL.CH on 03.12.20.
//

#include "Richardson.h"
#include <iostream>
#include <complex>

template <typename T>
Richardson<T>::Richardson(const Vector<T>& vec, int nb_iters, double tol) : Iterative_Solver<T>(vec, nb_iters, tol){};

template <typename T>
Richardson<T>::Richardson() : Iterative_Solver<T>(){};

template <typename T>
Richardson<T>::~Richardson(){};

template <typename T>
Richardson<T>::Richardson(const Richardson<T>& solver){
    this-> initial_guess = solver.initial_guess;
    this-> nb_iter = solver.nb_iter;
    this-> tol = solver.tol;
}

template <typename T>
Vector<T> Richardson<T>::Solve(const Matrix<T>& A, const Vector<T>& b) {
    try {
        T r0 = b.Norm();
        if (fabs(r0) <0)
            r0 = 1;
        if (this->initial_guess.getRows() <=1)
            this->initial_guess = Vector<T>(A.getCols());

        Vector<T> x = this->initial_guess;
        Vector<T> r = b - A * x;
        Matrix<T> P = Identity<T>(A.getCols());
        vector<T> res(1, r.Norm());
        size_t iter(0);
        //Vector<T> z(A.getRows()); //vector with one column and the same number of rows of the matrix A
        Vector<T> z;

        while ((fabs(res[res.size()-1] / r0) > this->tol) && (iter < this->nb_iter)) {
            z = r; //P = I is the preconditioning matrix
            Vector<T> t = A * r; //row vector of size n
            T alpha = (z * r) / (z * t); //want to use transpose on a vector seen as a 1D matrix
            Vector<T> w = A * z;
            x = x + z * alpha;
            r = r - w * alpha;

            iter += 1;
            res.push_back(r.Norm());
       }
        return x;
     }catch(const runtime_error& e){
       cout << e.what() << endl;
       }
   }

   //make compiler happy
   template class Richardson<int>;
   template class Richardson<double>;
   template class Richardson<long int>;
   template class Richardson<long long int>;
   template class Richardson<float>;
   template class Richardson<complex<double>>;
   template class Richardson<complex<float>>;