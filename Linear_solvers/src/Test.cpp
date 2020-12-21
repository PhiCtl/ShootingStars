#include <iostream>
#include <string>

#include <Jacobi.h>
#include <Gauss_Seidel.h>
#include <Conjugate_Gradient.h>
#include <Richardson.h>
#include <LU.h>
#include <Cholesky.h>
#include <Conjugate_Gradient.h>
enum{ Lu, cholesky, Conjugate_gradient, jacobi, GaussSeidel, richardson}; //enum type for solver type
using namespace std;

template <typename T> LinearSolver<T>* Solver(int solver_type)
{
    LinearSolver<T>* solver;
    switch(solver_type){
        case Lu:
            solver = new LU<T&>;
            break;
        case cholesky:
            solver = new Cholesky<T&>;
            break;
        case Conjugate_gradient:
            solver = new Conjugate_Gradient<T&>;
            break;
        case jacobi:
            solver = new Jacobi<T&>;
            break;
        case richardson:
            solver = new Richardson<T&>;
            break;
        case GaussSeidel:
            solver = new Gauss_Seidel<T&>;
            break;
        default:
            break;
    }
}

int main()
{


    return 0;
}