//
// Created by dmitry on 3/28/17.
//

#include <iostream>
#include "Matrix.h"

int __test_counter = 0;

void assert(const bool statement, const char *message) {
    if (!statement) {
        std::cerr << "Test error: " << message << std::endl;
    }
}

void next_test(const char * test_name)
{
    std::cout << std::endl << "Test " << ++__test_counter << ": " << test_name << std::endl;
}

void test_runnable() {
    Matrix<int> matrix(2, 2);
    matrix.print();
    assert(true, "Hope, zero 2x2 matrix was printed");
}

int main() {

    next_test("print zero 2x2 matrix");
    test_runnable();
}
