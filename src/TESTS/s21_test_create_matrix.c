#include "s21_matrix_tests.h"

START_TEST(test_create_matrix_0) {
  int rows = 1;
  int columns = 1;
  test_create_matrix_success(rows, columns);
}

START_TEST(test_create_matrix_1) {
  int rows = 2;
  int columns = 1;
  test_create_matrix_success(rows, columns);
}

START_TEST(test_create_matrix_2) {
  int rows = 15;
  int columns = 1;
  test_create_matrix_success(rows, columns);
}

START_TEST(test_create_matrix_3) {
  int rows = 1;
  int columns = 12;
  test_create_matrix_success(rows, columns);
}

START_TEST(test_create_matrix_4) {
  int rows = 10;
  int columns = 12;
  test_create_matrix_success(rows, columns);
}

START_TEST(test_create_matrix_5) {
  matrix_t result = {0};
  int rows = -1;
  int columns = -1;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &result),
                   TEST_INCORRECT_MATRIX);
}

START_TEST(test_create_matrix_6) {
  matrix_t *result = NULL;
  int rows = 3;
  int columns = 2;
  ck_assert_int_eq(s21_create_matrix(rows, columns, result),
                   TEST_INCORRECT_MATRIX);
}

Suite *create_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("create_matrix");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_create_matrix_0);
  tcase_add_test(tc_core, test_create_matrix_1);
  tcase_add_test(tc_core, test_create_matrix_2);
  tcase_add_test(tc_core, test_create_matrix_3);
  tcase_add_test(tc_core, test_create_matrix_4);
  tcase_add_test(tc_core, test_create_matrix_5);
  tcase_add_test(tc_core, test_create_matrix_6);
  suite_add_tcase(s, tc_core);
  return s;
}

void test_create_matrix_success(int rows, int columns) {
  matrix_t result;
  int error_code = s21_create_matrix(rows, columns, &result);
  ck_assert_int_eq(error_code, TEST_OK);
  s21_remove_matrix(&result);
}
