//
// Created by dmitry on 3/28/17.
//

#include <iostream>
#include "Matrix.h"

void assert(const bool statement, const char *message) {
    if (!statement) {
        std::cerr << "Test error: " << message;
    }
}

void test_runnable() {
    Matrix<int> matrix(2, 2);
    assert(true, "unnable to create matrix");
}

int main() {
    test_runnable();
}
