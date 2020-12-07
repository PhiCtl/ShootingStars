//
// Created by descourt@INTRANET.EPFL.CH on 05.12.20.
//

#include "FileReader.h"
FileReader::FileReader(string matfile, string vecfile, bool complex):Reader(complex) {
    fileA = matfile;
    fileB = vecfile ;
}
