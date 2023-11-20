#ifndef S21_ADDITIONAL_FUNCTIONS_H
#define S21_ADDITIONAL_FUNCTIONS_H

#include "../s21_main/s21_main.h"
#include "../s21_types.h"

int s21_validation(matrix_t const* A, matrix_t const* B);
int s21_is_correct_matrix(matrix_t const* A);
int s21_is_equal_size_matrix(matrix_t const* A, matrix_t const* B,
                             matrix_t* result);
matrix_t minor(matrix_t* A, int rows, int columns);
int s21_is_square_matrix(matrix_t const* A);

#endif  // S21_ADDITIONAL_FUNCTIONS_H
