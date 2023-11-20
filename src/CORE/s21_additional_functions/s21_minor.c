#include "s21_additional_functions.h"

/**
 * @brief Вернуть минор M(rows, columns) матрицы А (без расчета определителя).
 * Валидация не производится
 * @param A Указатель на структуру matrix_t
 * @param rows Индекс строки
 * @param columns Индекс столбца
 * @return matrix_t M(rows, columns) (Возвращается только матрица, а не |M(rows,
 * columns)|)
 */
matrix_t minor(matrix_t *A, int rows, int columns) {
  matrix_t result = {0};
  s21_create_matrix(A->rows - 1, A->columns - 1, &result);
  for (int i = 0, i_tmp = 0; i < A->rows; i++) {
    if (i == rows) {
      continue;
    }
    for (int j = 0, j_tmp = 0; j < A->columns; j++) {
      if (j == columns) {
        continue;
      }
      result.matrix[i_tmp][j_tmp] = A->matrix[i][j];
      j_tmp++;
    }
    i_tmp++;
  }
  return result;
}