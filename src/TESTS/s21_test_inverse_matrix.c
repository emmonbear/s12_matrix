#include "s21_matrix_tests.h"

START_TEST(test_inverse_matrix_0) {
  matrix_t A = {0};
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;

  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  matrix_t check = {0};
  s21_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 1;
  check.matrix[0][1] = -1;
  check.matrix[0][2] = 1;

  check.matrix[1][0] = -38;
  check.matrix[1][1] = 41;
  check.matrix[1][2] = -34;

  check.matrix[2][0] = 27;
  check.matrix[2][1] = -29;
  check.matrix[2][2] = 24;

  matrix_t result = {0};
  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, TEST_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), TEST_SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}

START_TEST(test_inverse_matrix_1) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, TEST_CALCULATION_ERROR);
  }
  s21_remove_matrix(&m);
}

START_TEST(test_inverse_matrix_2) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, TEST_INCORRECT_MATRIX);
}

START_TEST(test_inverse_matrix_3) {
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 3, &A);
  int code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(code, TEST_CALCULATION_ERROR);
  s21_remove_matrix(&A);
}

Suite *inverse_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("inverse_matrix");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_inverse_matrix_0);
  tcase_add_test(tc_core, test_inverse_matrix_1);
  tcase_add_test(tc_core, test_inverse_matrix_2);
  tcase_add_test(tc_core, test_inverse_matrix_3);
  suite_add_tcase(s, tc_core);
  return s;
}