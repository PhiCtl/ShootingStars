
#include "Jacobi.h"
#include <iostream>
#include <complex>

template <typename T>
Jacobi<T>::Jacobi(const Vector<T>& vec, int nb_iters, double tol) : Iterative_Solver<T>(vec, nb_iters, tol){};

template <typename T>
Jacobi<T>::Jacobi() : Iterative_Solver<T>(){};

template <typename T>
Jacobi<T>::~Jacobi(){};

template <typename T>
Jacobi<T>::Jacobi(const Jacobi<T>& solver){
    this-> initial_guess = solver.initial_guess;
    this-> nb_iter = solver.nb_iter;
    this-> tol = solver.tol;
}

template <typename T>
Vector<T> Jacobi<T>::Solve(const Matrix<T>& A, const Vector<T>& b) {
    try {
        T r0 = b.Norm();
        if (fabs(r0) <0)
            r0 = 1;
        if (this->initial_guess.getRows() <=1)
            this->initial_guess = Vector<T>(A.getCols());

        int n = A.getCols();
        Vector<T> x = this->initial_guess;
        Vector<T> r = A*x - b;
        vector<T> res(1, r.Norm());
        size_t iter(0);
        Vector<T> sum = Vector<T>(A.getCols());

        while((fabs(res[res.size()-1] / r0) > this->tol) && (iter < this->nb_iter)){

            for(int i = 0; i < n; i++){
               sum[i] = b(i);
               for(int j = 0; j < n; j++){
                   if(i!=j){
                       sum[i] = sum[i]- A(i,j)*x(j);
                   }
               }
           }
           for(int i = 0; i <n; i++){
               x[i] = sum[i]/A(i,i);
           }
           iter += 1;
           res.push_back(r.Norm());
        }
        return x;
    }catch(const runtime_error& e) {
    cout << e.what() << endl;
 }
}


template class Jacobi<int>;
template class Jacobi<double>;
template class Jacobi<long int>;
template class Jacobi<long double>;
template class Jacobi<long long int>;
template class Jacobi<float>;
template class Jacobi<complex<double>>;
template class Jacobi<complex<long double>>;
template class Jacobi<complex<float>>;