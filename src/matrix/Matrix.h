//
// Created by dmitry on 3/28/17.
//

#ifndef LINAL_MIPT_MATRIX_H
#define LINAL_MIPT_MATRIX_H


template <typename T>
class Matrix {
private:
    int row_count;
    int col_count;
    T** values;

    void set_sizes(const int row_count, const int col_count);
    void free();
public:
    Matrix(const int row_count, const int col_count);
    Matrix(const Matrix &that);
    ~Matrix();

    void print();
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


#endif //LINAL_MIPT_MATRIX_H
