#include "s21_main.h"

/**
 * @brief Очистить матрицу А
 * @param А указатель на структуру matrix_t
 */
void s21_remove_matrix(matrix_t *A) {
  if (A) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i]) {
        free(A->matrix[i]);
      }
    }
    if (A->matrix) {
      free(A->matrix);
    }
    A->rows = 0;
    A->columns = 0;
  }
}
