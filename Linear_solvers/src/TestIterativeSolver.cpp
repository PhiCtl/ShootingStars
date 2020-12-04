
#include <iostream>
#include "Conjugate_Gradient.cpp"
#include "Jacobi.cpp"
#include "Gauss_Seidel.cpp"
#include "Richardson.cpp"

int main()
{
    Conjugate_Gradient<double> solver;
    vector<vector<double>> vec = {{4,1},{1,3}};
    vector<double> vec2 = {1,2};
    Matrix<double> A(vec);
    Vector<double> b(vec2);

    std::cout << "Conjugate_Gradient solution: " << "\n ";
    auto Sol = solver.Solve(A,b);
    Sol.Print(cout);

    Jacobi<double> solverJ;
    std::cout << "Jacobi solution: " << "\n ";
    auto SolJ = solverJ.Solve(A,b);
    SolJ.Print(cout);

    Gauss_Seidel<double> solverGS;
    std::cout << "Gauss_Seidel solution: " << "\n ";
    auto SolSG = solverGS.Solve(A,b);
    SolSG.Print(cout);

    Richardson<double> solverR;
    std::cout << "Richardson solution: " << "\n ";
    auto SolR = solverR.Solve(A,b);
    SolR.Print(cout);

    return 0;

}

