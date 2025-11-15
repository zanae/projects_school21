#include "s21_matrix.h"

#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  if (validate_matrix(A) == OK && validate_matrix(B) == OK &&
      A->columns == B->columns && A->rows == B->rows) {
    for (int i = 0; i < A->rows && result == SUCCESS; i++) {
      for (int j = 0; j < A->columns && result == SUCCESS; j++) {
        result =
            fabs(A->matrix[i][j] - B->matrix[i][j]) < EPS ? SUCCESS : FAILURE;
      }
    }
  } else
    result = FAILURE;
  return result;
}