//
// Created by petronio@INTRANET.EPFL.CH on 26.11.20.
//
#include<iostream>
#include <exception>

//Template declaration class Matrix
template<typename T>
class Matrix{
private:
    int rows; //number of rows
    int cols; //number of columns
    T **matrix; //matrix
public:
    //Constructor
    Matrix();
    Matrix(int r, int c, const T& value);
    Matrix(int r, T* vec);
    //Copy Constructor
    Matrix(const Matrix<T>& mat);
    //Destructor
    virtual ~Matrix();

    //get the entry element i,j
    // GetEntry(int i, int j);
    //set the entry element i,j
    //void SetEntry(int i, int j, const T& value);

    int getRows() const;
    int getCols() const;

    //Operators
    //Matrix<T> operator*(const T& value);
    //Matrix<T> operator+(const Matrix<T> &mat);
    //Matrix<T> operator*(const Matrix<T> &mat);
    //Matrix<T> operator-(const Matrix<T> &mat);


    //Print the matrix
    void Print(std::ostream &s);

};

//Template definition class Matrix
//Default constructor
template<typename T>
Matrix<T>::Matrix() {
    rows = cols = 0;
    matrix = nullptr;
}

//Constructor with two parameters and an initialization value of type T
template<typename T>
Matrix<T>::Matrix(int r, int c, const T& value){
    rows = r;
    cols = c;

    matrix = new T*[rows];

    for(int i = 0; i < rows; i++){
        matrix[i] = new T[cols];
    }

    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = value;
        }
    }
}
//Constructor with the same vector for each column
template<typename T>
Matrix<T>::Matrix(int r, T* vec){
    rows = r;
    for(int i = 0; i < rows; i++){
        matrix[i] = vec;
    }

}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& mat){

}

//Destructor
template<typename T>
Matrix<T>::~Matrix(){
    for(int i = 0; i < rows; i++){
        delete [] matrix[i];
    }
    delete [] matrix;

}

template<typename T>
int Matrix<T>::getRows() const{
    return (*this).rows;
}

template<typename T>
int Matrix<T>::getCols() const{
    return (*this).cols;
}

/*
//Constructor with the same vector for each column
template<typename T>
Matrix<T>::Matrix(int r, T* vec){
    rows = r;

    matrix = new T*[cols];
}

//Destructor
template<typename T>
Matrix<T>::~Matrix(){
    for(int i = 0; i < rows; i++){
        delete [] matrix[i];
    }
    delete [] matrix;

}

/*
template<typename T>
T Matrix<T>::GetEntry(int i, int j) {
    //if((rows > 0) && (cols > 0)){
        return matrix[i][j];
    /*} else {
        throw std::invalid_argument("Dimension of the matrix unacceptable");
    }
     */


/*
template<typename T>
void Matrix<T>::SetEntry(int i, int j, const T& value){
    //ask if it is correct how used the exception
    //if((i<0) || (i >= rows) || (j < 0) || (j >= cols) ){
       // throw std::invalid_argument("ERROR: check i and j values");
   // }else{
    matrix[i][j] = value;
    //}
}

template<typename T>
int Matrix<T>::getRows() const{
    return (*this).rows;
}

template<typename T>
int Matrix<T>::getCols() const{
    return (*this).cols;
}

// = operator
template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &mat){
    assert(matrix != nullptr);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = mat.GetEntry(i,j);
        }
    }
    return *this;
}


template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &mat) {
    Matrix res;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            res.SetEntry(i,j, matrix[i][j] + res.GetEntry(i,j));
        }
    }
    return res;
}


//Matrix/scalar product
template<typename T>
Matrix<T> Matrix<T>::operator*(const T& value){
    Matrix res;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            res.SetEntry(i,j,matrix[i][j]*value);
        }
    }
    return res;
}
*/

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

    Matrix<int> mat1(10,10,3.0);
    mat1.Print(std::cout);

    std::cout << "\t" <<std::endl;

    Matrix<double> mat2(4,4,{2.9,3.8,4.0,5.2});
    mat2.Print(std::cout);
    /*int i,j;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            mat2.SetEntry(i,j,i+j);
        }
    }
     */
    //std::cout << "\t" <<std::endl;
    //mat2.Print(std::cout);

    //std::cout << "\t" <<std::endl;
    //int d = 4;
    //Matrix<int> mat3 = mat2 + mat2;
    //mat3.Print(std::cout);

    return 0;

}

