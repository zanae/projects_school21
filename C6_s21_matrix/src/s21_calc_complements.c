#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int _return = INCORRECT_MATRIX;
  if (validate_matrix(A) == OK) {
    if (A->rows == A->columns) {
      _return = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows && _return == OK; i++) {
        for (int j = 0; j < A->columns && _return == OK; j++) {
          matrix_t minor = {0};
          _return = fill_minor_matrix(A, i, j, &minor);
          double det = 0;
          _return = s21_determinant(&minor, &det);
          if (_return == OK) {
            result->matrix[i][j] = (i + j) % 2 == 0 ? det : -det;
          } else {
            _return = CALCULATION_ERROR;
          }
          s21_remove_matrix(&minor);
        }
      }
    } else {
      _return = CALCULATION_ERROR;
    }
  }
  return _return;
}