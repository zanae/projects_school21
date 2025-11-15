#include "tests.h"

START_TEST(s21_create_matrix_1) {
  matrix_t A;
  int r = 5, c = 8;
  int _return = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return, OK);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_int_eq(A.rows, r);
  ck_assert_int_eq(A.columns, c);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j], 0.0, EPS);
    }
  }
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t A;
  int r = -5, c = 8;
  int _return = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  int r = 5, c = 8;
  int _return = s21_create_matrix(r, c, NULL);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  matrix_t A;
  int r = 1, c = 1;
  int _return = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return, OK);
  ck_assert_ptr_nonnull(A.matrix);
  A.matrix[0][0] = 9.0;
  ck_assert_int_eq(A.rows, r);
  ck_assert_int_eq(A.columns, c);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j], 9.0, EPS);
    }
  }
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_create_matrix() {
  Suite *s = suite_create("s21_create_matrix");
  TCase *tc = tcase_create("s21_create_matrix_tc");

  tcase_add_test(tc, s21_create_matrix_1);  // правильно
  tcase_add_test(tc, s21_create_matrix_2);  // неправильный размер
  tcase_add_test(tc, s21_create_matrix_3);  // нулевой указатель
  tcase_add_test(tc, s21_create_matrix_4);  // матрица 1x1
  suite_add_tcase(s, tc);
  return s;
}