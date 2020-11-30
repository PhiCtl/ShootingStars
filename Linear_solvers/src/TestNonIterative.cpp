//
// Created by descourt@INTRANET.EPFL.CH on 30.11.20.
//
#include <iostream>
#include "LU.cpp"
#include "Cholesky.cpp"

int main()
{
    vector<vector<double>> mat = {{1,1,1},{4,3,-1},{3,5,3}};
    Matrix<double> A(mat);
    A.Print(cout);

    LU<double> solver;
    solver.Decomposition(A);
    Matrix<double> L = solver.getL();
    L.Print(cout);
    Matrix<double> U = solver.getU();
    U.Print(cout);


    return 0;
}

