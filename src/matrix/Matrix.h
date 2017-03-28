//
// Created by dmitry on 3/28/17.
//

#ifndef LINAL_MIPT_MATRIX_H
#define LINAL_MIPT_MATRIX_H

#include <iostream>

template <typename T>
class Matrix {
private:
    int row_count;
    int col_count;
    T** values;

    void set_sizes(const int row_count, const int col_count);
    void free();
    static bool compare_size(const Matrix<T>& matrix1, const Matrix<T>& matrix2);
    static bool compare(const Matrix<T>& matrix1, const Matrix<T>& matrix2);
public:
    Matrix(const int row_count, const int col_count);
    Matrix(const Matrix &that);
    ~Matrix();

    bool operator==(const Matrix& that);
    bool operator!=(const Matrix& that);

    template <typename C> friend std::ostream & operator<< (std::ostream &out, const Matrix<C>& matrix);
    template <typename C> friend std::istream & operator>> (std::istream &in, const Matrix<C>& matrix);

    void print();
    static Matrix<int> random(const int row_count, const int col_count);
};

template <typename T>
Matrix<T>::Matrix(const int row_count, const int col_count) {
    set_sizes(row_count, col_count);
    for (int row = 0; row < row_count; ++row) {
        for (int col = 0; col < col_count; ++col) {
            this->values[row][col] = 0;
        }
    }
}

template <typename T>
void Matrix<T>::set_sizes(const int row_count, const int col_count) {
    this->row_count = row_count;
    this->col_count = col_count;
    this->values = new T*[row_count];
    for (int row = 0; row < row_count; ++row) {
        this->values[row] = new T[col_count];
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix &that) {
    set_sizes(that.row_count, that.col_count);
    for (int row = 0; row < row_count; ++row) {
        for (int col = 0; col < col_count; ++col) {
            this->values[row][col] = that.values[row][col];
        }
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    free();
}

template <typename T>
void Matrix<T>::free() {
    for (int row = 0; row < row_count; ++row)
    {
        delete []this->values[row];
    }
    delete []this->values;
}

template <typename T>
void Matrix<T>::print() {
    for (int row = 0; row < row_count; ++row) {
        for (int col = 0; col < col_count; ++col) {
            std::cout << this->values[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
bool Matrix<T>::compare(const Matrix<T> &matrix1, const Matrix<T> &matrix2) {
    if (!compare_size(matrix1, matrix2))
    {
        return false;
    }
    for (int row = 0; row < matrix1.row_count; ++row) {
        for (int col = 0; col < matrix1.col_count; ++col) {
            if (matrix1.values[row][col] != matrix2.values[row][col])
            {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool Matrix<T>::compare_size(const Matrix<T> &matrix1, const Matrix<T> &matrix2) {
    return (matrix1.row_count == matrix2.row_count) && (matrix1.col_count == matrix2.col_count);
}

template <typename T>
bool Matrix<T>::operator==(const Matrix<T> &that) {
    return compare(*this, that);
}

template <>
Matrix<int> Matrix<int>::random(const int row_count, const int col_count) {
    Matrix<int> matrix(row_count, col_count);
    for (int row = 0; row < row_count; ++row) {
        for (int col = 0; col < col_count; ++col) {
            matrix.values[row][col] = rand() % 1001 - 500;
        }
    }
    return matrix;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix &that) {
    return !compare(*this, that);
}

template <typename C>
std::ostream & operator<<(std::ostream &out, const Matrix<C> &matrix) {
    for (int row = 0; row < matrix.row_count; ++row) {
        for (int col = 0; col < matrix.col_count; ++col) {
            out << matrix.values[row][col] << " ";
        }
        out << std::endl;
    }
    return out;
}

template<typename C>
std::istream &operator>>(std::istream &in, const Matrix<C> &matrix) {
    for (int row = 0; row < matrix.row_count; ++row) {
        for (int col = 0; col < matrix.col_count; ++col) {
            in >> matrix.values[row][col];
        }
    }
    return in;
}


#endif //LINAL_MIPT_MATRIX_H
