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
                ifstream sol_vec("../data/Sol.mat");
                ifstream b_vec("../data/VecSDP.mat");
                ifstream mat("../data/MatSDP.mat");
                read.Matrix_Reader(A_file, mat,20);
                read.Vector_Reader(b_file, b_vec ,20);
                read.Vector_Reader(sol_file, sol_vec ,20);
                break;
        }
    }

    vector<vector<double>> A;
    vector<double> b;
    vector<double> sol;
    FileReader read;
    Matrix<double> A_file;
    Vector<double> b_file;
    Vector<double> sol_file;

};

template<int test>
class IterativeTestComplex:public::testing::Test{
public:
    void SetUp(){
        switch(test){
            case 0:
                break;
            case 1:
                break;
            default:
                break;
        }
    }

    vector<vector<complex<double>>> A;
    vector<complex<double>> b;
    vector<complex<double>> sol;
};


using IterativeTestRealF0 = IterativeTestReal<0>;
using IterativeTestRealF1 = IterativeTestReal<1>;
using IterativeTestRealF2 = IterativeTestReal<2>;
using IterativeTestComlexF0 = IterativeTestComplex<0>;
using IterativeTestComplexF1 = IterativeTestComplex<1>;

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
    Conjugate_Gradient<double> solver;
    ASSERT_NEAR(solver.Solve(A_file,b_file).getValue()[0], sol_file[0], 1e-4);
}