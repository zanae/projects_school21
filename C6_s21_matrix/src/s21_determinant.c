#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int _return = INCORRECT_MATRIX;
  if (validate_matrix(A) == OK && result != NULL) {
    *result = 0;
    if (A->columns == A->rows) {
      _return = OK;
      double det = 0;
      if (A->columns == 1) {
        det = A->matrix[0][0];
      } else if (A->columns == 2) {
        det = A->matrix[0][0] * A->matrix[1][1] -
              A->matrix[0][1] * A->matrix[1][0];
      } else {
        for (int i = 0; i < A->rows && _return == OK; i++) {
          matrix_t minor_matrix = {0};
          double tmp = 0;
          fill_minor_matrix(A, 0, i, &minor_matrix);
          _return = s21_determinant(&minor_matrix, &tmp);
          if (_return == OK) {
            det += A->matrix[0][i] * (i % 2 == 0 ? 1.0 : -1.0) * tmp;
          } else
            _return = CALCULATION_ERROR;
          s21_remove_matrix(&minor_matrix);
        }
      }
      *result = det;
    } else
      _return = CALCULATION_ERROR;
  }
  return _return;
}
