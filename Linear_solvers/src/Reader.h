//
// Created by descourt@INTRANET.EPFL.CH on 04.12.20.
//

#ifndef LINEAR_SOLVERS_READER_H
#define LINEAR_SOLVERS_READER_H
#include <string>
#include <iostream>
#include <complex>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <vector>
#include "Matrix.h"
#include "Vector.h"

using namespace  std;

class Reader{
public:
    Reader(bool, bool, bool);
    ~Reader();
    template< typename T> void Matrix_Reader(Matrix<T>&, istream&, int);
    template <typename T> void Vector_Reader(Vector<T>&, istream&, int);
    bool found_complex(string);
    //template <typename T> complex<T> Converter(string);

protected:
    bool complex_entries;
    bool large_entries;
    bool precision;
};

template <typename T> void Reader::Matrix_Reader(Matrix<T> & M, istream & is, int dim) {
    string line;
    vector<vector<T>> mat;
    size_t count(0);

    while(getline(is,line) && (count < dim) )
    {
        if(found_complex(line) && !complex_entries)
            throw domain_error("Complex entries found while expecting only real entries.");

        istringstream iss(line);
        T tp; //deal with complex entries: a+ib vs (a,b) ?
        vector<T> V1;
        while(iss  >> tp)
        {
            V1.push_back(tp);
        }
        if(V1.size() != dim)
            throw length_error("Incorrect dimensions provided for matrix rows.");
        mat.push_back(V1);

        ++count;
    }
    if (mat.size() != dim)
        throw length_error("Incorrect  dimensions provided for matrix columns.");
    M = mat;
}

template<typename T> void Reader::Vector_Reader(Vector<T> & b, istream & is, int dim) {

    T el;
    vector<T> vec;
    size_t count(0);
    while((is >> el) && (count <dim))
    {
        string check(to_string(el));
        if(found_complex(check) && !complex_entries)
            throw domain_error("Complex entries found while expecting only real entries.");
        vec.push_back(el);
        ++count;
    }
    if(vec.size() != dim)
        throw length_error("Incorrect dimensions provided for vector rows.");
    b = vec;
}

#endif //LINEAR_SOLVERS_READER_H
