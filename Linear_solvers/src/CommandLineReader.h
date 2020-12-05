//
// Created by descourt@INTRANET.EPFL.CH on 05.12.20.
//

#ifndef LINEAR_SOLVERS_COMMANDLINEREADER_H
#define LINEAR_SOLVERS_COMMANDLINEREADER_H
#include "Reader.h"

class CommandLineReader: public  Reader
{
public:
    CommandLineReader(bool, bool, bool);
    template<typename T> void Read(Matrix<T>&, Vector<T>&, int);


};

template <typename T> void CommandLineReader::Read(Matrix<T>& A, Vector<T>& b, int dim) {
    cout << "Enter matrix entries, row by row (separated by linespaces) :" << endl;
    this->Matrix_Reader(A, cin, dim);
    cout << "Enter vector entries element-wise (separated by linespaces):" << endl;
    this->Vector_Reader(b, cin, dim);
}

#endif //LINEAR_SOLVERS_COMMANDLINEREADER_H
