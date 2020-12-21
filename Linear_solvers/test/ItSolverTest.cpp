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
            case 0: {
                ifstream matA2x2("../data/ItSolver/Mat2x2.txt");
                ifstream vecB2x1("../data/ItSolver/VecB2x1.txt");
                ifstream vecSol2x1("../data/ItSolver/VecSol2x1.txt");

                read.Matrix_Reader(A,matA2x2, 2);
                read.Vector_Reader(b, vecB2x1, 2);
                read.Vector_Reader(sol, vecSol2x1, 2);

                break;
            }
            case 1: {
                ifstream matA4x4("../data/ItSolver/Mat4x4.txt");
                ifstream vecB4x1("../data/ItSolver/VecB4x1.txt");
                ifstream vecSol4x1("../data/ItSolver/VecSol4x1.txt");

                read.Matrix_Reader(A,matA4x4, 4);
                read.Vector_Reader(b, vecB4x1, 4);
                read.Vector_Reader(sol, vecSol4x1, 4);

                break;
            }
            case 2: {
                ifstream matA20x20("../data/ItSolver/Mat20x20.txt");
                ifstream vecB20x1("../data/ItSolver/VecB20x1.txt");
                ifstream vecSol20x1("../data/ItSolver/VecSol20x1.txt");

                read.Matrix_Reader(A, matA20x20,20);
                read.Vector_Reader(b, vecB20x1 ,20);
                read.Vector_Reader(sol, vecSol20x1 ,20);
                break;
            }
            default:
                break;
        }

    }

    void Compare(const Matrix<double>& mat){
        for(int i = 0; i < A.getRows(); i++){
            ASSERT_NEAR(mat(i,0), sol(i), 1e-4);
        }
    }


    FileReader read;
    Matrix<double> A;
    Vector<double> b;
    Vector<double> sol;

};


template<int test>
class IterativeTestComplex:public::testing::Test{
public:
    IterativeTestComplex():read(true){};

    void SetUp(){
        switch(test){
            case 0: {
                ifstream matCompl("../data/ItSolver/ComplexMatA.txt");
                ifstream vecBCompl("../data/ItSolver/ComplexVecB.txt");
                ifstream vecSolCompl("../data/ItSolver/ComplexVecSol.txt");
                read.Matrix_Reader(A, matCompl, 2);
                read.Vector_Reader(b, vecBCompl, 2);
                read.Vector_Reader(sol, vecSolCompl, 2);
                break;
            }
            default:
                break;
        }
    }

    void Compare(const Matrix<complex<double>>& mat){
        for(int i = 0; i < A.getRows(); i++){
            ASSERT_NEAR(mat(i,0).real(), sol(i).real(), 1e-4);
            ASSERT_NEAR(mat(i,0).imag(), sol(i).imag(), 1e-4);
        }
    }

    FileReader read;
    Matrix<complex<double>> A;
    Vector<complex<double>> b;
    Vector<complex<double>> sol;
};



using IterativeTestRealF0 = IterativeTestReal<0>;
using IterativeTestRealF1 = IterativeTestReal<1>;
using IterativeTestRealF2 = IterativeTestReal<2>;
using IterativeTestComlexF0 = IterativeTestComplex<0>;
//using IterativeTestComplexF1 = IterativeTestComplex<1>;

TEST_F(IterativeTestRealF0, Conjugate_Gradient){
    Conjugate_Gradient<double> solver;
    Compare(solver.Solve(A,b));
}

TEST_F(IterativeTestRealF0, Jacobi){
    Jacobi<double> solver;
    Compare(solver.Solve(A,b));
}

TEST_F(IterativeTestRealF0, Gauss_Seidel){
    Gauss_Seidel<double> solver;
    Compare(solver.Solve(A,b));
}

TEST_F(IterativeTestRealF0, Richardson){
    Richardson<double> solver;
    Compare(solver.Solve(A,b));
}

TEST_F(IterativeTestRealF1, Conjugate_Gradient1){
    Conjugate_Gradient<double> solver;
    Compare(solver.Solve(A,b));
}

TEST_F(IterativeTestRealF1, Jacobi1){
    Jacobi<double> solver;
    Compare(solver.Solve(A,b));
}


TEST_F(IterativeTestRealF1, Gauss_Seidel1){
    Gauss_Seidel<double> solver;
    Compare(solver.Solve(A,b));
}

TEST_F(IterativeTestRealF1, Richardson1){
    Richardson<double> solver;
    Compare(solver.Solve(A,b));
}

TEST_F(IterativeTestRealF2, Conjugate_Gradient2){
    Conjugate_Gradient<double> solver;
    Compare(solver.Solve(A,b));
}

TEST_F(IterativeTestRealF2, Jacobi2){
    Jacobi<double> solver;
    solver.Set_parameters_it(1000);
    Compare(solver.Solve(A,b));
}

TEST_F(IterativeTestRealF2, Gauss_Seidel2){
    Gauss_Seidel<double> solver;
    solver.Set_parameters_it(700);
    Compare(solver.Solve(A,b));
}

TEST_F(IterativeTestRealF2, Richardson2){
    Richardson<double> solver;
    solver.Set_parameters_it(1000);
    Compare(solver.Solve(A,b));
}

TEST_F(IterativeTestComlexF0, Conjugate_Gradient_Complex){
    Conjugate_Gradient<complex<double>> solver;
    auto output = solver.Solve(A,b);
    Compare(output);
}

TEST_F(IterativeTestComlexF0, Jacobi_Complex){
    Jacobi<complex<double>> solver;
    auto output = solver.Solve(A,b);
    Compare(output);
}

TEST_F(IterativeTestComlexF0, Gauss_Seidel_Complex){
    Gauss_Seidel<complex<double>> solver;
    auto output = solver.Solve(A,b);
    Compare(output);
}

TEST_F(IterativeTestComlexF0, Richardson_Complex){
    Richardson<complex<double>> solver;
    auto output = solver.Solve(A,b);
    Compare(output);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}