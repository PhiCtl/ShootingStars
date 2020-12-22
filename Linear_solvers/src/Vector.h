//
// Created by descourt@INTRANET.EPFL.CH on 30.11.20.
//

#ifndef LINEAR_SOLVERS_VECTOR_H
#define LINEAR_SOLVERS_VECTOR_H
#include "Matrix.h"
#include <cmath>

/*! @brief Vector class: daughter class of Matrix
 *
 * @tparam T
 */
template <typename T = double> class Vector: public Matrix<T>{
public:
    //constructors
    /*! @brief Constructor (default)
     *
     */
    Vector();

    /*! @brief Constructor
     *
     * @param n : number of rows
     * @param el : value for each entry
     */
    Vector(int n, T el= 0.0);

    /*! @brief Constructor (redundant)
     *
     * @param n : number of rows
     * @param vec : (STL vector<T>) value for each entry
     */
    Vector(int n, vector<T> vec);

    /*! @brief Constructor
     *
     * @param vec : a STL vector of same type T
     */
    Vector(vector<T> vec);

    /*! @brief Copy Constructor
     * @param vec: another Vector of same type T
     */
    Vector(const Vector& vec);

    /*! @brief Copy Constructor
     *
     * @param mat : Matrix of same type T and with 1 column only
     */
    Vector(const Matrix<T>& mat);

    /** @brief Destructor */
    ~Vector();

    //overload operators

    /*! @brief overloading read/write operator
     *
     * @param i : size_t index of requested element in the Vector
     * @return reference to ith element
     */
    T& operator[](size_t i);

    /*! @brief overloading read only operator
     *
     * @param i : size_t index of requested element in the Vector
     * @return const reference to ith element
     */
    T operator()(size_t i) const;

    /*! @brief overloading / operator (only valid if current vector has size (1,1)
     *
     * @param vec : another Vector of same type T and of size (1,1)
     * @return a scalar resulting from the division of the two scalar vectors
     */
    T operator/(const Vector& vec) const;

    /*! @brief overloading operator =
     *
     * @param V: an STL vector of same type T
     * @return reference to this
     */
    Vector<T>& operator=(const vector<T>& V);

    /*! @brief overloading operator =
     *
     * @param M: (unicolumn) matrix
     * @return reference to this
     */
    Vector<T>& operator=(const Matrix<T>& M) override;

    /*! @brief overloading operator =
     *
     * @param V: another Vector of same type T
     * @return reference to this
     */
    Vector<T>& operator=(const Vector& V);

    /*! @brief overloading operator *
     *
     * @param scalar: scalar which multiplies every entry of this
     * @return const reference of this
     */
    Vector<T> operator*(const T& scalar);

    /*! @brief Inner product operator
     *
     * @param V : another Vector of same type T and number of rows as this
     * @return inner product between this and V
     */
    T operator*(const Vector& V) const;

    //Utils

    /*! @brief Push_back: push back an element at the back of the Vector
     *
     * @param el : element of same type T as this
     */
    void Push_back(const T& el);

    /** @brief Norm: returns norm of this Vector */
    double Norm() const;

    /*! @brief getValue
     *
     * @return const reference to actual Vector value (vector<T>)
     */
    vector<T> getValue() const;
};

#endif //LINEAR_SOLVERS_VECTOR_H