
#include "FileReader.h"
FileReader::FileReader(string matfile, string vecfile, bool complex):Reader(complex) {
    fileA = matfile;
    fileB = vecfile ;
}

FileReader::FileReader( bool complex):Reader(complex) {}

FileReader::FileReader():Reader(false) {}

FileReader::FileReader(const FileReader& f):Reader(f.complex_entries) {
    fileA = f.fileA;
    fileB = f.fileB;
}
void FileReader::SetFiles(string f1, string f2) {
    fileA = f1;
    fileB = f2;
}