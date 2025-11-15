#include <stdio.h>

#include "s21_matrix.h"

int validate_matrix(matrix_t *A) {
  /*
  int result = INCORRECT_MATRIX;
  if (A && A->matrix && A->rows > 0 && A->columns > 0) {
    result = OK;
    for (int i = 0; i < A->rows && result == OK; i++)
      result = A->matrix[i] ? OK : INCORRECT_MATRIX; 
      // не катит, т.к. может случиться ситуация, 
      // что на A->matrix память выделена, но заполнена мусором.
  }
  return result;
  */
  return A && A->matrix && A->rows > 0 && A->columns > 0 ? OK
                                                         : INCORRECT_MATRIX;
}

void generate_matrix(matrix_t *A, int add, int shift, double frac) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = ((i + j + add) >> (i + j) % shift) * frac;
    }
  }
}

/*
void print_matrix(const matrix_t A) {
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      printf("%f ", A.matrix[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}
*/

int fill_minor_matrix(matrix_t *A, int r, int c, matrix_t *minor) {
  int _return = INCORRECT_MATRIX;
  if (A->rows == 1 && A->columns == 1) {
    _return = s21_create_matrix(1, 1, minor);
  } else {
    _return = s21_create_matrix(A->rows - 1, A->columns - 1, minor);
  }
  if (_return == OK) {
    if (A->rows == 1 && A->columns == 1)
      minor->matrix[0][0] = 1.0;
    else {
      for (int i = 0; i < minor->rows; i++) {
        for (int j = 0; j < minor->columns; j++) {
          minor->matrix[i][j] = A->matrix[i < r ? i : i + 1][j < c ? j : j + 1];
        }
      }
    }
  }
  return _return;
}
/*
int main() {
  matrix_t A, B, C;
  int res1 = s21_create_matrix(4, 4, &A);
  int res2 = s21_create_matrix(3, 3, &B);
  generate_matrix(&A, 1, 3, 1.23);
  generate_matrix(&B, 0, 2, 3.45);
  print_matrix(A);
  //print_matrix(B);
  int res = s21_mult_matrix(&A, &B, &C);
  //print_matrix(C);

  double det = 1;
  int a = s21_determinant(&A, &det);
  printf("\n\t%.10f\t %d\n", det, a == OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  return 0;
}*/

/*
int main() {
  matrix_t A, B;
  int res1 = s21_create_matrix(1, 1, &A);
  // int res2 = s21_create_matrix(3, 5, &B);
  // generate_matrix(&A, 1, 3, 1.23);
  // generate_matrix(&B, 0, 2, 1);
  A.matrix[0][0] = 19.87;
  print_matrix(A);
  int res = s21_calc_complements(&A, &B);
  print_matrix(B);

  double det = 1;
  int a = s21_determinant(&B, &det);
  printf("\n\t%f\t %d\n", det, a == OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  return 0;
}
*/