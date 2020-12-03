//
// Created by descourt@INTRANET.EPFL.CH on 02.12.20.
//
#include <iostream>
#include "Conjugate_Gradient.cpp"

int main()
{
    Conjugate_Gradient<double> solver;
    vector<vector<double>> vec = {{4,1},{1,3}};
    vector<double> vec2 = {1,2};
    Matrix<double> A(vec);
    Vector<double> b(vec2);

    auto Sol = solver.Solve(A,b);
    Sol.Print(cout);

    return 0;

}

