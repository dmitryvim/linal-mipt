//
// Created by dmitry on 3/28/17.
//

#ifndef LINAL_MIPT_SQUAREMATRIX_H
#define LINAL_MIPT_SQUAREMATRIX_H

#include "Matrix.h"

const double EPS = 1e-10;

template<typename T>
class SquareMatrix : public Matrix<T> {
protected:
    void assign(const Matrix<T> &that) override;

    void _swap_rows(const int row1, const int row2);

    void _row_sum(const int row1, const int row2, const T coef);

    T abs_get(const int row, const int col);

    T diag_mult() const;

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

    T det();

    SquareMatrix<T> up_triangle();

    SquareMatrix<T> get_up_triangle() const;
};

template<typename T>
SquareMatrix<T>::SquareMatrix(const int size): Matrix<T>::Matrix(size, size) {
//    Matrix<T>::Matrix(size, size);
}

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

template<typename T>
T SquareMatrix<T>::det() {
    return this->get_up_triangle().diag_mult();
}


template<typename T>
SquareMatrix<T> SquareMatrix<T>::up_triangle() {
    for (int col = 0; col < this->size(); ++col) {
        int nn_row = col;
        while (nn_row < this->size() && this->abs_get(nn_row, col) < EPS) {
            nn_row++;
        }

        if (col != nn_row) {
            this->_swap_rows(col, nn_row);
        }

        for (int row = col + 1; row < this->size(); ++row) {
            if (this->abs_get(row, col) > EPS) {
                T c = -this->get(row, col) / this->get(nn_row, col);
                this->_row_sum(row, nn_row, c);
            }
        }
    }
    return *this;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::get_up_triangle() const {
    SquareMatrix result = *this;
    return result.up_triangle();
}

template<typename T>
T SquareMatrix<T>::diag_mult() const {
    T result = 1;
    for (int i = 0; i < this->size(); ++i) {
        result *= this->get(i, i);
    }
    return result;
}

template<typename T>
void SquareMatrix<T>::_swap_rows(const int row1, const int row2) {
    if (row1 != row2) {
        this->swap_rows(row1, row2);
        for (int col = 0; col < this->size(); ++col) {
            this->set(row2, col, -this->get(row2, col));
        }
    }
}

template<typename T>
void SquareMatrix<T>::_row_sum(const int row1, const int row2, const T coef) {
    for (int col = 0; col < this->size(); ++col) {
        this->set(row1, col, this->get(row1, col) + coef * this->get(row2, col));
    }
}

template<typename T>
T SquareMatrix<T>::abs_get(const int row, const int col) {
    T value = this->get(row, col);
    return value < 0 ? -value : value;
}


#endif //LINAL_MIPT_SQUAREMATRIX_H
