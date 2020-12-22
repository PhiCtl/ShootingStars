//
// Created by descourt@INTRANET.EPFL.CH on 05.12.20.
//

#ifndef LINEAR_SOLVERS_COMMANDLINEREADER_H
#define LINEAR_SOLVERS_COMMANDLINEREADER_H
#include "Reader.h"

/*! @brief Reader of Matrices and Vectors from files
 */
class CommandLineReader: public  Reader
{
public:
    /*! @brief Constructor
     * @param b: boolean indicating if there is any complex entry in the files
     */
    CommandLineReader(bool b);

    /*! @brief Read
     * @tparam T : same type as matrix and vector
     * @param Mat: an empty matrix
     * @param Vec: an empty vector
     * @param dim: (int) dimensions of (square) matrix and vector
     */
    template<typename T> void Read(Matrix<T>& Mat, Vector<T>& Vec, int dim);


};

//Read
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
