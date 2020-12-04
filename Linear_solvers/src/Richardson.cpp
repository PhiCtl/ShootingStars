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
        //Matrix<T> P = Identity<T>(A.getCols());
        vector<T> res(1, r.Norm());
        size_t iter(0);
        Vector<T> z = r;

        while ((fabs(res[res.size()-1] / r0) > this->tol) && (iter < this->nb_iter)) {
            //z = P.solve(r); //P is the preconditioning matrix
            Vector<T> w = A * z;
            //double alpha = 0.2;
            x = x + z;
            r = r - w;

            iter += 1;
            res.Push_back(r.Norm());
        }
        return x;
        /*
           while ((fabs(res[res.getRows()-1] / r0) > this->tol) && (iter < this->nb_iter)) {
               // T alpha; //how define alpha??
               //x = x + r * alpha;
               x = x + r;
               iter += 1;
           }
           return x;
        */
       } catch(const runtime_error& e){
       cout << e.what() << endl;
       }
   }

   template <typename T>
   vector<complex<T>> operator *(const vector<complex<T>>& v, const complex<T> z) {
       vector<complex<T>> res;
       transform(v.begin(), v.end(), back_inserter(res),
                 [&](complex<T> x) -> complex<T> {
                     return x * z;
                 });
       return res;
   }


   //make compiler happy
   template class Richardson<int>;
   template class Richardson<double>;
   template class Richardson<long int>;
   template class Richardson<long long int>;
   template class Richardson<float>;
   template class Richardson<complex<double>>;
   template class Richardson<complex<float>>;