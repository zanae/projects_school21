#include "s21_matrix.h"
/*
void free_tmp_matrix(int rows, double*** tmp_matrix) {
  if (*tmp_matrix) {
    for (int i = 0; i < rows; i++) {
      free((*tmp_matrix)[i]);
    }
  }
  free(*tmp_matrix);
  *tmp_matrix = NULL;
}
*/
int s21_create_matrix(int rows, int columns, matrix_t* result) {
  int _return = INCORRECT_MATRIX;
  if (rows > 0 && columns > 0 && result != NULL) {
    double** tmp_matrix = (double**)calloc(rows, sizeof(double*));
    int error = tmp_matrix ? 0 : 1;
    for (int i = 0; i < rows && !error; i++) {
      tmp_matrix[i] = (double*)calloc(columns, sizeof(double));
      error = tmp_matrix[i] != NULL ? 0 : 1;
    }
    if (!error) {
      result->rows = rows;
      result->columns = columns;
      result->matrix = tmp_matrix;
      _return = OK;
    } /*else {
      free_tmp_matrix(rows, &tmp_matrix);
    }*/
  }
  return _return;
}
