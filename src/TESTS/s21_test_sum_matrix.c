#include "s21_matrix_tests.h"

START_TEST(test_sum_matrix_0) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double value = get_rand(DBL_MIN, DBL_MAX);
      A.matrix[i][j] = value;
      B.matrix[i][j] = value;
    }
  }
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, TEST_OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_matrix_1) {
  matrix_t A = {0};
  matrix_t *B = NULL;
  matrix_t result = {0};
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double value = get_rand(DBL_MIN, DBL_MAX);
      A.matrix[i][j] = value;
    }
  }
  int code = s21_sum_matrix(&A, B, &result);
  ck_assert_int_eq(code, TEST_INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(B);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_matrix_2) {
  matrix_t A = {0};
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  s21_create_matrix(rows, columns, &A);

  matrix_t B = {0};
  const int rows_1 = rand() % 100 + 1;
  const int columns_1 = rand() % 100 + 1;
  matrix_t result = {0};
  s21_create_matrix(rows_1, columns_1, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }
  for (int i = 0; i < rows_1; i++) {
    for (int j = 0; j < columns_1; j++) {
      B.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, TEST_CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

Suite *sum_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sum_matrix");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_sum_matrix_0);
  tcase_add_test(tc_core, test_sum_matrix_1);
  tcase_add_test(tc_core, test_sum_matrix_2);
  suite_add_tcase(s, tc_core);
  return s;
}