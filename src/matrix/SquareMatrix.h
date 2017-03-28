//
// Created by dmitry on 3/28/17.
//

#ifndef LINAL_MIPT_SQUAREMATRIX_H
#define LINAL_MIPT_SQUAREMATRIX_H

#include "Matrix.h"

template <typename T>
class SquareMatrix: protected Matrix<T>
{
    SquareMatrix(const int size);
    SquareMatrix(const SquareMatrix &that);
    SquareMatrix(const Matrix &that);
    ~SquareMatrix();

    bool operator==(const Matrix& that);
    bool operator!=(const Matrix& that);

    SquareMatrix<T> operator=(const SquareMatrix& that);

    SquareMatrix<T> operator+(const SquareMatrix& that) const;
    SquareMatrix<T> operator-(const SquareMatrix& that) const;
};


#endif //LINAL_MIPT_SQUAREMATRIX_H
