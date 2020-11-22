#include <iostream>
#include "Utils.h"
#include "Matrix.hpp"
#include <vector>

using namespace utilities;


//use should provide in right order: (program_name), wanted method,
//if more : 2 files with A and B matrices, output name: default Sol.dat
int main(int argc, char* argv[]) {

    Matrix M;
    Vector b;
    string operation;
    string output_file = "Solution.dat";
    string M_file;
    string b_file;
    bool again = true;
    vector<string> allowed_operations = {};
    //have a list of allowed operations and check if operation belongs to it
    //otherwise ask user again -> error handling

    //read part
    while (again) {}

    switch (argc) {
        case 1: //only program name provided
            cerr << "Error: Only program name provided. Please enter options again:" << endl;
            break;
        case 2: //only program name and type of operation
            Read(M, b);
            //check if operation supported
            break;
        case 3: //program name, operation type and 1 file were given
            break;
        case 4: //same, 2 files given
            try { Read(argv[2], argv[3], M, b); }
            catch (const runtime_error &e) {
                cerr << e.what() << endl; //couldn't open files
                cout << "Enter file name for matrix A:" << endl;
                cin >> M_file;
                cout << "Enter file name for vector b:" << endl;
                cin >> b_file;
                Read(M_file, b_file, M, b);
                again = false;
            }
            again = false;
            break;
        default: //ask user info again
            break;
    }

}

    //computation part
    Vector x;
    //write part
    Write(output_file, x);


    return 0;
}
