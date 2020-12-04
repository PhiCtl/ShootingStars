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
    EXPECT_EQ(vec1.getCols(),1);
    EXPECT_EQ(vec1.getValue(), vector<double>(9));

    Vector<double> vec3(6,1);
    EXPECT_EQ(vec2.getRows(),6);
    EXPECT_EQ(vec1.getCols(),1);
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

    EXPECT_EQ(vec3[0], 1);
}

TEST(VectorBuilderTest, copy_constructors)
{
    Vector<double> vec1 = vector<double>(3,4.7);
    EXPECT_EQ(vec1[1], 4.7);
    EXPECT_EQ(vec1.getRows(), 3);

    Vector<double> vec2;
    vec2 = vec1;
    EXPECT_EQ(vec2.)

}


