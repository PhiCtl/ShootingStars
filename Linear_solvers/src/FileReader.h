
#ifndef LINEAR_SOLVERS_FILEREADER_H
#define LINEAR_SOLVERS_FILEREADER_H

#include "Reader.h"
/*! @brief Reader from file
 */

class FileReader: public Reader{
public:

    /*! @brief Constructor
     *
     * @param fileA : file (string name of relative path) containing matrix A
     * @param fileB : file (string name of relative path) containing matrix B
     * @param complex : boolean indicating if there is any complex entry in either file
     */
    FileReader(string fileA, string fileB, bool complex);

    /*! @brief Constructor
     *
     * @param complex: boolean to indicate if there is any complex entry in the files
     */
    FileReader(bool complex);

    /*! @brief Constructor (default)
     */
    FileReader();

    /*! @brief Read
     *
     * @tparam T
     * @param Mat: Matrix to store matrix data from file
     * @param Vec: Vector to store vector data from file
     * @param dim: dimensions of (square) matrix and vector
     */
    template <typename T> void Read(Matrix<T>& Mat, Vector<T>& Vec, int dim);

    /*! @brief Copy constructor
     * @param reader: another FileReader of same type T
     */
    FileReader(const FileReader& reader);

    /*! @brief Destructor
     *
     */
    ~FileReader() {};

    /*! @brief SetFiles: set files path
     *
     * @param fileA: (string) relative path of file storing matrix A
     * @param fileB: (string) relative path of file storing vector B
     */
    void SetFiles(string fileA, string fileB);

private:
    /** @brief fileA: string name of file storing matrix A */
    string fileA;

    /** @brief fileB: string name of file storing vector B */
    string fileB;
};


template <typename T> void FileReader::Read(Matrix<T>& M, Vector<T>& b, int n) {
    ifstream read_A(fileA.c_str());
    ifstream read_b(fileB.c_str());

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
