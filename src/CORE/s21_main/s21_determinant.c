#include <math.h>

#include "s21_main.h"

/**
 * @brief Определитель матрицы
 * @param A Указатель на структуру matrix_t
 * @param result Указатель на double для сохранения результата
 * @return int код ошибки:
 *         0 - OK;
 *         1 - Ошибка, некорректная матрица,
 *         2 - Ошибка вычисления
 */
int s21_determinant(matrix_t *A, double *result) {
  s21_result code = S21_OK;
  *result = 0.0;
  if (s21_is_correct_matrix(A)) {
    code = S21_INVALID_MATRIX;
  } else if (!s21_is_square_matrix(A)) {
    code = S21_CALCULATION_ERROR;
  } else if ((A->rows == 1) && (A->columns == 1)) {
    *result = A->matrix[0][0];
  } else {
    *result = s21_determinant_additional(A);
  }
  return code;
}

/**
 * @brief Вспомогательная функция для расчета определителя
 * @param A Указатель на структуру matrix_t
 * @return double результат расчета определителя матрицы А->matrix
 */
double s21_determinant_additional(matrix_t *A) {
  double result = 0.0;
  if (A->columns == 2) {
    result = (A->matrix[0][0] * A->matrix[1][1]) -
             (A->matrix[1][0] * A->matrix[0][1]);
  } else {
    for (int i = 0; i < A->columns; i++) {
      matrix_t tmp = minor(A, 0, i);
      result += pow(-1, i) * A->matrix[0][i] * s21_determinant_additional(&tmp);
      s21_remove_matrix(&tmp);
    }
  }
  return result;
}