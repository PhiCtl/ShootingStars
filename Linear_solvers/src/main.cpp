#include "Vector.h"
#include "CommandLineReader.h"
#include "FileReader.h"
#include <Writer.h>

#include <Jacobi.h>
#include <Gauss_Seidel.h>
#include <Conjugate_Gradient.h>
#include <Richardson.h>
#include <LU.h>
#include <Cholesky.h>

#include <iostream>
#include <vector>
#include <string>
#include <tclap/CmdLine.h>
#include <tclap/ValuesConstraint.h>
#include <complex>

using namespace std;
enum{ Lu, cholesky, Conjugate_gradient, jacobi, GaussSeidel, richardson}; //enum type for solver type
template <typename T> LinearSolver<T>* Solver(int solver_type);

int main(int argc, char** argv)
{
    try{
        TCLAP::CmdLine cmd("Command description message", ' ');

        //constraints on solver names
        vector<int> allowed_solver = {Lu, cholesky, Conjugate_gradient, jacobi, GaussSeidel, richardson};
        TCLAP::ValuesConstraint<int> allowedSolv(allowed_solver);
        //constraints on data type
        /*vector<string> allowed_type = {"double","float", "long double"};
        TCLAP::ValuesConstraint<string> allowedTyp(allowed_type);*/

        //Value arguments
        TCLAP::SwitchArg readFromCmdl("C", "terminal", "Read matrix and vector from command line", cmd, false);
        TCLAP::ValueArg<string> fileMatArg("A", "matrix", "Name of the file storing matrix A", false, "Noname", "string");
        cmd.add(fileMatArg);
        TCLAP::ValueArg<string> fileVecArg("B", "vector", "Name of the file storing vector B", false, "Noname", "string");
        cmd.add(fileVecArg);
        TCLAP::ValueArg<string> fileOutArg("O", "out", "Name of the output file storing the solution", false, "Sol.mat", "string");
        cmd.add(fileOutArg);
        TCLAP::ValueArg<int> solverNameArg("S", "solver", "Method chosen to solve the linear system \n: 0:lu, 1:cholesky, 2: conjugate gradient, 3: jacobi, 4: gauss seidel, 5: richardson \n", true, Lu, &allowedSolv);
        cmd.add(solverNameArg);
        TCLAP::ValueArg<int> precisionArg("P", "precision", "significant digits of solution", false,20, "int");
        cmd.add(precisionArg);
        /*TCLAP::ValueArg<string> dataTypeArg("T", "type", "Data type to store entries", true, "double", &allowedTyp);
        cmd.add(dataTypeArg);*/

        TCLAP::ValueArg<int> matrixDimArg("D", "dimension", "Dimension of the square matrix", true, 3, "int");
        cmd.add(matrixDimArg);
        TCLAP::SwitchArg complexEntries("I", "complex", "Specify if there is any complex entry in the files", cmd, false);

        //parse
        cmd.parse(argc, argv);

        //get values
        int solver_type = solverNameArg.getValue();
        //string data_type = dataTypeArg.getValue();
        string output_file = fileOutArg.getValue();
        string M_file = fileMatArg.getValue();
        string b_file = fileVecArg.getValue();
        int dim = matrixDimArg.getValue();
        bool complex = complexEntries.getValue();
        bool readCmdl = readFromCmdl.getValue();
        int precision = precisionArg.getValue();

        //readers
        CommandLineReader reader1(complex);
        FileReader reader2(complex);
        Writer writer(output_file);

        //Compute solution and assign solver
        if (complex)
        {
            LinearSolver<std::complex<long double>>* solver(Solver<std::complex<long double>>(solver_type));
            Matrix<std::complex<long double>> A;
            Vector<std::complex<long double>> b;

            if(readCmdl)
                reader1.Read(A,b,dim);
            else{
                reader2.SetFiles(M_file, b_file);
                reader2.Read(A,b,dim);
            }
            auto Solution = solver->Solve(A,b);
            writer.Write(Solution, 10);
        }
        else{
            LinearSolver<long double>* solver(Solver<long double>(solver_type));
            Matrix<long double> A;
            Vector<long double> b;

            if(readCmdl)
                reader1.Read(A,b,dim);
            else {
                reader2.SetFiles(M_file, b_file);
                reader2.Read(A,b,dim);
            }

            auto Solution = solver->Solve(A,b);
            writer.Write(Solution, precision);
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

template <typename T> LinearSolver<T>* Solver(int solver_type)
{
    LinearSolver<T>* solver;
    switch(solver_type){
        case Lu:
            solver = new LU<T>;
            break;
        case cholesky:
            solver = new Cholesky<T>;
            break;
        case Conjugate_gradient:
            solver = new Conjugate_Gradient<T>;
            break;
        case jacobi:
            solver = new Jacobi<T>;
            break;
        case richardson:
            solver = new Richardson<T>;
            break;
        case GaussSeidel:
            solver = new Gauss_Seidel<T>;
            break;
        default:
            break;
    }
}