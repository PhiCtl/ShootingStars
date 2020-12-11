//
// Created by descourt@INTRANET.EPFL.CH on 07.12.20.
//
#include <gtest/gtest.h>
#include <Vector.h>
#include <LU.h>
#include <Cholesky.h>

//Fixture Class?

TEST(Decomposition, lu_decomposition)
{
    vector<vector<double>> mat = {{4,12,-16},{12,37,-43},{-16,-43,98}};
    vector<vector<double>> L_mat = { { 1, 0, 0 }, { 3, 1, 0 }, { -4, 5, 1 } };
    vector<vector<double>> U_mat = { { 4, 12, -16 }, { 0, 1, 5 }, { 0, 0, 9 } };
    Matrix<double> A(mat);
    LU<double> solver;
    solver.Decomposition(A);
    EXPECT_EQ(solver.getL().getValue(),L_mat);
    EXPECT_EQ(solver.getU().getValue(), U_mat);

}
TEST(Decomposition, cholesky_decomposition)
{
    vector<vector<double>> mat = {{4,12,-16},{12,37,-43},{-16,-43,98}};
    vector<vector<double>> L_mat = {{2,0,0},{6,1,0},{-8,5,3}};
    vector<vector<double>> U_mat = {{2,6,-8},{0,1,5},{0,0,3}};
    Matrix<double> A(mat);
    Cholesky<double> solver;
    solver.Decomposition(A);
    EXPECT_EQ(solver.getL().getValue(),L_mat);
    EXPECT_EQ(solver.getU().getValue(), U_mat);
}

TEST(Solver, lu_solution)
{
    vector<vector<double>> mat = {{4,12,-16},{12,37,-43},{-16,-43,98}};
    Matrix<double> A(mat);
    vector<double> vec = {1,6,4};
    Vector<double> b(vec);
    vector<double> sol = {-23.5278,6.8889,-0.7778};
    LU<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);
}

TEST(Solver, chol_solution)
{
    vector<vector<double>> mat = {{4,12,-16},{12,37,-43},{-16,-43,98}};
    Matrix<double> A(mat);
    vector<double> vec = {1,6,4};
    Vector<double> b(vec);
    vector<double> sol = {-23.5278,6.8889,-0.7778};
    Cholesky<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

