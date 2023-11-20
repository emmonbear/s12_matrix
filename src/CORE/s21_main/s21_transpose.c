#include "s21_main.h"

/**
 * @brief Транспонирование матрицы
 * @param A Указатель на структуру matrix_t
 * @param result Указатель на структуру matrix_t
 * @return int код ошибки:
 *         0 - OK;
 *         1 - Ошибка, некорректная матрица,
 *         2 - Ошибка вычисления
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  s21_result code = s21_is_correct_matrix(A);
  if (code == S21_OK) {
    code = s21_create_matrix(A->columns, A->rows, result);
    if (code == S21_OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
      result->rows = A->columns;
      result->columns = A->rows;
    }
  }
  return code;
}