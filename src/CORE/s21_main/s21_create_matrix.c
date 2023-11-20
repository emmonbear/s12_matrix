#include "s21_main.h"

/**
 * @brief Создать матрицу, размером n rows на m columns
 * @param rows Количество строк
 * @param colomns Количество столбцов
 * @param result Созданная матрица
 * @return int код ошибки:
 *         0 - OK;
 *         1 - Ошибка, некорректная матрица,
 *         2 - Ошибка вычисления
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  s21_result code = S21_OK;
  if ((!result)) {
    code = S21_INVALID_MATRIX;
  } else if ((rows < 1) || (columns < 1)) {
    code = S21_INVALID_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (!result->matrix) {
      code = S21_INVALID_MATRIX;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (!result->matrix[i]) {
          code = S21_INVALID_MATRIX;
        }
      }
    }
  }
  if ((code != S21_OK)) {
    s21_remove_matrix(result);
  }
  return code;
}
