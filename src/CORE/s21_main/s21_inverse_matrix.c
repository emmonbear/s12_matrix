#include "s21_main.h"

/**
 * @brief Обратная матрица
 * @param A Указатель на структуру matrix_t
 * @param result Указатель на структуру matrix_t
 * @return int код ошибки:
 *         0 - OK;
 *         1 - Ошибка, некорректная матрица,
 *         2 - Ошибка вычисления
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  s21_result code = S21_OK;
  double determinant = 0.0;
  s21_determinant(A, &determinant);
  if (s21_is_correct_matrix(A)) {
    code = S21_INVALID_MATRIX;
  } else if (!s21_is_square_matrix(A)) {
    code = S21_CALCULATION_ERROR;
  } else if (determinant != 0.0) {
    matrix_t tmp_1 = {0};
    matrix_t tmp_2 = {0};
    s21_calc_complements(A, &tmp_1);
    s21_transpose(&tmp_1, &tmp_2);
    s21_mult_number(&tmp_2, (1.0 / determinant), result);
    s21_remove_matrix(&tmp_1);
    s21_remove_matrix(&tmp_2);
  }
  return code;
}