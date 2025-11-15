#include "tests.h"

START_TEST(s21_transpose_1) {
  matrix_t A, B;
  int r = 5, c = 5;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  int _return = s21_transpose(&A, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(B.matrix[j][i], A.matrix[i][j], EPS);
    }
  }
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_transpose_2) {
  matrix_t A, B;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  int _return = s21_transpose(&A, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(B.matrix[j][i], A.matrix[i][j], EPS);
    }
  }
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_transpose_3) {
  matrix_t A, B;
  int r = 8, c = 3;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  int _return = s21_transpose(&A, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(B.matrix[j][i], A.matrix[i][j], EPS);
    }
  }
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_transpose_4) {
  matrix_t A, B;
  int r = 8, c = 3;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  A.columns = -1;
  int _return = s21_transpose(&A, &B);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_5) {
  matrix_t A = {NULL, 5, 5}, B;
  ck_assert_ptr_null(A.matrix);
  int _return = s21_transpose(&A, &B);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_6) {
  matrix_t B;
  int _return = s21_transpose(NULL, &B);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_transpose_7) {
  int n = 4;
  matrix_t A;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  int _return = s21_transpose(&A, NULL);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_transpose() {
  Suite *s = suite_create("s21_transpose");
  TCase *tc = tcase_create("s21_transpose_tc");

  tcase_add_test(tc, s21_transpose_1);  // ок  s21_remove_matrix(&B);
  tcase_add_test(tc, s21_transpose_2);  // ок
  tcase_add_test(tc, s21_transpose_3);  // ок
  tcase_add_test(tc, s21_transpose_4);  // на входе матрица неправильная
  tcase_add_test(tc, s21_transpose_5);  // на входе матрица с NULL-матрицей
  tcase_add_test(tc, s21_transpose_6);  // на входе матрица чистый NULL
  tcase_add_test(tc, s21_transpose_7);  // результирующая матрица NULL
  suite_add_tcase(s, tc);
  return s;
}