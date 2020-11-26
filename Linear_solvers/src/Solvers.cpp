//
// Created by descourt@INTRANET.EPFL.CH on 24.11.20.
//
#include <iostream>
//#include "Matrix.h"
//#include "Vector.h"
#include <cmath>
#include <limits>
#include <vector>
using namespace std;

typedef vector<vector<double>> Matrix;
typedef vector<double> Vector;

void Print(const Vector& v)
{
    for(auto el: v)
        cout << el << " ";
    cout << endl;
}

void Print(const Matrix& M)
{
    for(auto v: M)
        Print(v);
}

Vector  backward_subst(const Matrix& A,const Vector& b)
{
    int n = A.size();//int n = A.getColumns(); //A is upper triangular
    Vector x(n);            //

    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    return x;

}

Vector forward_subst(const Matrix& A, const Vector& b)
{
    int n = A.size();//int n = A.getColumns(); //
    Vector x(n);
    x[0] = b[0] / A[0][0]; //provided I can write it
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            x[i] -= A[i][j]*x[j];
        }
        x[i] = (x[i] + b[i]) / A[i][i];
    }

    return x;

}

Matrix identity(int n)
{
    Matrix I(n,Vector(n));//Matrix I (n,n, 0.0);
    for(int i = 0; i < n; ++i)
    {
        I[i][i] = 1;

    }
    return I;
}

Matrix transpose(const Matrix& M)
{
    int n = M.size();
    Matrix R(n, Vector(n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            R[j][i] = M[i][j];
    }
    return R;
}

void LU_decomposition(const Matrix& A, Matrix& L, Matrix& U) //Doolittle algorithm
{
    int n = A.size();//int n = A.getColumns()
    L = identity(n);
    for(int i = 0; i < n; ++i)
    {
        for(int k = i; k < n; ++k)
        {
            auto tot = 0.0;
            for(int j = 0; j < i; ++j)
            {
                tot += (L[i][j] * U[j][k]);
            }
            U[i][k] = A[i][k] - tot;
        }

        for(int k = i; k < n; ++k)
        {
            auto tot =  0.0;
            for(int j = 0; j < i; ++j)
            {
                tot += (L[k][j] * U[j][i]);
            }
            L[k][i] = (A[k][i] - tot) / (U[i][i]);
        }
    }
}

void Cholesky_decomposition(const Matrix& A, Matrix& R)
{
    int n = A.size();//int n = A.getColumns();
    R = Matrix(n, Vector(n));//R = Matrix(n,n,0.0);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            auto sum(0.0);
            if (i == j)
            {
                for (int k = 0; k < j; ++k)
                    sum += (R[j][k] * R[j][k]);
                R[j][j] = sqrt(A[j][j] - sum);
            }
            else{
                for(int k = 0; k < j; ++k)
                    sum += R[i][k] * R[j][k];
                R[i][j] = 1/R[j][j]*(A[i][j] - sum);
            }
        }
    }
}

Vector Cholesky(const  Matrix& A, const Vector& b){
    Matrix R(A.size(), Vector(A.size()));//Matrix R(A.getColumns(), A.getColumns(),0);
    Cholesky_decomposition(A,R);
    Vector y = forward_subst(R,b);
    Matrix R_ = transpose(R);//Matrix R_ = R.Transpose());
    Vector sol(backward_subst(R_, y));
    return sol;
}

Vector LU(const Matrix& A, const Vector& b)
{
    Matrix L(A.size(), Vector(A.size()));//Matrix L(A.getColumns(), A.getColumns(),0);
    Matrix U = L;
    LU_decomposition(A,L,U);
    Vector y(forward_subst(L,b));
    Print(y);
    Vector sol(backward_subst(U,y));
    return sol;
}

int main()
{
    Matrix A = {{4,12,-16},{12,37,-43},{-16,-43,98}};
    Vector b = {1,2,3};
    Print(Cholesky(A,b));
    return 0;
}
