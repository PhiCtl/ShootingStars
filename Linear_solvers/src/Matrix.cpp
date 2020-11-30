#include<iostream>
#include <exception>
#include <vector>
#include <algorithm>
using namespace std;


//Template declaration class Matrix
template<typename T = double>
class Matrix{
protected:
    int rows; //number of rows
    int cols; //number of columns
    vector<vector<T>> matrix; //matrix
public:
    /*
     * Constructors:
     * -default constructor
     * -three parameters: number of rows, number of columns, and initial value of tzpe T
     * -one parameter: a vector of vector of type T
     * -two parameters: rows and a vector
     * -a copy constructor
    */
    Matrix();
    Matrix(int r, int c, const T& value);
    Matrix(int r, vector <T> vec);
    Matrix(vector<vector<T>> mat);
    Matrix(const Matrix<T>& mat);

    //Destructor
    virtual ~Matrix();

    //Read and write operator
    vector<T>& operator[](int i);
    //Read operator
    T operator()(int i, int j) const;

    /*
     * Operations between matrices:
     * -Equal operator
     * -Addition
     * -Subtraction
     * -Multiplication
    */
    virtual Matrix<T>& operator=(const Matrix<T> &mat);
    Matrix<T> operator+(const Matrix<T> &mat);
    Matrix<T> operator*(const Matrix<T> &mat);
    Matrix<T> operator-(const Matrix<T> &mat);

    //Multiplication between matrix and scalar
    Matrix<T> operator*(const T& value);

    //Return a transpose matrix
    Matrix<T> transpose();
    //Return a lower triangular matrix
    Matrix<T> LowerTriangularMatrix();
    //Return a upper triangular matrix
    Matrix<T> UpperTriangularMatrix();
    //Return a diagonal matrix (with the main diagonal)
    Matrix<T> DiagonalMatrix();


    //Get rows size
    int getRows() const;
    //Get cols size
    int getCols() const;
    //Get matrix value as a vector or vector of T
    vector<vector<T>> getValue() const;

    //Print the matrix
    void Print(std::ostream &s);
};


//Template definition class Matrix
//Default constructor
template<typename T>
Matrix<T>::Matrix(){
    rows = 0;
    cols = 0;

}
//Constructor with two parameters and an initialization value of type T
template<typename T>
Matrix<T>::Matrix(int r, int c, const T& value){
    if(r < 0 || c < 0){
        throw invalid_argument("Error: negative dimension!");
    } else {
        rows = r;
        cols = c;

        matrix.resize(rows);

        for (int i = 0; i < matrix.size(); i++){
            matrix[i].resize(cols,value);
        }
    }

}

//Constructor with the same vector for each column
template<typename T>
Matrix<T>::Matrix(int r, vector<T> vec){
    if(r < 0){
        throw invalid_argument("Error: negative dimension!");
    }else{
        cols = r;
        rows = vec.size();
        matrix.resize(rows);
        auto it = vec.begin();
        auto func = [&it, r] (vector<T>& vec) {
            vec.resize(r);
            for(auto& el: vec)
                el = *it;
            ++it;
        };
        for_each(matrix.begin(), matrix.end(), func);
    }

}

//Constructor with a vector of vector as argument
template<typename T>
Matrix<T>::Matrix(vector<vector<T>> mat){
    rows = mat.size();
    cols = mat[0].size();
    matrix = mat;
}

//Copy constructor
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& mat){
    matrix = mat.matrix;
    rows = mat.getRows();
    cols = mat.getCols();
}


template<typename T>
Matrix<T>::~Matrix() {};

template<typename T>
int Matrix<T>::getRows() const{
    return (*this).rows;
}

template<typename T>
int Matrix<T>::getCols() const{
    return (*this).cols;
}

template <typename T> vector<vector<T>> Matrix<T>::getValue() const {
    return matrix;
}

template<typename T>
vector<T>& Matrix<T>::operator[](int i){
    return matrix[i];
}

template<typename T>
T Matrix<T>::operator()(int i, int j) const{
    return matrix[i][j];
}

//Addition of two matrices
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &mat) {

    if((rows != mat.getRows()) || (cols != mat.getCols())){
        throw invalid_argument("Error: the matrices must have the same number of rows and columns.");
    }else{

        Matrix res(rows,cols,0.0);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                res[i][j] = this->matrix[i][j] + mat(i,j);
            }
        }
        return res;
    }
}

//Subtraction of two matrices
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &mat) {

    if((rows != mat.getRows()) || (cols != mat.getCols())){
        throw invalid_argument("Error: the matrices must have the same number of rows and columns.");
    }else{
        Matrix res(rows,cols,0.0);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                res[i][j] = this->matrix[i][j] - mat(i,j);
            }
        }
        return res;
    }
}

//Multiplication of this matrix and another
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &mat) {
    if(cols != mat.getRows()){
        throw invalid_argument("Error: for matrix multiplication, the number of columns in the first matrix must be equal to the number of rows in the second matrix. ");
    } else {

        Matrix res(rows,mat.getCols(),0.0);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < mat.getCols(); j++){
                for(int k = 0; k < cols; ++k)
                    res[i][j] += this->matrix[i][k] * mat(k,j);
            }
        }
        return res;
    }

}

// Assignment Operator
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& mat){

    rows = mat.getRows();
    cols = mat.getCols();

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = mat(i,j);
        }
    }
    return *this;
}


//Matrix/scalar multiplication
template<typename T>
Matrix<T> Matrix<T>::operator*(const T& value){
    Matrix res(rows,cols,0.0);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            res[i][j] = this->matrix[i][j] * value;
        }
    }
    return res;
}


//Transpose matrix
template<typename T>
Matrix<T> Matrix<T>::transpose(){
    Matrix mat_T(cols, rows, 0.0);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j)
            mat_T[j][i] = matrix[i][j];
    }
    return mat_T;
}

//Lower triangular matrix
template<typename T>
Matrix<T> Matrix<T>::LowerTriangularMatrix(){
    Matrix mat_lower(cols, rows, 0.0);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            if (i < j){
                mat_lower[i][j] = 0.0;
            }else{
                mat_lower[i][j] = matrix[i][j];
            }
        }
    }
    return mat_lower;
}

//Upper triangular matrix
template<typename T>
Matrix<T> Matrix<T>::UpperTriangularMatrix(){
    Matrix mat_upper(cols, rows, 0.0);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            if (i > j){
                mat_upper[i][j] = 0.0;
            }else{
                mat_upper[i][j] = matrix[i][j];
            }
        }
    }
    return mat_upper;
}

//Diagonal matrix
template<typename T>
Matrix<T> Matrix<T>::DiagonalMatrix(){
    Matrix mat_diagonal(cols, rows, 0.0);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; j++){
            if (i == j){
                mat_diagonal[i][j] = matrix[i][j];
            }else{
                mat_diagonal[i][j] = 0.0;
            }
        }
    }
    return mat_diagonal;
}

//Print the matrix
template<typename T>
void Matrix<T>::Print(std::ostream &s){
    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j++){
            s << matrix[i][j] << " ";
        }
        s << std::endl;
    }
}



/*int main(int argc, char * argv[]) {

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

}*/


