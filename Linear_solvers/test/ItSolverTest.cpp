#include <gtest/gtest.h>
#include <Vector.h>
#include <Matrix.h>
#include <Jacobi.h>
#include <Conjugate_Gradient.h>
#include <Gauss_Seidel.h>
#include <Richardson.h>

TEST(Conjugate_GradientBuildertTest, Conjugate_Gradient){

    vector<vector<double>> mat = {{4,1},{1,3}};
    Matrix<double> A(mat);
    vector<double> vec = {1,2};
    Vector<double> b(vec);
    vector<double> sol = {0.0909091, 0.636364};
    Conjugate_Gradient<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);

}

TEST(JacobiBuildertTest, Jacobi){

    vector<vector<double>> mat = {{4,1},{1,3}};
    Matrix<double> A(mat);
    vector<double> vec = {1,2};
    Vector<double> b(vec);
    vector<double> sol = {0.0909091, 0.636364};
    Jacobi<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);

}


TEST(Gauss_SeidelBuildertTest, Gauss_Seidel){

    vector<vector<double>> mat = {{4,1},{1,3}};
    Matrix<double> A(mat);
    vector<double> vec = {1,2};
    Vector<double> b(vec);
    vector<double> sol = {0.0909091, 0.636364};
    Gauss_Seidel<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);

}

TEST(RichardsonBuildertTest, Richardson){

    vector<vector<double>> mat = {{4,1},{1,3}};
    Matrix<double> A(mat);
    vector<double> vec = {1,2};
    Vector<double> b(vec);
    vector<double> sol = {0.0909091, 0.636364};
    Richardson<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);

}

TEST(Conjugate_GradientBuildertTest1, Conjugate_Gradient1){

    vector<vector<double>> mat = {{5,1,1,0},{1,5,1,1},{1,1,5,1},{0,1,1,5}};
    Matrix<double> A(mat);
    vector<double> vec = {7,8,8,7};
    Vector<double> b(vec);
    vector<double> sol = {1,1,1,1};
    Conjugate_Gradient<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);

}

TEST(JacobiBuildertTest1, Jacobi1){

    vector<vector<double>> mat = {{5,1,1,0},{1,5,1,1},{1,1,5,1},{0,1,1,5}};
    Matrix<double> A(mat);
    vector<double> vec = {7,8,8,7};
    Vector<double> b(vec);
    vector<double> sol = {1,1,1,1};
    Jacobi<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);

}


TEST(Gauss_SeidelBuildertTest1, Gauss_Seidel1){

    vector<vector<double>> mat = {{5,1,1,0},{1,5,1,1},{1,1,5,1},{0,1,1,5}};
    Matrix<double> A(mat);
    vector<double> vec = {7,8,8,7};
    Vector<double> b(vec);
    vector<double> sol = {1,1,1,1};
    Gauss_Seidel<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);

}

TEST(RichardsonBuildertTest1, Richardson1){

    vector<vector<double>> mat = {{5,1,1,0},{1,5,1,1},{1,1,5,1},{0,1,1,5}};
    Matrix<double> A(mat);
    vector<double> vec = {7,8,8,7};
    Vector<double> b(vec);
    vector<double> sol = {1,1,1,1};
    Richardson<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);

}