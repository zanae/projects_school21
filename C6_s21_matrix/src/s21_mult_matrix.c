#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int _return = OK;
  if (validate_matrix(A) == OK && validate_matrix(B) == OK && result) {
    if (A->columns != B->rows)
      _return = CALCULATION_ERROR;
    else {
      _return = s21_create_matrix(A->rows, B->columns, result);
      if (_return == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            for (int r = 0; r < B->rows; r++) {
              result->matrix[i][j] += A->matrix[i][r] * B->matrix[r][j];
            }
          }
        }
      }
    }
  } else
    _return = INCORRECT_MATRIX;
  return _return;
}