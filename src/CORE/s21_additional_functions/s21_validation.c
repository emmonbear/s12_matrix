#include "s21_additional_functions.h"

/**
 * @brief Проверить, что размерность матрицы A равна размерности матрицы B
 * @param A указатель на структуру matrix_t
 * @param B указатель на структуру matrix_t
 * @return int код
 *         1 - SUCCESS (в случае, если размерности матриц равны)
 *         0 - FAILURE
 */
int s21_validation(matrix_t const* A, matrix_t const* B) {
  equal_matrix error_code = SUCCESS;
  if ((!A) || (!B) || (!A->matrix) || (!B->matrix))
    error_code = FAILURE;
  else if ((A->columns != B->columns) || (A->rows != B->rows))
    error_code = FAILURE;
  return error_code;
}

/**
 * @brief Проверить, что матрица А корректная
 * @param A указатель на matrix_t
 * @return int 0 - матрица корректная
 *             1 - матрица некорректная
 */
int s21_is_correct_matrix(matrix_t const* A) {
  s21_result error_code = S21_OK;
  if ((!A) || (!A->matrix))
    error_code = S21_INVALID_MATRIX;
  else if ((A->rows < 1) || (A->columns < 1))
    error_code = S21_INVALID_MATRIX;
  return error_code;
}

/**
 * @brief Проверить, что поля rows и columns указателей на структуры A и B
 * равны. В случае, если равенство выполняется, то создать матрицу result.
 * @param A указатель на структуру matrix_t
 * @param B указатель на структуру matrix_t
 * @return int код ошибки: 0 - OK;
 *                         2 - Ошибка вычисления;
 */
int s21_is_equal_size_matrix(matrix_t const* A, matrix_t const* B,
                             matrix_t* result) {
  s21_result code = S21_OK;
  if ((A->rows != B->rows) || (A->columns != B->columns)) {
    code = S21_CALCULATION_ERROR;
  } else {
    code = s21_create_matrix(A->rows, A->columns, result);
  }
  return code;
}

/**
 * @brief Проверить, что матрица является квадратной
 * @param A Указатель на структуру matrix_t
 * @result int 1 - матрица квадратная;
 *             0 - матрица прямоугольная;
 */
int s21_is_square_matrix(matrix_t const* A) {
  int code = 1;
  if (A->columns != A->rows) {
    code = 0;
  }
  return code;
}
