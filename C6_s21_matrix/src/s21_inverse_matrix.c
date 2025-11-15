#include "s21_matrix.h"
/*
int eye(int rows, int columns, matrix_t *eye) {
  int _return = s21_create_matrix(rows, columns, eye);
  for (int i = 0; i < rows && _return == OK; i++) {
    eye->matrix[i][i] = 1.0;
  }
  return _return;
}

int check_inverse(matrix_t A, matrix_t inverse) {
  matrix_t ident = {0}, Ainv = {0};
  int _return = eye(A.rows, A.columns, &ident);
  _return = s21_mult_matrix(&A, &inverse, &Ainv);
  _return = s21_eq_matrix(&A, &ident);
  s21_remove_matrix(&ident);
  s21_remove_matrix(&Ainv);
  return _return == SUCCESS ? OK : CALCULATION_ERROR;
}
*/
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int _return = INCORRECT_MATRIX;
  if (validate_matrix(A) == OK && result) {
    double det = 0;
    _return = s21_determinant(A, &det);
    if (_return == OK && fabs(det - 0) > EPS * EPS) {
      matrix_t tmp = {0}, trans_complements = {0};
      _return = s21_calc_complements(A, &tmp);
      _return =
          _return == OK ? s21_transpose(&tmp, &trans_complements) : _return;
      _return = _return == OK
                    ? s21_mult_number(&trans_complements, 1 / det, result)
                    : _return;
      s21_remove_matrix(&tmp);
      s21_remove_matrix(&trans_complements);
    } else {
      _return = CALCULATION_ERROR;
    }
  }
  return _return;
}
/*
int main() {
  matrix_t A = {0}, inv = {0};
  int res = s21_create_matrix(3, 3, &A);
  generate_matrix(&A, 1, 3, 1);
  print_matrix(A);
  res = s21_inverse_matrix(&A, &inv);
  print_matrix(inv);
  printf("%d\n", res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&inv);
  return 0;
}
*/