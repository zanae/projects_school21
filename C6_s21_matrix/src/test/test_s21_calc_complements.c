#include "tests.h"

#define DEFAULT_COMPLEMENTS_2(P) \
  matrix_t P;                    \
  s21_create_matrix(2, 2, &P);   \
  P.matrix[0][0] = 0.94;         \
  P.matrix[0][1] = -6.97;        \
  P.matrix[1][0] = -5.38;        \
  P.matrix[1][1] = 1.23

#define DEFAULT_COMPLEMENTS_3(P) \
  matrix_t P;                    \
  s21_create_matrix(3, 3, &P);   \
  P.matrix[0][0] = -24.2064;     \
  P.matrix[0][1] = -3.0258;      \
  P.matrix[0][2] = 6.0516;       \
  P.matrix[1][0] = -3.0258;      \
  P.matrix[1][1] = 3.0258;       \
  P.matrix[1][2] = -6.0516;      \
  P.matrix[2][0] = 6.0516;       \
  P.matrix[2][1] = -6.0516;      \
  P.matrix[2][2] = -1.5129

START_TEST(s21_calc_complements_1) {
  int n = 1;
  matrix_t A, C;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  A.matrix[0][0] = 9;
  int _return = s21_calc_complements(&A, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(C.matrix[i][j], 1, EPS);
    }
  }
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  int n = 2;
  matrix_t A, C;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  A.matrix[0][0] = 1.23;
  A.matrix[0][1] = 5.38;
  A.matrix[1][0] = 6.97;
  A.matrix[1][1] = 0.94;
  DEFAULT_COMPLEMENTS_2(complements);
  int _return = s21_calc_complements(&A, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(C.matrix[i][j], complements.matrix[i][j], EPS);
    }
  }
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&complements);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  int n = 3;
  matrix_t A, C;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.23);
  DEFAULT_COMPLEMENTS_3(complements);
  int _return = s21_calc_complements(&A, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(C.matrix[i][j], complements.matrix[i][j], EPS);
    }
  }
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&complements);
}
END_TEST

START_TEST(s21_calc_complements_4) {
  matrix_t A, C;
  int r = 8, c = 3;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  int _return = s21_calc_complements(&A, &C);
  ck_assert_int_eq(_return, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_5) {
  int n = 5;
  matrix_t A, C;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  A.columns = -1;
  int _return = s21_calc_complements(&A, &C);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_6) {
  matrix_t A = {NULL, 5, 5}, C;
  ck_assert_ptr_null(A.matrix);
  int _return = s21_calc_complements(&A, &C);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_7) {
  matrix_t C;
  int _return = s21_calc_complements(NULL, &C);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements_8) {
  int n = 4;
  matrix_t A;
  int _return1 = s21_create_matrix(n, n, &A);
  ck_assert_int_eq(_return1, OK);
  int _return = s21_calc_complements(&A, NULL);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_complements() {
  Suite *s = suite_create("s21_calc_complements");
  TCase *tc = tcase_create("s21_calc_complements_tc");

  tcase_add_test(tc, s21_calc_complements_1);  // ок матрица 1x1
  tcase_add_test(tc, s21_calc_complements_2);  // ок квадратная 2x2
  tcase_add_test(tc, s21_calc_complements_3);  // ок квадратная 3x3
  tcase_add_test(tc, s21_calc_complements_4);  // не ок прямоугольная
  tcase_add_test(tc, s21_calc_complements_5);  // на входе матрица неправильная
  tcase_add_test(tc, s21_calc_complements_6);  // матрица с NULL-матрицей
  tcase_add_test(tc, s21_calc_complements_7);  // на входе матрица чистый NULL
  tcase_add_test(tc, s21_calc_complements_8);  // результирующая матрица NULL

  suite_add_tcase(s, tc);
  return s;
}