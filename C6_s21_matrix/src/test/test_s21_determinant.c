#include "tests.h"

START_TEST(s21_determinant_1) {
  int n = 1;
  matrix_t A;
  double detA = 0;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  A.matrix[0][0] = 9;
  int _return = s21_determinant(&A, &detA);
  ck_assert_double_eq_tol(detA, A.matrix[0][0], EPS);
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2) {
  int n = 3;
  matrix_t A;
  double detA = 0;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 1, 1.23);
  int _return = s21_determinant(&A, &detA);
  ck_assert_double_eq_tol(detA, 0, EPS);
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
  int n = 4;
  matrix_t A;
  double detA = 0;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.23);
  int _return = s21_determinant(&A, &detA);
  ck_assert_double_eq_tol(detA, 318.15243099, EPS);
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_4) {
  matrix_t A;
  double detA = 0;
  int r = 8, c = 3;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  int _return = s21_determinant(&A, &detA);
  ck_assert_int_eq(_return, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_5) {
  int n = 5;
  matrix_t A;
  double detA = 0;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  A.columns = -1;
  int _return = s21_determinant(&A, &detA);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_6) {
  matrix_t A = {NULL, 5, 5};
  double detA = 0;
  ck_assert_ptr_null(A.matrix);
  int _return = s21_determinant(&A, &detA);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_7) {
  double detA = 0;
  int _return = s21_determinant(NULL, &detA);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_8) {
  int n = 4;
  matrix_t A;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  int _return = s21_determinant(&A, NULL);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_det() {
  Suite *s = suite_create("s21_determinant");
  TCase *tc = tcase_create("s21_determinant_tc");

  tcase_add_test(tc, s21_determinant_1);  // ок матрица 1x1
  tcase_add_test(tc, s21_determinant_2);  // ок 3x3 с нулевым определителем
  tcase_add_test(tc, s21_determinant_3);  // ок 4x4
  tcase_add_test(tc, s21_determinant_4);  // не ок прямоугольная
  tcase_add_test(tc, s21_determinant_5);  // на входе матрица неправильная
  tcase_add_test(tc, s21_determinant_6);  // матрица с NULL-матрицей
  tcase_add_test(tc, s21_determinant_7);  // на входе матрица чистый NULL
  tcase_add_test(tc, s21_determinant_8);  // запись результата в NULL

  suite_add_tcase(s, tc);
  return s;
}