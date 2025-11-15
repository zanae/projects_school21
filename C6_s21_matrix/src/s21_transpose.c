#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int _return = INCORRECT_MATRIX;
  if (validate_matrix(A) == OK) {
    _return = s21_create_matrix(A->columns, A->rows, result);
    if (_return == OK) {
      for (int i = 0; i < A->columns; i++) {
        for (int j = 0; j < A->rows; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    }
  }
  return _return;
}