//
// Created by descourt@INTRANET.EPFL.CH on 30.11.20.
//
#include <iostream>
#include "LU.cpp"
#include "Cholesky.cpp"

int main()
{
    /*
    //Test LU
    vector<vector<double>> mat = {{1,1,1},{4,3,-1},{3,5,3}};
    Matrix<double> A(mat);
    vector<double> vec = {1,6,4};
    Vector<double> b(vec);
    //A.Print(cout);

    LU<double> solver;
    solver.Decomposition(A);
    Matrix<double> L = solver.getL();
    //L.Print(cout);
    Matrix<double> U = solver.getU();
    //U.Print(cout);
    //ref geekforgeek

    auto Solution =solver.Solve(A,b);
    //Solution.Print(cout);
    */

    //Test cholesky
    vector<vector<double>> mat2 = {{4,12,-16},{12,37,-43},{-16,-43,98}};
    Matrix<double> A2(mat2);
    vector<double> vec = {1,6,4};
    Vector<double> b(vec);

    Cholesky<double> chol_solver;
    chol_solver.Decomposition(A2);
    Matrix<double> R = chol_solver.getL();
    Matrix<double> R_ = chol_solver.getU();
    R.Print(cout);
    R_.Print(cout);

    auto Solution_2 = chol_solver.Solve(A2,b);
    Solution_2.Print(cout);





    return 0;
}

