#include "tests.h"

#define EYE(E, n)               \
  matrix_t E;                   \
  s21_create_matrix(n, n, &E);  \
  for (int i = 0; i < n; i++) { \
    E.matrix[i][i] = 1;         \
  }

START_TEST(s21_inverse_matrix_1) {
  int n = 1;
  matrix_t A, B, C;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  A.matrix[0][0] = 10;
  int _return = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(_return, OK);
  EYE(E, n);
  int _return0 = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(_return0, OK);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(E.matrix[i][j], C.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&E);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  int n = 4;
  matrix_t A, B, C;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, -1.11);
  int _return = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(_return, OK);
  EYE(E, n);
  int _return0 = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(_return0, OK);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(E.matrix[i][j], C.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&E);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  int n = 4;
  matrix_t A, B;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  int _return = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(_return, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  int n = 4;
  matrix_t B, C;
  EYE(E, n);
  int _return = s21_inverse_matrix(&E, &B);
  ck_assert_int_eq(_return, OK);
  int _return0 = s21_mult_matrix(&E, &B, &C);
  ck_assert_int_eq(_return0, OK);
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert_double_eq_tol(E.matrix[i][j], C.matrix[i][j], EPS);
    }
  }
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&E);
}
END_TEST

START_TEST(s21_inverse_matrix_5) {
  int n = 4;
  matrix_t A, B;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 1, 1);
  int _return = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(_return, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_6) {
  int r = 4, c = 9;
  matrix_t A, B;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, -1);
  int _return = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(_return, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_7) {
  matrix_t A, B;
  int r = 8, c = 3;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  A.columns = -1;
  int _return = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_8) {
  matrix_t A = {NULL, 5, 5}, B;
  ck_assert_ptr_null(A.matrix);
  int _return = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_9) {
  matrix_t B;
  int _return = s21_inverse_matrix(NULL, &B);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix_10) {
  int n = 4;
  matrix_t A;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  int _return = s21_inverse_matrix(&A, NULL);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_inverse() {
  Suite *s = suite_create("s21_inverse_matrix");
  TCase *tc = tcase_create("s21_inverse_matrix_tc");

  tcase_add_test(tc, s21_inverse_matrix_1);  // ок матрица 1x1
  tcase_add_test(tc, s21_inverse_matrix_2);  // ок матрица 4x4
  tcase_add_test(tc, s21_inverse_matrix_3);  // не ок нулевая матрица
  tcase_add_test(tc, s21_inverse_matrix_4);  // ок единичная матрица
  tcase_add_test(tc, s21_inverse_matrix_5);  // не ок определитель=0
  tcase_add_test(tc, s21_inverse_matrix_6);  // не ок матрица прямоугольная
  tcase_add_test(tc, s21_inverse_matrix_7);  // на входе матрица неправильная
  tcase_add_test(tc, s21_inverse_matrix_8);  // на входе матрица с NULL-матрицей
  tcase_add_test(tc, s21_inverse_matrix_9);  // на входе матрица чистый NULL
  tcase_add_test(tc, s21_inverse_matrix_10);  // результирующая матрица NULL
  suite_add_tcase(s, tc);
  return s;
}