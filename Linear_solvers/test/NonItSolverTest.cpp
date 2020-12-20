//
// Created by descourt@INTRANET.EPFL.CH on 07.12.20.
//
#include <gtest/gtest.h>
#include <LU.h>
#include <Cholesky.h>
#include <complex>
#include <FileReader.h>
#include <fstream>

template<int test>
class NonIterativeTestReal:public ::testing::Test{
public:

    NonIterativeTestReal():read("../data/NonItSolver/sparseA.txt","../data/NonItSolver/B.mat",false) {}

    void SetUp() override{
        read.Read(A,b,20);

        switch(test){
            case 0: {
                ifstream f("../data/NonItSolver/sparse_chol.txt");
                read.Matrix_Reader(U,f,20);
                L = U.transpose();
                break;
            }//cholesky

            case 1: {
                ifstream f("../data/NonItSolver/L_sparse.txt");
                read.Matrix_Reader(L,f,20);
                f = ifstream("../data/NonItSolver/U_sparse.txt");
                read.Matrix_Reader(U,f,20);
                break;
            }//LU

            case 2: {
                ifstream f("../data/NonItSolver/Sol.txt");
                read.Vector_Reader(sol, f, 20);
                break;
            }//Solution

            default:
                break;

        }
    }
    void Compare(const Matrix<double>& mat, int casus) {
        switch (casus) {
            case 0 : //L U decomposition: L matrix
                for (int i = 0; i < mat.getRows(); ++i) {
                    for (int j = 0; j < mat.getCols(); ++j) {
                        ASSERT_NEAR(L(i,j), mat(i, j), 1e-5);
                    }
                }
                break;
            case 1: //U matrix
                for(int i = 0; i <mat.getRows(); ++i)
                {
                    for(int j = 0; j < mat.getCols(); ++j)
                        ASSERT_NEAR(U(i,j), mat(i,j), 1e-5);
                }
                break;
            case 2: //solution
                for(int i = 0; i < sol.getRows(); ++i)
                    ASSERT_NEAR(mat(i,0), sol(i), 1e-5);
            default:
                break;

        }
    }

    Matrix<double> A;
    Matrix<double> L;
    Matrix<double>  U;
    Vector<double> b;
    Vector<double> sol;
    FileReader read;
};
template<int test> class NonIterativeTestComplex:public ::testing::Test{
public:
    NonIterativeTestComplex():read("../data/NonItSolver/ComplexLUPA.txt","../data/NonItSolver/ComplexB.txt",true) {}

    void SetUp(){
        read.Read(A,b,3);

        switch(test){

            case 0: {
                ifstream f("../data/NonItSolver/ComplexLU_sol.txt");
                read.Vector_Reader(sol, f, 3);
                break;
            }// LUx= b
            case 1:{
                ifstream f("../data/NonItSolver/ComplexCholA.txt");
                read.Matrix_Reader(A, f,3);
                break;
            }
            default:
                break;

        }

    }
    void Compare(const Matrix<complex<double>>& mat, int casus) {
        switch (casus) {
            case 0 : //L U or cholesky decomposition: test against A
                for (int i = 0; i < mat.getRows(); ++i) {
                    for (int j = 0; j < mat.getCols(); ++j) {
                        ASSERT_NEAR(A(i,j).real(), mat(i, j).real(), 1e-5);
                        ASSERT_NEAR(A(i,j).imag(), mat(i, j).imag(), 1e-5);
                    }
                }
                break;

            case 1: //solution
                for(int i = 0; i < sol.getRows(); ++i)
                {
                    ASSERT_NEAR(mat(i,0).real(), sol(i).real(), 1e-5);
                    ASSERT_NEAR(mat(i,0).imag(), sol(i).imag(), 1e-5);
                }
                break;
            default:
                break;

        }


    }
    Matrix<complex<double>> A;
    Vector<complex<double>> b;
    FileReader read;
    Matrix<complex<double>> L;
    Matrix<complex<double>> U;
    Vector<complex<double>>  sol;

};

using NonIterativeTestRealF1 = NonIterativeTestReal<0>;
using NonIterativeTestRealF2 = NonIterativeTestReal<1>;
using NonIterativeTestRealF3 = NonIterativeTestReal<2>;
using NonItTeComp0 = NonIterativeTestComplex<0>;
using NonItTeComp1 = NonIterativeTestComplex<1>;

TEST_F(NonIterativeTestRealF2, lu_decomposition)
{

    LU<double> solver;
    solver.Decomposition(A);
    Compare(solver.getL(),0);
    Compare(solver.getU(), 1);


}
TEST_F(NonIterativeTestRealF1, cholesky_decomposition)
{

    Cholesky<double> solver;
    solver.Decomposition(A);
    Compare(solver.getL(), 0);
    Compare(solver.getU(),1);
}

TEST_F(NonIterativeTestRealF3, lu_solution)
{
    LU<double> solver;
    Compare(solver.Solve(A,b), 2);
}

TEST_F(NonIterativeTestRealF3, chol_solution)
{
    Cholesky<double> solver;
    Compare(solver.Solve(A,b), 2);
}

TEST_F(NonItTeComp0, lu_fact_complex)
{
    LU<complex<double>> solver;
    solver.Decomposition(A);
    auto res = solver.getL() * solver.getU();
    Compare(res, 0);
}
TEST_F(NonItTeComp0, lu_complex_sol)
{
    LU<complex<double>> solver;
    auto res = solver.Solve(A,b);
    Compare(res, 1);
}
TEST_F(NonItTeComp1, chol_decomposition_complex)
{
    Cholesky<complex<double>> solver;
    solver.Decomposition(A);
    auto res = solver.getL() * solver.getU();
    solver.getL().Print(cout);
    Compare(res, 0);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

