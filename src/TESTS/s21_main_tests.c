#include <stdlib.h>

#include "s21_matrix_tests.h"

int main() {
  int count_failed = 0;
  SRunner *sr;

  sr = srunner_create(NULL);
  srunner_add_suite(sr, create_matrix_suite());
  srunner_add_suite(sr, eq_matrix_suite());
  srunner_add_suite(sr, sum_matrix_suite());
  srunner_add_suite(sr, sub_matrix_suite());
  srunner_add_suite(sr, mult_matrix_suite());
  srunner_add_suite(sr, mult_number_suite());
  srunner_add_suite(sr, transpose_matrix_suite());
  srunner_add_suite(sr, determinant_suite());
  srunner_add_suite(sr, calc_complements_suite());
  srunner_add_suite(sr, inverse_matrix_suite());
  srunner_set_fork_status(sr, CK_NOFORK);
  // srunner_set_log(sr, "-");
  srunner_run_all(sr, CK_VERBOSE);
  count_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (count_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
