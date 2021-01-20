//
// Created by descourt@INTRANET.EPFL.CH on 04.12.20.
//
#include <gtest/gtest.h>
#include <Vector.cpp>
#include <FileReader.h>


template <bool complex_entry, int test>
class VectorOperationTest: public ::testing::Test{
public:
    VectorOperationTest():reader("../data/Vector/ComplexMat.mat", "../data/Vector/ComplexVec.mat",complex_entry) {};

    void SetUp()
    {
        reader.Read(A,b,3);
        string name;
        switch(test){
            case 1:{
                Res = A*b;
                name = "Res1.txt";
                break;
            }
            case 2:{
                Res = A*b - b*3;
                name = "Res2.txt";
                break;
            }
            default:
                break;

        }
        ifstream f("../data/Vector/"+name);
        reader.Vector_Reader(Truth, f, 3);

    }

    void Compare()
    {
        for(int i = 0; i < Res.getRows(); ++i)
        {
            ASSERT_NEAR(Res(i).real(), Truth(i).real(), 1e-9);
            ASSERT_NEAR(Res(i).imag(), Truth(i).imag(), 1e-9);
        }

    }
    Vector<complex<double>> b;
    Matrix<complex<double>> A;
    Vector<complex<double>> Res;
    Vector<complex<double>> Truth;
    FileReader reader;

};
using Operation1 = VectorOperationTest<true, 1>;
using Operation2 = VectorOperationTest<true,2>;


TEST(VectorBuilderTest, vector_constructors)
{
    Vector<double> vec1;
    EXPECT_EQ(vec1.getCols(),0);
    EXPECT_EQ(vec1.getRows(),0);

    Vector<double> vec2(9);
    EXPECT_EQ(vec2.getRows(),9);
    EXPECT_EQ(vec2.getCols(),1);
    EXPECT_EQ(vec2.getValue(), vector<double>(9));

    Vector<double> vec3(6,1);
    EXPECT_EQ(vec3.getRows(),6);
    EXPECT_EQ(vec3.getCols(),1);
}

TEST(VectorBuilderTest, vector_elements)
{
    Vector<double> vec1(6,1);
    vector<double> val1 = {1,1,1,1,1,1};
    EXPECT_EQ(vec1.getValue(), val1);

    vector<double> val2 = {1,2,3};
    Vector<double> vec2(2,val2);
    EXPECT_EQ(vec2.getValue(), val2);

    Vector<double> vec3(val2);
    EXPECT_EQ(vec2.getValue(), val2);

    EXPECT_EQ(vec3(0), 1);

    vec3[0] = 22;
    EXPECT_EQ(vec3(0),22);

    vec3.Push_back(56);
    EXPECT_EQ(vec3.getRows(),4);
    EXPECT_EQ(vec3(3),56);
}

TEST(VectorBuilderTest, copy_constructors)
{
    Vector<double> vec1 = vector<double>(3,4.7);
    EXPECT_EQ(vec1[1], 4.7);
    EXPECT_EQ(vec1.getRows(), 3);

    Vector<double> vec2;
    vec2 = vec1;
    EXPECT_EQ(vec2.getValue(),vec1.getValue());

    Matrix<double> mat(3,1,2);
    vec2 =  mat;
    EXPECT_EQ(vec2.getValue(), vector<double>(3,2));

}

TEST(VectorBuilder, not_allowed)
{
    Matrix<double> M(4,5,1);
    ASSERT_THROW(Vector<double> vec1(M),runtime_error);
}

TEST(VectorOperations, division_allowed)
{
    Vector<double> vec1(1,2);
    Vector<double> vec2(1,4);
    auto res = vec1/vec2;
    EXPECT_EQ(res, 0.5);
}

TEST(VectorOperations, multiplication_allowed)
{
    Vector<double> vec1(3,1);
    Vector<double> vec2(3,2);
    EXPECT_EQ(vec1*vec2, 6);
    vec1 = vec2*3;
    EXPECT_EQ(vec1(0),6);
}

TEST(VectorOperations, not_allowed)
{
    Vector<double> vec1(3,1);
    Vector<double> vec2(3,2);
    ASSERT_THROW(vec1/vec2, runtime_error);

    vec2 = vector<double>(4,1);
    ASSERT_THROW(vec1*vec2, runtime_error);

}

TEST_F(Operation1, complex_operations_1)
{
    Compare();
}

TEST_F(Operation2, complex_operations_2)
{
    Compare();
}

TEST(Operation3, scalar_conversion)
{
    Vector<double> Vec1(5,3);
    Vector<double> Vec2(5,2);
    EXPECT_DOUBLE_EQ(Vec2*Vec1, 30);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


