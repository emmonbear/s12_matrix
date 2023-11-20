#include "s21_matrix_tests.h"

START_TEST(test_eq_matrix_0) {
  matrix_t A = {0};
  matrix_t B = {0};
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
  ck_assert_int_eq(s21_eq_matrix(&A, &B), TEST_SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_1) {
  matrix_t A = {0};
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  s21_create_matrix(rows, columns, &A);

  matrix_t B = {0};
  const int rows_1 = rand() % 100 + 1;
  const int columns_1 = rand() % 100 + 1;
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
  ck_assert_int_eq(s21_eq_matrix(&A, &B), TEST_FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1.02;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
}

Suite *eq_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("eq_matrix");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_eq_matrix_0);
  tcase_add_test(tc_core, test_eq_matrix_1);
  tcase_add_test(tc_core, test_eq_matrix_2);
  tcase_add_test(tc_core, test_eq_matrix_3);
  suite_add_tcase(s, tc_core);
  return s;
}

double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}