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

/*! @brief Reader class : generic reader class from any istream
 *
 */
class Reader{
public:

    /*! @brief Constructor
     *
     * @param complex : boolean if there is any complex entry in the istream
     */
    Reader(bool complex);

    /*! @brief Destructor
     *
     */
    ~Reader();

    /*! @brief Matrix_Reader: read a matrix from stream f
     *
     * @tparam T
     * @param A : Matrix to store the data
     * @param f : istream input
     * @param dim : dimensions of the matrix
     */
    template< typename T> void Matrix_Reader(Matrix<T>& A, istream& f, int dim);

    /*! @brief Vector_Reader
     *
     * @tparam T
     * @param b: Vector to store data
     * @param f: istream input
     * @param dim : dimensions of the vector
     */
    template <typename T> void Vector_Reader(Vector<T>& b, istream& f, int dim);

    /*! @brief found_complex
     *
     * @param input: string line from input stream
     * @return if there is any complex entry in the input
     */
    bool found_complex(string input);

protected:
    /** @brief complex_entries: if there are any complex entries in the input */
    bool complex_entries;

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
        T tp; //deal with complex entries:(a,b) ?
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

    string line;

    T el;
    vector<T> vec;
    size_t count(0);
    is >> el;
    while(getline(is, line) && count < dim)
    {
        istringstream iss(line);
        iss >> el;
        if(found_complex(line) && !complex_entries)
            throw domain_error("Complex entries found while expecting only real entries.");
        vec.push_back(el);
        ++count;
    }
    if(vec.size() != dim)
        throw length_error("Incorrect dimensions provided for vector rows.");
    b = vec;
}

#endif //LINEAR_SOLVERS_READER_H
