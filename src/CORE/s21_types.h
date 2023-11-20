#ifndef S21_TYPES_H
#define S21_TYPES_H

#include <stdio.h>
#include <stdlib.h>

// Структура матрицы
typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

#endif  // S21_TYPES_H