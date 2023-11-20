#include "s21_matrix_tests.h"

START_TEST(test_calc_complements_0) {
  matrix_t A = {0};
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  matrix_t check = {0};
  s21_create_matrix(rows, columns, &check);
  check.matrix[0][0] = 0;
  check.matrix[0][1] = 10;
  check.matrix[0][2] = -20;

  check.matrix[1][0] = 4;
  check.matrix[1][1] = -14;
  check.matrix[1][2] = 8;

  check.matrix[2][0] = -8;
  check.matrix[2][1] = -2;
  check.matrix[2][2] = 4;

  matrix_t result = {0};
  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, TEST_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), TEST_SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}

START_TEST(test_calc_complements_1) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, TEST_INCORRECT_MATRIX);
}

START_TEST(test_calc_complements_2) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(3, 4, &m);
  if (codec == TEST_OK) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, TEST_CALCULATION_ERROR);
    s21_remove_matrix(&m);
  }
}

Suite *calc_complements_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("calc_complements");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_calc_complements_0);
  tcase_add_test(tc_core, test_calc_complements_1);
  tcase_add_test(tc_core, test_calc_complements_2);
  suite_add_tcase(s, tc_core);
  return s;
}