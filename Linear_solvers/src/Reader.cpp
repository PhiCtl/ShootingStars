//
// Created by descourt@INTRANET.EPFL.CH on 30.11.20.
//
#include "Reader.h"
using namespace std;

Reader::Reader(bool complex):complex_entries(complex){};
Reader::~Reader() {};

bool Reader::found_complex(string s) {
    return ((s.find('i') != string::npos) or(s.find('(') != string::npos));
}




