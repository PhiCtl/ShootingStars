#include <iostream>
#include "Vector.h"
#include "Reader.h"
#include <vector>
#include <string>
#include <tclap/CmdLine.h>
#include <tclap/ValuesConstraint.h>

using namespace std;

int main(int argc, char** argv)
{
    try{
        TCLAP::CmdLine cmd("Command description message", ' ');

        //constraints on solver names
        vector<string> allowed_solver = {"LU", "Cholesky", "Conjugate gradient", "Jacobi", "Gauss Seidel", "Richardson"};
        TCLAP::ValuesConstraint<string> allowedSolv(allowed_solver);

        //Value arguments
        TCLAP::SwitchArg readFromCmdl("C", "terminal", "Read matrix and vector from command line", cmd, true);
        TCLAP::ValueArg<string> fileMatArg("A", "matrix", "Name of the file storing matrix A", false, "Noname", "string");
        cmd.add(fileMatArg);
        TCLAP::ValueArg<string> fileVecArg("B", "vector", "Name of the file storing vector B", false, "Noname", "string");
        cmd.add(fileVecArg);
        TCLAP::ValueArg<string> fileOutArg("O", "out", "Name of the output file storing the solution", false, "Sol.mat", "string");
        cmd.add(fileOutArg);
        TCLAP::ValueArg<string> solverNameArg("S", "solver", "Method chosen to solve the linear system", true, "LU", &allowedSolv);
        cmd.add(solverNameArg);
        TCLAP::ValueArg<int> matrixDimArg("D", "dimension", "Dimension of the square matrix", true, 3, "int");
        cmd.add(matrixDimArg);
        TCLAP::SwitchArg PrecisionArg("T", "precision", "Whether the output needs to be highly precise", cmd, true);
        TCLAP::SwitchArg DataSizeArg("L", "large", "Whether the matrix/vector has large entries", cmd, false);
        TCLAP::SwitchArg complexEntries("I", "complex", "Specify if there is any complex entry in the files", cmd, false);

        //parse
        cmd.parse(argc, argv);

        //get values
        string solver = solverNameArg.getValue();
        string output_file = fileOutArg.getValue();
        string M_file = fileMatArg.getValue();
        string b_file = fileVecArg.getValue();
        int dim = matrixDimArg.getValue();
        bool complex = complexEntries.getValue();
        bool readCmdl = readFromCmdl.getValue();

        //test
        cout << solver << " " << output_file << " " << M_file << endl;
        cout << b_file << " " << dim <<" " << complex;

        if(readCmdl)
        {

        }

    }
    catch(TCLAP::ArgException &e)
    {
        cerr << "error: " << e.error() << " for arg " << e.argId() << endl;
    }
    catch(const runtime_error& e)
    {
        cerr <<"error: " << e.what() << endl;
    }
    return 0;
}