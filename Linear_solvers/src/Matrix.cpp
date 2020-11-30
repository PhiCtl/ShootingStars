#include<iostream>
#include <exception>
#include <vector>
using namespace std;


//Template declaration class Matrix
template<typename T = double>
class Matrix{
private:
    int rows; //number of rows
    int cols; //number of columns
    vector<vector<T>> matrix; //matrix
public:
    Matrix(int r, int c, const T& value);
    //for default
    //Matrix(int r, int c, const T& value = 0.0);
    Matrix(int c, vector <T> vec);
    Matrix(vector<vector<T>> mat);
    //Copy constructor
    Matrix(const Matrix<T>& mat);
    //destructor
    virtual ~Matrix();

    //Read and write operator
    vector<T>& operator[](int i);
    //Read operator
    T operator()(int i, int j) const;

    //Operations between matrices
    Matrix<T>& operator=(const Matrix<T> &mat);
    Matrix<T> operator+(const Matrix<T> &mat);
    Matrix<T> operator*(const Matrix<T> &mat);
    Matrix<T> operator-(const Matrix<T> &mat);

    //Operation matrix/scalar
    Matrix<T> operator*(const T& value);

    //Return the transpose
    Matrix<T> transpose();
    //Return a lower triangular matrix
    Matrix<T> LowerTriangularMatrix();

    //Norm
    T norm(const vector<T>& vec);

    //Get rows size
    int getRows() const;
    //Get cols size
    int getCols() const;

    //Print the matrix
    void Print(std::ostream &s);
};


//Template definition class Matrix
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
        rows = r;
        cols = vec.size();
        matrix = matrix = vector<vector<T>>(r, vec);
    }


    /*
    cols = c;
    rows = vec.size();
    matrix = vector<vector<T>>(c, vec);
    *this = (*this).transpose();
    */
}

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

    if(mat.getRows() < 0 || mat.getCols() < 0) {
        throw invalid_argument("Error: negative dimension!");
    }

    if((rows != mat.getRows()) || (cols != mat.getCols())){
        throw invalid_argument("Error: incompatible dimension between matrices!");
    }


   /* if ((rows != mat.getRows()) || (cols != mat.getCols()) || (mat.getRows() < 0) || (mat.getCols() < 0) ){
        throw invalid_argument("Check the dimension!!");
    }else{
   */
        Matrix res(rows,cols,0.0);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                res[i][j] = this->matrix[i][j] + mat(i,j);
            }
        }
        return res;

}

//Subtraction of two matrices
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &mat) {
    Matrix res(rows,cols,0.0);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            res[i][j] = this->matrix[i][j] - mat(i,j);
        }
    }
    return res;
}

//Multiplication of this matrix and another
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &mat) {
    Matrix res(rows,cols,0.0);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            res[i][j] = this->matrix[i][j] * mat(i,j);
        }
    }
    return res;

}

// Assignment Operator

/*
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& mat){
    if(&mat == this)
        return *this;

    int new_rows = mat.getRows();
    int new_cols = mat.getCols();

    matrix.resize(new_rows);
    for(int i = 0; i < matrix.size(); i ++){
        matrix[i].resize(new_cols);
    }

    for(int i = 0; i < new_rows; i ++){
        for(int j = 0; j < new_cols; j++){
            matrix[i][j] = mat(i,j);
        }
    }
    rows = new_rows;
    cols = new_cols;

    return *this;
}
*/
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

//Try!!
template <typename T>
T Matrix<T>::norm(const vector<T>& vec){
    T norm_;
    auto add = [&norm_] (auto& el) {norm_ += pow(el,2);};
    for_each(vec.begin(), vec.end(),add);
    return sqrt(norm_);

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



int main(int argc, char * argv[]) {

    Matrix<int> mat1(4,4,2.0);
    mat1.Print(std::cout);

    std::cout << "\t" <<std::endl;
    int r = -4;
    int c = 4;
    try{
        Matrix<int> mat2(r,c,4);
        mat2.Print(std::cout);
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
    vector<vector<int>> mat = {{2,3,4},{5,6,7}};
    Matrix<int> mat8(mat);
    mat8.Print(std::cout);

    std::cout << "\t" <<std::endl;
    Matrix<int> mat9 = mat8.transpose();
    mat9.Print(std::cout);

    std::cout << "\t" <<std::endl;
    Matrix<int> mat10 = mat8.LowerTriangularMatrix();
    mat10.Print(std::cout);


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

