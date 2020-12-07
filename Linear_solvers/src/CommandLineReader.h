//
// Created by descourt@INTRANET.EPFL.CH on 05.12.20.
//

#ifndef LINEAR_SOLVERS_COMMANDLINEREADER_H
#define LINEAR_SOLVERS_COMMANDLINEREADER_H
#include "Reader.h"

class CommandLineReader: public  Reader
{
public:
    CommandLineReader(bool);
    template<typename T> void Read(Matrix<T>&, Vector<T>&, int);


};

template <typename T> void CommandLineReader::Read(Matrix<T>& A, Vector<T>& b, int dim) {
    try{
        cout << "Enter matrix entries, row by row (separated by linespaces) :" << endl;
        this->Matrix_Reader(A, cin, dim);
        cout << "Enter vector entries element-wise (separated by linespaces):" << endl;
        this->Vector_Reader(b, cin, dim);
        cout << "Matrix and Vector correctly stored !" << endl;
    }
    catch(const runtime_error& e)
    {
        throw e;
    }
    catch(const domain_error& e)
    {
        throw e;
    }
    catch(const length_error& e)
    {
         throw e;
    }

}

#endif //LINEAR_SOLVERS_COMMANDLINEREADER_H
