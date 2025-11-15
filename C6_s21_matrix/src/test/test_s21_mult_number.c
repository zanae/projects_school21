#include "tests.h"

START_TEST(s21_mult_number_1) {
  matrix_t A, B;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  double multiplier = 1.234567;
  int _return = s21_mult_number(&A, multiplier, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(B.matrix[i][j], A.matrix[i][j] * multiplier, EPS);
    }
  }
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_number_2) {
  matrix_t A, B;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  int _return = s21_mult_number(&A, 0, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(B.matrix[i][j], 0, EPS);
    }
  }
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_number_3) {
  matrix_t A, B;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  A.columns = -1;
  ck_assert_int_eq(validate_matrix(&A), INCORRECT_MATRIX);
  double multiplier = 1.234567;
  int _return = s21_mult_number(&A, multiplier, &B);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_4) {
  int r = 5, c = 8;
  matrix_t A = {NULL, r, c}, B;
  ck_assert_int_eq(validate_matrix(&A), INCORRECT_MATRIX);
  double multiplier = 1.234567;
  int _return = s21_mult_number(&A, multiplier, &B);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_5) {
  matrix_t B;
  double multiplier = 1.234567;
  int _return = s21_mult_number(NULL, multiplier, &B);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_number_6) {
  int r = 5, c = 8;
  matrix_t A;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  double multiplier = 1.234567;
  int _return = s21_mult_number(&A, multiplier, NULL);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_multn() {
  Suite *s = suite_create("s21_mult_number");
  TCase *tc = tcase_create("s21_mult_number_tc");

  tcase_add_test(tc, s21_mult_number_1);  // ок
  tcase_add_test(tc, s21_mult_number_2);  // ок на 0
  tcase_add_test(tc, s21_mult_number_3);  // на входе матрица неправильная
  tcase_add_test(tc, s21_mult_number_4);  // на входе матрица с NULL-матрицей
  tcase_add_test(tc, s21_mult_number_5);  // на входе матрица чистый NULL
  tcase_add_test(tc, s21_mult_number_6);  // результирующая матрица NULL
  suite_add_tcase(s, tc);
  return s;
}