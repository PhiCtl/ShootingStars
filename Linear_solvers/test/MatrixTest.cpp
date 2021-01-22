#include <gtest/gtest.h>
#include "Matrix.cpp"

TEST(MatrixBuilderTest, matrix_constructos){
    Matrix<double> mat1;
    EXPECT_EQ(mat1.getCols(),0);
    EXPECT_EQ(mat1.getRows(),0);

    vector<vector<double>> mat_ = {{2,2,2,2},{2,2,2,2},{2,2,2,2},{2,2,2,2}};
    Matrix<double> mat2(4,4,2);
    EXPECT_EQ(mat2.getCols(),4);
    EXPECT_EQ(mat2.getRows(),4);
    EXPECT_EQ(mat2.getValue(), mat_);

    vector<vector<double>> mat = {{2,3,4},{5,6,7}};
    Matrix<double> mat3(mat);
    EXPECT_EQ(mat3.getCols(),3);
    EXPECT_EQ(mat3.getRows(),2);
    EXPECT_EQ(mat3.getValue(),mat);

    vector<double> vec = {1,2,4};
    vector<vector<double>> _mat_ = {{1,1,1,1},{2,2,2,2},{4,4,4,4}};
    Matrix<double> mat4(4,vec);
    EXPECT_EQ(mat4.getCols(),4);
    EXPECT_EQ(mat4.getRows(),3);
    EXPECT_EQ(mat4.getValue(),_mat_);

}

TEST(MatrixBuilderTest, matrix_elements){

    Matrix<double> mat1(3,3,5);
    vector<vector<double>> val_mat1 = {{5,5,5},{5,5,5},{5,5,5}};
    EXPECT_EQ(mat1.getValue(), val_mat1);

    vector<vector<double>> val_mat2 = {{2,6,8},{5,4,3},{8,4,5}};
    Matrix<double> mat2(val_mat2);
    EXPECT_EQ(mat2.getValue(), val_mat2);

}

TEST(MatrixBuilderTest, copy_constructors){
    Matrix<double> mat1(4,4,2);
    vector<vector<double>> val_mat1 = {{2,2,2,2},{2,2,2,2},{2,2,2,2},{2,2,2,2}};
    EXPECT_EQ(mat1.getRows(),4);
    EXPECT_EQ(mat1.getCols(),4);
    EXPECT_EQ(mat1.getValue(), val_mat1);

    Matrix<double> mat2;
    mat2 = mat1;
    EXPECT_EQ(mat2.getRows(), 4);
    EXPECT_EQ(mat2.getCols(),4);
    EXPECT_EQ(mat2.getValue(), val_mat1);
}

TEST(MatrixBuilderTest, matrix_operations){

    vector<vector<double>> val_mat2 = {{1,1,1},{1,1,1},{1,1,1}};
    vector<vector<double>> val_mat1 = {{5,5,5},{5,5,5},{5,5,5}};
    vector<vector<double>> val_mat_sum = {{6,6,6},{6,6,6},{6,6,6}};
    Matrix<double> mat1(val_mat1);
    Matrix<double> mat2(val_mat2);
    Matrix<double> mat_sum = mat1 + mat2;
    EXPECT_EQ(mat_sum.getValue(), val_mat_sum);

    vector<vector<double>> val_mat3 = {{1,1,1},{1,1,1},{1,1,1}};
    vector<vector<double>> val_mat4 = {{5,5,5},{5,5,5},{5,5,5}};
    vector<vector<double>> val_mat_sub ={{4,4,4},{4,4,4},{4,4,4}};
    Matrix<double> mat3(val_mat3);
    Matrix<double> mat4(val_mat4);
    Matrix<double> mat_sub = mat4 - mat3;
    EXPECT_EQ(mat_sub.getValue(), val_mat_sub);

    vector<vector<double>> val_mat5 = {{1,2,3},{4,5,6},{7,8,9}}; //double value?? 1.0
    vector<vector<double>> val_mat6 = {{2,2,2},{3,3,3},{4,4,4}};
    vector<vector<double>> val_mat_mul = {{20,20,20},{47,47,47},{74,74,74}};
    Matrix<double> mat5(val_mat5);
    Matrix<double> mat6(val_mat6);
    Matrix<double> mat_mul = mat5 * mat6;
    EXPECT_EQ(mat_mul.getValue(), val_mat_mul);

    double s = 6;
    vector<vector<double>> val_mat_sca = {{6,12,18},{24,30,36},{42,48,54}};
    Matrix<double> mat_mul_mat_sca = mat5 * s;
    EXPECT_EQ(mat_mul_mat_sca.getValue(), val_mat_sca);

    //Transpose test
    vector<vector<double>> val_mat_transpose = {{1,4,7},{2,5,8},{3,6,9}};
    Matrix<double> mat_transpose = mat5.transpose();
    EXPECT_EQ(mat_transpose.getValue(), val_mat_transpose);

    //Lower triangular matrix test
    vector<vector<double>> val_mat_lower = {{1,0,0},{4,5,0},{7,8,9}};
    Matrix<double> mat_lower = mat5.LowerTriangularMatrix();
    EXPECT_EQ(mat_lower.getValue(), val_mat_lower);

    vector<vector<double>> val_mat_upper = {{1,2,3},{0,5,6},{0,0,9}};
    Matrix<double> mat_upper = mat5.UpperTriangularMatrix();
    EXPECT_EQ(mat_upper.getValue(), val_mat_upper);

    vector<vector<double>> val_mat_diagonal = {{1,0,0},{0,5,0},{0,0,9}};
    Matrix<double> mat_diagonal = mat5.DiagonalMatrix();
    EXPECT_EQ(mat_diagonal.getValue(), val_mat_diagonal);

}

TEST(Matrix_to_scalar, correct_cast){
    Matrix<double> mat(1,1,2);
    EXPECT_DOUBLE_EQ(mat.To_scalar(), 2);
}

TEST(Matrix_to_scalar, incorrect_cast)
{
    Matrix<double> mat(2,1,5);
    ASSERT_THROW(mat.To_scalar(), invalid_argument);
}

TEST(Matrix_to_scalar, division)
{
    Matrix<double> mat1(1,5,3);
    Matrix<double> mat2(5,1,2);
    EXPECT_DOUBLE_EQ(mat1*mat2/ (mat1*mat2), 1);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}