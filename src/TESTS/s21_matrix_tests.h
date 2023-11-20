#ifndef S21_MATRIX_TESTS_H
#define S21_MATRIX_TESTS_H

#include <check.h>

#include "../s21_matrix.h"

typedef enum s21_result_test {
  TEST_OK = 0,
  TEST_INCORRECT_MATRIX = 1,
  TEST_CALCULATION_ERROR = 2,
} s21_result_test;

typedef enum s21_eq_result {
  TEST_SUCCESS = 1,
  TEST_FAILURE = 0,
} s21_eq_result;

Suite *create_matrix_suite(void);
Suite *eq_matrix_suite(void);
Suite *sum_matrix_suite(void);
Suite *sub_matrix_suite(void);
Suite *mult_matrix_suite(void);
Suite *mult_number_suite(void);
Suite *transpose_matrix_suite(void);
Suite *determinant_suite(void);
Suite *calc_complements_suite(void);
Suite *inverse_matrix_suite(void);

void test_create_matrix_success(int rows, int columns);
double get_rand(double min, double max);

#endif  // S21_MATRIX_TESTS_H
