//
// Created by descourt@INTRANET.EPFL.CH on 04.12.20.
//
#include <gtest/gtest.h>
#include <Vector.cpp>

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

TEST(VectorOperations, allowed_operations)
{
    Vector<double> vec1(1,2);
    Vector<double> vec2(1,4);
    EXPECT_EQ(vec2/vec1, 2);

    Vector<double> vec3(3,1);
    Vector<double> vec4(3,2);
    EXPECT_EQ(vec3*vec4, 6);
    vec4 = vec3*3;
    EXPECT_EQ(vec4(0),3);
}

TEST(VectorOperations, not_allowed)
{
    Vector<double> vec1(3,1);
    Vector<double> vec2(3,2);
    ASSERT_THROW(vec1/vec2, runtime_error);

    vec2 = vector<double>(4,1);
    ASSERT_THROW(vec1*vec2, runtime_error);

}


