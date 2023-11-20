#include "s21_matrix_tests.h"

START_TEST(test_mult_number_0) {
  matrix_t A = {0};
  matrix_t result = {0};
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  double value_1 = get_rand(DBL_MIN, DBL_MAX);
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double value = get_rand(DBL_MIN, DBL_MAX);
      A.matrix[i][j] = value;
    }
  }
  int code = s21_mult_number(&A, value_1, &result);
  ck_assert_int_eq(code, TEST_OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(test_mult_number_1) {
  matrix_t result = {0};
  double value_1 = get_rand(DBL_MIN, DBL_MAX);
  int code = s21_mult_number(NULL, value_1, &result);
  ck_assert_int_eq(code, TEST_INCORRECT_MATRIX);
  s21_remove_matrix(&result);
}

Suite *mult_number_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("mult_number");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_mult_number_0);
  tcase_add_test(tc_core, test_mult_number_1);
  suite_add_tcase(s, tc_core);
  return s;
}