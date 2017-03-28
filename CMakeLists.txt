cmake_minimum_required(VERSION 3.6)
project(linal_mipt)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp)
set(MATRIX_FILES src/matrix/Matrix.h)
set(MATRIX_TEST_FILES src/matrix/test.cpp)

add_executable(linal_mipt ${SOURCE_FILES} ${MATRIX_FILES})

add_executable(matrix_test ${MATRIX_TEST_FILES} ${MATRIX_FILES})