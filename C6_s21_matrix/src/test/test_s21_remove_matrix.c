#include "tests.h"

START_TEST(s21_remove_matrix_1) {
  matrix_t A;
  int r = 5, c = 8;
  int _return = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  matrix_t A = {NULL, 0, 0};
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_3) {
  matrix_t *A = NULL;
  s21_remove_matrix(A);
  ck_assert_ptr_null(A);
}
END_TEST

START_TEST(s21_remove_matrix_4) {
  matrix_t A = {NULL, 5, 5};
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

Suite *suite_remove_matrix() {
  Suite *s = suite_create("s21_remove_matrix");
  TCase *tc = tcase_create("s21_remove_matrix_tc");
  tcase_add_test(tc, s21_remove_matrix_1);  // правильно
  tcase_add_test(tc, s21_remove_matrix_2);  // инициализация нулями
  tcase_add_test(tc, s21_remove_matrix_3);  // чистый NULL
  tcase_add_test(tc, s21_remove_matrix_4);
  // matrix = NULL, rows > 0, columns > 0
  suite_add_tcase(s, tc);
  return s;
}