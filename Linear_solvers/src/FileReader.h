//
// Created by descourt@INTRANET.EPFL.CH on 05.12.20.
//

#ifndef LINEAR_SOLVERS_FILEREADER_H
#define LINEAR_SOLVERS_FILEREADER_H

#include "Reader.h"

class FileReader: public Reader{
public:
    FileReader(string, string, bool);
    FileReader(bool);
    FileReader();
    template <typename T> void Read(Matrix<T>&, Vector<T>&, int);
    FileReader(const FileReader&);
    ~FileReader() {};

    void SetFiles(string, string);

private:
    string fileA;
    string fileB;
};


template <typename T> void FileReader::Read(Matrix<T>& M, Vector<T>& b, int n) {
    ifstream read_A(fileA.c_str());
    ifstream read_b(fileB.c_str());
    //check if files can be opened
    if(!read_A.is_open())
    {
        throw runtime_error("File '" + fileA+ "' cannot be open.");
    }
    if(!read_b.is_open())
    {
        throw runtime_error("File '" + fileB+ "' cannot be open.");
    }

    try {
        this->Matrix_Reader(M, read_A,n);
        read_A.close();
        this->Vector_Reader(b, read_b, n);
        read_b.close();
    }
    catch(const domain_error& e)
    {
        throw e;
    }
    catch(const runtime_error& e)
    {
        throw e;
    }
    catch(const length_error& e)
    {
        throw e;
    }
}
#endif //LINEAR_SOLVERS_FILEREADER_H
