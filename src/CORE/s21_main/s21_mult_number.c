#include "s21_main.h"

/**
 * @brief Умножение матрицы A на число number
 * @param A указатель на структуру matrix_t
 * @param number число типа double, на которое умножается кажется элемент А
 * @param result указатель на структуру matrix_t, в который сохранится результат
 * @return int код ошибки:
 *         0 - OK;
 *         1 - Ошибка, некорректная матрица,
 *         2 - Ошибка вычисления
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  s21_result code = S21_OK;
  if ((s21_is_correct_matrix(A))) {
    code = S21_INVALID_MATRIX;
  } else {
    code = s21_create_matrix(A->rows, A->columns, result);
    if (code == S21_OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
      result->rows = A->rows;
      result->columns = A->columns;
    }
  }
  return code;
}