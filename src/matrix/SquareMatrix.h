//
// Created by dmitry on 3/28/17.
//

#ifndef LINAL_MIPT_SQUAREMATRIX_H
#define LINAL_MIPT_SQUAREMATRIX_H

#include "Matrix.h"

template<typename T>
class SquareMatrix : public Matrix<T> {
protected:
    void assign(const Matrix<T> &that) override;

public:
    SquareMatrix(const int size);

    SquareMatrix(const Matrix<T> &that);

    SquareMatrix<T> operator=(const SquareMatrix<T> &that);

    SquareMatrix<T> operator+(const SquareMatrix<T> &that) const;

    SquareMatrix<T> operator-(const SquareMatrix<T> &that) const;

    SquareMatrix<T> operator*(const T &coefficient) const;

    template<typename C>
    friend SquareMatrix<C> operator*(const C &coefficient, const SquareMatrix<C> matrix);


    int size() const;
};

template<typename T>
SquareMatrix<T>::SquareMatrix(const int size): Matrix(size, size) {}

template<typename T>
void SquareMatrix<T>::assign(const Matrix<T> &that) {
    if (that.rows_size() != that.columns_size()) {
        throw std::logic_error("matrix is not square");
    }
    Matrix<T>::assign(that);
}

template<typename T>
SquareMatrix<T>::SquareMatrix(const Matrix<T> &that) {
    this->assign(that);
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator=(const SquareMatrix<T> &that) {
    this->free_values();
    this->assign(that);
    return *this;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator+(const SquareMatrix<T> &that) const {
    return Matrix<T>::operator+(that);
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator-(const SquareMatrix<T> &that) const {
    return Matrix<T>::operator-(that);
}

template<typename T>
int SquareMatrix<T>::size() const {
    return this->columns_size();
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator*(const T &coefficient) const {
    return Matrix<T>::operator*(coefficient);
}

template<typename C>
SquareMatrix<C> operator*(const C &coefficient, const SquareMatrix<C> matrix) {
    return matrix * coefficient;
}


#endif //LINAL_MIPT_SQUAREMATRIX_H
