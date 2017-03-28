//
// Created by dmitry on 3/28/17.
//

#include <iostream>
#include <sstream>
#include "Matrix.h"

int __test_counter = 0;

void assert(const bool statement, const char *message) {
    if (!statement) {
        std::cerr << "Test " << __test_counter << " error: " << message << std::endl;
    }
}

void next_test(const char * test_name)
{
    std::cout << std::endl << "Test " << ++__test_counter << ": " << test_name << std::endl;
}

Matrix<int> matrix2x2_from_string(const char * line)
{
    std::stringstream stringstream(line);
    Matrix<int> matrix(2, 2);
    stringstream >> matrix;
    return matrix;
}

void test_runnable() {
    Matrix<int> matrix = Matrix<int>::random(2, 2);
    std::cout << matrix << std::endl;
    matrix.print();
    assert(true, "Hope, zero 2x2 matrix was printed");
}

void test_equals() {
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(2, 2);
    assert(matrix1 == matrix2, "error on compare two equals zero matrix");
}

void test_not_equals() {
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2 = Matrix<int>::random(2, 2);
    assert(matrix1 != matrix2, "error on compare two not equals zero matrix");
}

void test_cin()
{
    Matrix<int> origin_matrix = Matrix<int>::random(2, 2);
    std::stringstream string;
    string << origin_matrix;
    Matrix<int> read_matrix(2, 2);
    string >> read_matrix;
    assert(origin_matrix == read_matrix, "error on read and write matrix via stream");
}

void test_set()
{
    Matrix<int> matrix1 = Matrix<int>::random(2, 2);
    Matrix<int> matrix2 = Matrix<int>::random(2, 2);
    matrix1 = matrix2;
    assert(matrix1 == matrix2, "error on matrix1 = matrix2");

}

void test_plus_minus()
{
    Matrix<int> matrix1 = matrix2x2_from_string("2 5 23 7");
    Matrix<int> matrix2 = matrix2x2_from_string("3 1 2 3");
    Matrix<int> matrix_sum = matrix2x2_from_string("5 6 25 10");
    Matrix<int> matrix_dif = matrix2x2_from_string("-1 4 21 4");

    assert(matrix1 + matrix2 == matrix_sum, "error on sum matrix");
    assert(matrix1 - matrix2 == matrix_dif, "error on dif matrix");
}


int main() {
    next_test("print random 2x2 matrix two times");
    test_runnable();

    next_test("equals");
    test_equals();

    next_test("not equals");
    test_not_equals();

    next_test("stream work with matrixes, input 2x2 matrix values");
    test_cin();

    next_test("matrix1 = matrix2");
    test_set();

    next_test("sum and dif matrix");
    test_plus_minus();
}
