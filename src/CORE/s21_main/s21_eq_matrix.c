#include "s21_main.h"

/**
 * @brief Сравнить матрицу A с матрицей B
 * @param A Указатель на матрицу
 * @param B Указатель на матрицу
 * @return int код
 *         1 - SUCCESS
 *         0 - FAILURE
 */
int s21_eq_matrix(matrix_t const* A, matrix_t const* B) {
  equal_matrix error_code = s21_validation(A, B);
  if (error_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] != B->matrix[i][j]) error_code = FAILURE;
      }
    }
  }
  return error_code;
}
