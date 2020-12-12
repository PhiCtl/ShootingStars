//
// Created by descourt@INTRANET.EPFL.CH on 07.12.20.
//
#include <gtest/gtest.h>
#include <Vector.h>
#include <LU.h>
#include <Cholesky.h>
#include <complex>

template<int test>
class NonIterativeTestReal:public ::testing::Test{
public:

    void SetUp() override{
        vector<vector<double>> mat = {{4,12,-16},{12,37,-43},{-16,-43,98}};
        A = mat;

        switch(test){
            case 0:
                L = { { 1, 0, 0 }, { 3, 1, 0 }, { -4, 5, 1 } };
                U = { { 4, 12, -16 }, { 0, 1, 5 }, { 0, 0, 9 } };
                break;
            case 1:
                L =  {{2,0,0},{6,1,0},{-8,5,3}};
                U = {{2,6,-8},{0,1,5},{0,0,3}};
                break;
            case 2:
                b = {1,6,4};
                sol = {-23.5278,6.8889,-0.7778};
                break;
            default:
                break;

        }
    }

    Matrix<double> A;
    vector<vector<double>> L;
    vector<vector<double>> U;
    vector<double> b;
    vector<double> sol;
};
template<int test> class NonIterativeTestComplex:public ::testing::Test{
public:
    void SetUp(){
        vector<vector<complex<double>>> mat = {{100,complex<double>(2,-1)},{complex<double>(2,-1),100}};

        A = mat;
        switch(test){
            case 0:
                L = { { 10, 0}, { complex<double>(0.2,-0.1), complex<double>(9.9985,0.0020003) } };
                U = { { 10, complex<double>(0.2,0.1) }, { 0, complex<double>(9.9985,-0.0020003) } };

                break;
            case 1:
                b = vector<complex<double>>({complex<double>(102,-1), complex<double>(102,1)});
                sol = vector<complex<double>>(2,1);
                break;
            default:
                break;

        }

    }
    Matrix<complex<double>> A;
    Vector<complex<double>> b;
    vector<vector<complex<double>>> L;
    vector<vector<complex<double>>> U;
    vector<complex<double>>  sol;

};

using NonIterativeTestRealF1 = NonIterativeTestReal<0>;
using NonIterativeTestRealF2 = NonIterativeTestReal<1>;
using NonIterativeTestRealF3 = NonIterativeTestReal<2>;
using NonItTeComp1 = NonIterativeTestComplex<0>;
using NonItTeComp2 = NonIterativeTestComplex<1>;

TEST_F(NonIterativeTestRealF1, lu_decomposition)
{

    LU<double> solver;
    solver.Decomposition(A);
    EXPECT_EQ(solver.getL().getValue(),L);
    EXPECT_EQ(solver.getU().getValue(), U);

}
TEST_F(NonIterativeTestRealF2, cholesky_decomposition)
{

    Cholesky<double> solver;
    solver.Decomposition(A);
    EXPECT_EQ(solver.getL().getValue(),L);
    EXPECT_EQ(solver.getU().getValue(), U);
}

TEST_F(NonIterativeTestRealF3, lu_solution)
{
    LU<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);
}

TEST_F(NonIterativeTestRealF3, chol_solution)
{
    Cholesky<double> solver;
    ASSERT_NEAR(solver.Solve(A,b).getValue()[0], sol[0], 1e-4);
}

TEST_F(NonItTeComp1, chol_factorization_complex)
{
    Cholesky<complex<double>> solver;
    solver.Decomposition(A);
    EXPECT_EQ(solver.getL()(1,1),L[1][1]);
    EXPECT_EQ(solver.getU()(1,1),U[1][1]);
}
TEST_F(NonItTeComp2, chol_solution_complex)
{
    Cholesky<complex<double>> solver;
    solver.Decomposition(A);
    Vector<complex<double>> Vec = solver.Solve(A,b);
    ASSERT_NEAR(Vec(0).real(),1,1e-3);
    ASSERT_NEAR(Vec(0).imag(), 0, 1e-2);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

