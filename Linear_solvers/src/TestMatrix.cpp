//
// Created by descourt@INTRANET.EPFL.CH on 02.12.20.
//
#include "Matrix.cpp"

int main(int argc, char * argv[]) {

    Matrix<int> mat1(4,4,2.0);
    mat1.Print(std::cout);

    std::cout << "\t" <<std::endl;
    int r = 4;
    int c = 4;
    try{
        Matrix<int> mat2(r,c,4);
        mat2.Print(std::cout);
        std::cout << "\t" <<std::endl;
        Matrix<int> mat3(4,4,2.0);
        std::cout << "Addition matrix:"<< "\n";
        Matrix<int> mat4 = mat2 + mat3;
        mat4.Print(std::cout);
        std::cout << "\t" <<std::endl;
        Matrix<int> mat5(4,5,3);
        std::cout << "Multiplication matrix:"<< "\n";
        Matrix<int> mat6 = mat2 * mat5;
        mat5.Print(std::cout);
        std::cout << "\t" <<std::endl;
    } catch (const char* msg) {
        std::cerr<< msg << endl;
    }


    std::cout << "Rows size: " << mat1.getRows() << "\n";
    std::cout << "Cols size: " << mat1.getCols() << "\n";
    std::cout << "Entry: " << mat1[3][3] << "\n";

    Matrix<int> mat3 = mat1 + mat1;
    mat3.Print(std::cout);
    std::cout << "\t" <<std::endl;

    vector<double> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    std::cout << "The vector v is: " << " ";
    for(int i = 0; i < v.size(); i ++){
        std::cout << v[i] << " ";
    }
    std::cout << "\t" <<std::endl;
    Matrix<double> mat4(4, v);
    mat4.Print(std::cout);

    std::cout << "\t" <<std::endl;
    std::cout << "The norm:"<< "\n";
    norm(v);



    std::cout << "\t" <<std::endl;
    vector<vector<int>> mat = {{2,3,4},{5,6,7}};
    Matrix<int> mat8(mat);
    mat8.Print(std::cout);

    std::cout << "\t" <<std::endl;
    Matrix<int> mat9 = mat8.transpose();
    mat9.Print(std::cout);


    std::cout << "\t" <<std::endl;
    std::cout << "Lower Triangular Matrix matrix:"<< "\n";
    Matrix<int> mat10 = mat1.LowerTriangularMatrix();
    mat10.Print(std::cout);

    std::cout << "\t" <<std::endl;
    std::cout << "Upper Triangular Matrix:"<< "\n";
    Matrix<int> mat11 = mat1.UpperTriangularMatrix();
    mat11.Print(std::cout);

    std::cout << "\t" <<std::endl;
    std::cout << "Diagonal Matrix:"<< "\n";
    Matrix<int> mat12 = mat1.DiagonalMatrix();
    mat12.Print(std::cout);

    //std::cout << "\t" <<std::endl;
    //mat2.Print(std::cout);

    std::cout << "\t" <<std::endl;

    Matrix<int> mat5 = mat1;
    mat5.Print(std::cout);

    std::cout << "\t" <<std::endl;
    int d = 4;
    Matrix<int> mat6 = mat1 * d;
    mat6.Print(std::cout);

    std::cout << "\t" <<std::endl;
    Matrix<int> mat7 = mat1.transpose();
    mat7.Print(std::cout);


    return 0;

}
