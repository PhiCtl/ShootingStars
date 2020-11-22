//
// Created by descourt@INTRANET.EPFL.CH on 20.11.20.
//

#ifndef LINEAR_SOLVERS_UTILS_H
#define LINEAR_SOLVERS_UTILS_H

#include "Matrix.hpp" //let's imagine Vector is a daughter class of Matrix
#include "ComplexNumber.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace  std;

typedef  vector<ComplexNumber> vec;

namespace utilities
{
    //convert a string of the form '+/- a +/- ib' into complex /or real number
    ComplexNumber  converter(string entry){
        int plusPos, minusPos, i_Pos;
        bool real, imag;
        plusPos = entry.find('+');
        minusPos = entry.find('-');
        i_Pos = entry.find('i');
        real = (i_Pos < 0); //if i_Pos is negative, it means that number is real
        imag = minusPos <0 && plusPos <0;

        //number is either real, imaginary, or complex
        if(real)
            return ComplexNumber(stod(entry),0.0);
        if(imag){
            int sign = -2*(minusPos < 0) +1; //recover the sign
            return ComplexNumber(0.0, sign* stod(entry.substr(0, i_Pos)));
        }

        //recover sign of imaginary part
        int sign(-1);
        if(plusPos > 0)
            sign = 1;
        return ComplexNumber(stod(entry.substr(0,i_Pos-2)), sign* stod(entry.substr(i_Pos +1, entry.size() - 1)));

    }


    void Read(string A_file, string b_file, Matrix& mat, Vector& b){
        ifstream read_A(A_file.c_str());
        ifstream read_b(b_file.c_str());

        //check if files can be opened
        if(!read_A.is_open())
        {
             throw runtime_error("File '" + A_file+ "' cannot be open. Enter name again:");
        }
        if(!read_b.is_open())
        {
            throw runtime_error("File '" + b_file+ "' cannot be open. Enter name again:");
        }

        //should matrix and vector sizes be specified ?
        int n(0); //rows
        int m(0); //columns
        //yes ?
        read_A >> n >> m;

        //read from matrix file
        string line;
        while(getline(read_A,line))
        {
            assert(line.size() != m);
            istringstream iss(line);
            string tp;
            vec V1;
            while(iss  >> tp)
            {
               V1.push_back(converter(tp));
            }
        mat.push_back(V1);
        }
        assert(mat.size() != n);
        read_A.close();

        //read from vector file (one single line off valuees)
        getline(read_b, line);
        istringstream iss(line);
        string tp;
        while(iss >> tp)
        {
            b.push_back(converter(tp));
        }
        assert(b.size() != m);
        read_b.close();

    }
    void Read(Matrix& mat, Vector& b)
    {
        int n(0);
        int m(0);
        cout << "Enter expected matrix and vector sizes, space separated:" << endl;
        cin >> n >> m;
        string temp;

        cout << "Enter matrix entries :" << endl;
        for(int i = 0; i < n; ++i)
        {
            vec V(m);
            for (auto& el: V)
            {
                cin >> temp;
                V.push_back(converter(temp));
            }
            mat.push_back(V);
        }

        cout << "Enter vector entries : " << endl;
        for(int i = 0; i < m; ++i)
        {
            cin >> temp;
            b.push_back(converter(temp));
        }

    }
    //write to file OK
    void Write(string file, const Vector& x)
    {
        ofstream out(file);
        if(!out.is_open())
        {
            throw runtime_error("Invalid file name for output file. Enter new one: ");
        }
        for_each(x.begin(), x.end(), [&out] (const ComplexNumber& v) {
            out << scientific << setprecision(10);
            out << v << endl;}
            )

    }
}

#endif //LINEAR_SOLVERS_UTILS_H
