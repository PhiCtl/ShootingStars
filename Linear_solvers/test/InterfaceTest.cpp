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
class CommandLineTest: public ::testing::Test {
public:
     CommandLineTest():reader(complex_entry) {}

    void SetUp() override {
        switch(test){
            case 0:
                cout << "Enter those numbers for matrix (dim 4):" << endl;
                cout << "3 4 5 6 \n4 5 6 7 \n7 8 9 10 \n2 3 4 5 \n" << endl;
                cout << "Enter those numbers for vector (dim 4):" << endl;
                cout << "3 \n4 \n5 \n6\n" << endl;

                break;
            case 1:
                cout << "Enter those numbers for matrix (dim 2):" << endl;
                cout << "3 (4,6) \n4 (5,1) \n " << endl;
                cout << "Enter those numbers for vector (dim 2):" << endl;
                cout << "3 \n(5,8) \n" << endl;

                break;
            case 2:
                cout << "Enter those numbers for matrix (dim 2):" << endl;
                cout << "3 (4,6) \n4 (5,1) \n " << endl;
                cout << "Enter those numbers for vector (dim 2):" << endl;
                cout << "3 \n(5,8)\n" << endl;

                break;
            case 3:
                cout << "Enter those numbers for matrix (dim 2):" << endl;
                cout << "3 5 \n4 7 5 " << endl;
                cout << "Enter those numbers for vector (dim 2):" << endl;
                cout << "3 \n9" << endl;

                break;
            default:
                break;

        }

    }

    void TearDown( ) override {
        cin.clear();
    }

    ~CommandLineTest( )  {
        // cleanup any pending stuff, but no exceptions allowed
    }

    Vector<complex<double>> V;
    Matrix<complex<double>> M;
    CommandLineReader reader;

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

using CommandLineTestF1 = CommandLineTest<false,0>;
using CommandLineTestF2 = CommandLineTest<true,1>;
using CommandLineTestF3 = CommandLineTest<false,2>;
using CommandLineTestF4 = CommandLineTest<false,3>;

using FileReaderTestF1 = FileReaderTest<true>;
using FileReaderTestF2 = FileReaderTest<false>;

TEST_F(CommandLineTestF2,correct_complex_entries)
{
    vector<vector<complex<double>>> mat = {{3,(4,6)},{4,(5,1)}};
    mat[0][1] = complex<double>(4,6);
    mat[1][1] = complex<double>(5,1);
    vector<complex<double>> vec {3,(5,8)};
    vec[1] = complex<double>(5,8);
    cin.clear();

    reader.Read(M,V,2);
    EXPECT_EQ(M.getValue(),mat );
    EXPECT_EQ(V.getValue(), vec);
    cin.clear();

}

TEST_F(CommandLineTestF1, correct_real_entries)
{
    reader.Read(M,V,4);

    vector<vector<complex<double>>> mat = {{3,4,5,6},{4,5,6,7},{7,8,9,10},{2,3,4,5}};
    vector<complex<double>> vec = {3,4,5,6};
    EXPECT_EQ(M.getValue(),mat);
    EXPECT_EQ(V.getValue(), vec);
    cin.clear();
}

TEST_F(CommandLineTestF3, complex_entry_found)
{
    ASSERT_THROW(reader.Read(M,V,2), domain_error);

}

TEST_F(CommandLineTestF4, invalid_entries)
{
    ASSERT_THROW(reader.Read(M,V,2), length_error);
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
