//
// Created by descourt@INTRANET.EPFL.CH on 30.11.20.
//
#include "Reader.h"
using namespace std;

Reader::Reader(bool complex, bool large, bool precis):complex_entries(complex), large_entries(large), precision(precis) {};
Reader::~Reader() {};

bool Reader::found_complex(string s) {
    return ((s.find('i') != string::npos) or(s.find('(') != string::npos));
}




