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
public:
    Matrix(const int row_count, const int col_count);
    Matrix(const Matrix &that);
    ~Matrix();

    void print();
};


#endif //LINAL_MIPT_MATRIX_H
