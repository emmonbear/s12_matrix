#include "s21_matrix_tests.h"

START_TEST(test_transpose_matrix_0) {
  matrix_t A = {0};
  matrix_t check = {0};
  matrix_t result = {0};
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &check);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double value = get_rand(DBL_MIN, DBL_MAX);
      A.matrix[i][j] = value;
      check.matrix[j][i] = value;
    }
  }
  int code = s21_transpose(&A, &result);
  ck_assert_int_eq(code, TEST_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), TEST_SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}

Suite *transpose_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("transpose_matrix");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_transpose_matrix_0);
  suite_add_tcase(s, tc_core);
  return s;
}