//
// Created by descourt@INTRANET.EPFL.CH on 07.12.20.
//

#include <vector>
#include "CommandLineReader.h"
#include "FileReader.h"
#include "Matrix.h"
#include "Vector.h"
#include <complex>
#include <gtest/gtest.h>

template <bool complex_entry, int test>
class ReaderTest: public ::testing::Test {
public:
    ReaderTest():reader(complex_entry) {}

    void SetUp() override {
        switch(test){
            case 0:
                is = istringstream("3 (4,6)\n4 (5,1)\n");
                is2 = istringstream("3\n(7,8)");
                mat = {{3,complex<double>(4,6)},{4, complex<double>(5,1)}};
                vec = {3, complex<double>(7,8)};
                break;
            case 1:
                mat    = {{3,4},{5,6}};
                vec = {8,9};
                is = istringstream("3 4\n5 6\n");
                is2 = istringstream("8\n9");
                break;
            case 2:
                is = istringstream("3 4\n5 6 7\n");
                is2 = istringstream("8\n9 9\n");
                vec = {8,9};
                break;
            default:
                break;
        }

    }

    void TearDown( ) override {
        cin.clear();
    }

    ~ReaderTest( )  {
        // cleanup any pending stuff, but no exceptions allowed
    }

    Vector<complex<double>> V;
    Matrix<complex<double>> M;
    vector<vector<complex<double>>> mat;
    vector<complex<double>> vec;
    istringstream is, is2;
    Reader reader;

};

template <bool complex_entries>
class FileReaderTest: public ::testing::Test
{
public:
    FileReaderTest():F("../data/Mat.mat", "../data/Vec.mat",complex_entries) {};

    void SetUp() override
    {}
    void TearDown() override {}

    Vector<complex<double>> V;
    Matrix<complex<double>> M;
    FileReader F;
};

using Reader1 = ReaderTest<true,0>;
using Reader2 = ReaderTest<false,1>;
using Reader3 = ReaderTest<false,0>;
using Reader4 = ReaderTest<false,2>;

using FileReaderTestF1 = FileReaderTest<true>;
using FileReaderTestF2 = FileReaderTest<false>;

TEST_F(Reader1,correct_complex_entries)
{
    reader.Matrix_Reader(M,is,2);
    EXPECT_EQ(M.getValue(),mat);
    reader.Vector_Reader(V,is2,2);
    EXPECT_EQ(V.getValue(), vec);

}

TEST_F(Reader2, correct_real_entries)
{
    reader.Matrix_Reader(M,is,2);
    EXPECT_EQ(M.getValue(),mat);
    reader.Vector_Reader(V,is2,2);
    EXPECT_EQ(V.getValue(), vec);
}

TEST_F(Reader3, complex_entry_found)
{

    ASSERT_THROW(reader.Matrix_Reader(M,is,2), domain_error);
    ASSERT_THROW(reader.Vector_Reader(V,is2,2), domain_error);

}

TEST_F(Reader4, invalid_entries)
{
    ASSERT_THROW(reader.Matrix_Reader(M,is,2), length_error);
    reader.Vector_Reader(V,is2,2);
    EXPECT_EQ(V.getValue(), vec) ;
}

TEST_F(FileReaderTestF2, complex_entries_found)
{

    ASSERT_THROW(F.Read(M,V,2), domain_error);
}

TEST_F(FileReaderTestF1, correct_complex_entries)
{
    F.Read(M,V,2);
    vector<vector<complex<double>>> mat = {{0,2},{4,5}};
    mat[0][0] = complex<double>(1,5);

    vector<complex<double>> vec {3,4};
    EXPECT_EQ(M.getValue(),mat );
    EXPECT_EQ(V.getValue(), vec);
}

TEST_F(FileReaderTestF1, incorrect_dimensions)
{
    ASSERT_THROW(F.Read(M,V,3), length_error);
}

 int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
