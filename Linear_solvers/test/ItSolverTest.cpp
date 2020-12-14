#include <gtest/gtest.h>
#include <Vector.h>
#include <Matrix.h>
#include <Jacobi.h>
#include <Conjugate_Gradient.h>
#include <Gauss_Seidel.h>
#include <Richardson.h>
#include "FileReader.h"

template<int test>
class IterativeTestReal:public::testing::Test{
public:

    void SetUp() override{
        switch (test) {
            case 0:
                A = {{4,1},{1,3}};
                b = {1,2};
                sol = {0.0909091, 0.636364};
                break;
            case 1:
                A = {{5,1,1,0},{1,5,1,1},{1,1,5,1},{0,1,1,5}};
                b = {7,8,8,7};
                sol = {1,1,1,1};
                break;
            case 2:
                f = FileReader("MatSDP.mat", "Vec.mat", false)
                f.setFiles("MatSDP.mat", "Vec.mat")
                break;
            default:
                break;
        }
    }

    Matrix<double> A_file;
    vector<vector<double>> A;
    vector<double> b;
    Vector<double> b_file;
    vector<double> sol;
    FileReader f;
};

using IterativeTestRealF0 = IterativeTestReal<0>;
using IterativeTestRealF1 = IterativeTestReal<1>;
using IterativeTestRealF2 = IterativeTestReal<2>;

TEST_F(IterativeTestRealF0, Conjugate_Gradient){
    Conjugate_Gradient<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);
}

TEST_F(IterativeTestRealF0, Jacobi){
    Jacobi<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);
}


TEST_F(IterativeTestRealF0, Gauss_Seidel){
    Gauss_Seidel<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);
}

TEST_F(IterativeTestRealF0, Richardson){
    Richardson<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);
}

TEST_F(IterativeTestRealF1, Conjugate_Gradient1){
    Conjugate_Gradient<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);
}

TEST_F(IterativeTestRealF1, Jacobi1){
    Jacobi<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);
}


TEST_F(IterativeTestRealF1, Gauss_Seidel1){
    Gauss_Seidel<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);
}

TEST_F(IterativeTestRealF1, Richardson1){
    Richardson<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);
}

TEST_F(IterativeTestRealF2, Conjugate_Gradient2){
    Matrix
    Conjugate_Gradient<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);
}