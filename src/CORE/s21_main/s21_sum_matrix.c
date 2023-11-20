#include "s21_main.h"

/**
 * @brief Сложение матриц A и B
 * @param A указатель на структуру matrix_t
 * @param B указатель на структуру matrix_t
 * @param result указатель на структуру matrix_t, в который сохранится результат
 * @return int код ошибки:
 *         0 - OK;
 *         1 - Ошибка, некорректная матрица,
 *         2 - Ошибка вычисления
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  s21_result code = S21_OK;
  if ((s21_is_correct_matrix(A)) || (s21_is_correct_matrix(B))) {
    code = S21_INVALID_MATRIX;
  } else {
    code = s21_is_equal_size_matrix(A, B, result);
    if (code == S21_OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
      result->rows = A->rows;
      result->columns = A->columns;
    }
  }
  return code;
}