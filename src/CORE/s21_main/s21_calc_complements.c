#include <math.h>

#include "s21_main.h"

/**
 * @brief Вернуть матрицу алгебраических дополнений
 * @param A Указатель на структуру matrix_t
 * @param result Указатель на структуру matrix_t
 * @return int код ошибки:
 *         0 - OK;
 *         1 - Ошибка, некорректная матрица,
 *         2 - Ошибка вычисления
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  s21_result code = S21_OK;
  if (s21_is_correct_matrix(A)) {
    code = S21_INVALID_MATRIX;
  } else if (!s21_is_square_matrix(A)) {
    code = S21_CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t tmp = minor(A, i, j);
        s21_determinant(&tmp, &result->matrix[i][j]);
        result->matrix[i][j] *= pow(-1, i + j);
        s21_remove_matrix(&tmp);
      }
    }
  }
  return code;
}
