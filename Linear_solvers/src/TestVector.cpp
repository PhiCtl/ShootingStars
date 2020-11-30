//
// Created by descourt@INTRANET.EPFL.CH on 30.11.20.
//
#include <iostream>
#include "Vector.cpp"
#include <stdexcept>

int main()
{
    Vector<double> vec;
    //vec.Print(cout);
    Vector<double> vec0(9);
    //vec0.Print(cout);

    Vector<double> vec1(3,5.5);
    //vec1.Print(cout);

    Vector<double> vec2(4, {4,0,5,7,9});
    //vec2.Print(cout);
    //std::cout << vec2.getCols() << " " << vec2.getRows() << std::endl;

    Vector<double> vec3 = vector<double>(3,4.7);
    //vec3.Print(cout);

    Vector<double> vec4(vec1);
    //vec4.Print(cout);

    //cout << vec4[0] << endl;
    //cout << vec4[9] << endl;
    //cout << vec4(2) << vec4(8) << endl;

    //cout << vec4.norm();
    vec4.Push_back(7);
    //vec4.Print(cout);

    Vector<double> vec5(1,9);
    Vector<double> vec6(1,3);
    //cout << vec5/vec6 << endl ;

    Vector<double> vec7 = vec6;
    //vec7.Print(cout);
    vec6.Push_back(8);
    //vec7.Print(cout);

    try{
        vector<double> v = {1,2,3};
        vector<double> v2 = {9,0,5};
        Vector<double> vec8 = v;
        //vec8.Print(cout);
        Matrix<double> Mat1 = vector<vector<double>>(3,v2);
        //Mat1.Print(cout);
        Vector<double> res = Mat1*vec8;
        //res.Print(cout);
        //cout << res[0];

        Matrix<double> Mat2 = vector<vector<double>>(1,v2);
        //Vector<int> vec9(Mat2);
        Matrix<double> Mat3(1,v2);
        Vector<double> vec9(Mat3);
        //vec9.Print(cout);

        Vector<double> vec10 = v2;
        Vector<double> vec11 = v;
        //vec11.Print(cout);
        //cout << vec10*vec11 << endl;
        //vec10.Push_back(67);
        //cout << vec10*vec11;
        Vector<double> vec12 = vec10;
        //vec12.Print(cout);

        Vector<double> vec13 = vec11 - Mat1*vec8;
        //vec13.Print(cout);

        Matrix<double> I(Identity<double>(3));
        I.Print(cout);
    }
    catch( const invalid_argument& e) { cerr << e.what(); }
    catch(const runtime_error& e) { cerr << e.what(); }


    return 0;
}

