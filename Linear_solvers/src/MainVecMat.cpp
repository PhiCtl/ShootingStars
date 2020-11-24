//
// Created by petronio@INTRANET.EPFL.CH on 24.11.20.
//

#include <iostream>
#include <exception>

//Template declaration class Vector
template<typename T>
class Vector{
private:
    int dim; //size of the vector
    T* vec;
public:
    //Constructor
    Vector(int d);
    Vector(int d, const T& initial);
    //Destructor
    virtual ~Vector();

    //Operator return element of the vector
    T& operator[](const int& i);

    //Operations between vectors
    Vector<T> operator+(Vector<T>& vec_rhs);
    Vector<T> operator-(Vector<T>& vec_rhs);
    Vector<T> operator*(Vector<T>& vec_rhs);
    Vector<T> operator*(T& s_rhs);

    void Print(std::ostream &s);

};


//Template definition class Vector
//Constructor
template<typename T>
Vector<T>::Vector(int d){
    if(d > 0){
        dim = d;
        vec = new T[dim];
    } else {
        throw std::invalid_argument("Size vector not acceptable");
    }

}

//Construction with initialization
template<typename T>
Vector<T>::Vector(int d, const T& initial) {
    if(d > 0){
        dim = d;
        vec = new T[dim];
        for(int i = 0; i < dim; i++){
            vec[i] = initial;
        }
    } else {
        throw std::invalid_argument("Size vector not acceptable");
    }

}

//Deconstructor
template<typename T>
Vector<T>::~Vector(){
    delete [] vec;
}

//Operator to access an element in a vector
template<typename T>
T& Vector<T>::operator[](const int& i) {
    return vec[i];
}

//Addition between vectors
template<typename T>
Vector<T> Vector<T>::operator+(Vector<T> &vec_rhs) {
    Vector output(dim, 0.0);

    for(int i = 0; i < dim; i ++){
        output[i] = (*this).vec[i] + vec_rhs[i];
    }

    return output;
}

//Subtraction between vectors
template<typename T>
Vector<T> Vector<T>::operator-(Vector<T> &vec_rhs) {
    Vector output(dim, 0.0);

    for(int i = 0; i < dim; i ++){
        output[i] = (*this).vec[i] - vec_rhs[i];
    }

    return output;
}

//Multiplication between vectors
template<typename T>
Vector<T> Vector<T>::operator*(Vector<T> &vec_rhs) {
    Vector output(dim, 0.0);

    for(int i = 0; i < dim; i ++){
        output[i] = (*this).vec[i] * vec_rhs[i];
    }

    return output;
}


template<typename T>
Vector<T> Vector<T>::operator*(T &s_rhs) {
    Vector output(dim, 0.0);

    for(int i = 0; i < dim; i ++){
        output[i] = (*this).vec[i] * s_rhs;
    }

    return output;
}

//Print a vector
template<typename T>
void Vector<T>::Print(std::ostream &s){
    for(int i = 0; i < dim; i++){
        s << vec[i] << " ";
    }
    s << std::endl;
}

//Template declaration class Matrix
template<typename T>
class Matrix{
private:
   int rows;
   int cols;
   Vector<T>* mat;
public:
    //Constructor
    Matrix(int r, int c, Vector<T>& v, T& initial);
    //Destructor
    ~Matrix();

    //Print the matrix
    void Print(std::ostream &s);

};

//Template definition class Matrix
template<typename T>
Matrix<T>::Matrix(int r, int c, Vector<T>& v, T& initial){
    rows = r;
    cols = c;
    //Allocate memory for matrix
    mat = (Vector<T>*) new Vector<T>[r];

    for(int i = 0; i < cols; i++){
        mat[i] = (Vector<T>)new Vector<T>[cols];
    }

    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols, j++){
            mat[i][j] = initial;
        }
    }

}

//Destructor
template<typename T>
Matrix<T>::~Matrix(){
    if(cols > 0){
        for(int i = 0; i < rows; i ++){
            delete[] mat[i];
        }
    }
    if(rows > 0){
        delete[] mat;
    }
}



//Print the matrix
template<typename T>
void Matrix<T>::Print(std::ostream &s){
    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j++){
            s << mat[i][j] << " ";
        }
        s << std::endl;
    }
}

int main(int argc, char * argv[]) {
    int n;
    int s = 9.4;
    std::cout << "Enter size of vector \n";
    std::cin >> n;
    Vector<int> v(n);
    Vector<int> v1(n, 5.4);
    std::cout << "Enter the component of vector v \n";
    for(int i = 0; i < n; i ++){
        std::cin >> v[i];
    }

    std::cout << "The vector v is \n";
    //for(int i = 0; i < n; i ++){
    //   std::cout << v[i] << "\n";
    //}
    v.Print(std::cout);

    std::cout << "The vector v1 is \n";
    v1.Print(std::cout);
    //for(int i = 0; i < n; i ++){
      //  std::cout << v1[i] << "\n";
    //}

    Vector<int> v2 = v - v1;
    std::cout << "The subtraction vector is \n";
    v2.Print(std::cout);
    //for(int i = 0; i < n; i ++){
     //   std::cout << v2[i] << "\n";
    //}

    Vector<int> v3 = v1 * s;
    std::cout << "The prod vector v1 and scalar is \n";
    v3.Print(std::cout);

    Matrix<int> mat1(n,n,v1,0.0);
    mat1.Print(std::cout);
    return 0;

}

