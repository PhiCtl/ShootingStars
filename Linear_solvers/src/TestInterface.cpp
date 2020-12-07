//
// Created by descourt@INTRANET.EPFL.CH on 04.12.20.
//
#include "Writer.h"
#include <vector>
#include "CommandLineReader.h"
#include "FileReader.h"
#include "Matrix.h"
#include "Vector.h"

int main()
{
    /*vector<complex<double>> vec = {1.3, 4.6789, 0.000008, 4};
    Vector<complex<double>> V(vec);
    Matrix<complex<double>> M;
    Writer W;
    W.Write<double>(vec, 6);*/

    /*CommandLineReader reader(true);
    reader.Read(M,V,4);
    V.Print(cout);
    M.Print(cout);*/

    Vector<double> V;
    Matrix<double> M;
    FileReader F("../data/Mat.mat", "../data/Vec.mat", false);
    F.Read(M,V,4);
    M.Print(cout);
    V.Print(cout);

    return 0;
}

