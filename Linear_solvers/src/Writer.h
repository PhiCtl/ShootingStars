//
// Created by descourt@INTRANET.EPFL.CH on 04.12.20.
//

#ifndef LINEAR_SOLVERS_WRITER_H
#define LINEAR_SOLVERS_WRITER_H
#include <string>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Vector.h"
using namespace std;

/*! @brief Writer class: write Vector to file
 *
 */
class Writer{
public:

    /*! @brief Constructor
     *
     * @param fileout : string name of relative path to output file
     */
    Writer(string fileout);

    /*! @brief Constructor (default)
     *
     */
    Writer();

    /*! @brief Destructor
     *
     */
    ~Writer();

    /*! @brief Write
     *
     * @tparam T
     * @param vec : Vector to write in a file
     * @param precision : int precision of output
     */
    template <typename T> void Write(const Vector<T>& vec, int precision);


private:
    /** @brief file_out: name of output file */
    string file_out = "Sol.mat";

};

//Write
template <typename T> void Writer::Write(const Vector<T>& vec, int precision){
    ofstream out("../Solution/"+file_out);
    bool doAgain(true);

    while(doAgain){
        if(!out.is_open())
        {
            cerr << "Invalid file name for output file. Enter new one: ";
            cin >> file_out;
        }
        else {
            doAgain = false;
        }
    }

    vector<T> x = vec.getValue();

    for_each(x.begin(), x.end(), [&out, precision] (const T& v) {
        out << scientific << setprecision(precision);
        out << v << endl;}
    );
    out.close();
    cout << "Solution saved to file " + file_out << endl;
}


#endif //LINEAR_SOLVERS_WRITER_H
