#include "tests.h"

#define DEFAULT_PRODUCT_SQUARE(P) \
  matrix_t P;                     \
  s21_create_matrix(3, 3, &P);    \
  P.matrix[0][0] = 0;             \
  P.matrix[0][1] = 8.487;         \
  P.matrix[0][2] = 12.7305;       \
  P.matrix[1][0] = 33.948;        \
  P.matrix[1][1] = 16.974;        \
  P.matrix[1][2] = 76.383;        \
  P.matrix[2][0] = 16.974;        \
  P.matrix[2][1] = 42.435;        \
  P.matrix[2][2] = 50.922

#define DEFAULT_PRODUCT_RECTANGULAR_3_5(P) \
  matrix_t P;                              \
  s21_create_matrix(3, 5, &P);             \
  P.matrix[0][0] = 0;                      \
  P.matrix[0][1] = 8.487;                  \
  P.matrix[0][2] = 12.7305;                \
  P.matrix[0][3] = 21.2175;                \
  P.matrix[0][4] = 25.461;                 \
  P.matrix[1][0] = 33.948;                 \
  P.matrix[1][1] = 16.974;                 \
  P.matrix[1][2] = 76.383;                 \
  P.matrix[1][3] = 38.1915;                \
  P.matrix[1][4] = 118.818;                \
  P.matrix[2][0] = 16.974;                 \
  P.matrix[2][1] = 42.435;                 \
  P.matrix[2][2] = 50.922;                 \
  P.matrix[2][3] = 84.87;                  \
  P.matrix[2][4] = 84.87

START_TEST(s21_mult_matrix_1) {
  matrix_t A, B, C;
  int r = 3, c = 3;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r, c, &B);
  ck_assert_int_eq(_return1, OK);
  ck_assert_int_eq(_return2, OK);
  generate_matrix(&A, 1, 3, 1.23);
  generate_matrix(&B, 0, 2, 3.45);
  DEFAULT_PRODUCT_SQUARE(product);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  ck_assert_ptr_nonnull(product.matrix);
  int _return = s21_mult_matrix(&A, &B, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert_double_eq_tol(C.matrix[i][j], product.matrix[i][j], EPS);
    }
  }
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&product);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t A, B, C;
  int r = 3, c = 3;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r, 5, &B);
  ck_assert_int_eq(_return1, OK);
  ck_assert_int_eq(_return2, OK);
  generate_matrix(&A, 1, 3, 1.23);
  generate_matrix(&B, 0, 2, 3.45);
  DEFAULT_PRODUCT_RECTANGULAR_3_5(product);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  ck_assert_ptr_nonnull(product.matrix);
  int _return = s21_mult_matrix(&A, &B, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert_double_eq_tol(C.matrix[i][j], product.matrix[i][j], EPS);
    }
  }
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&product);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t A, B, C;
  int r = 3, c = 3;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r + 1, c + 2, &B);
  ck_assert_int_eq(_return1, OK);
  ck_assert_int_eq(_return2, OK);
  generate_matrix(&A, 1, 3, 1.23);
  generate_matrix(&B, 0, 2, 3.45);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  int _return = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(_return, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  matrix_t A, B, C;
  int r = 3, c = 5;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r - 1, c + 2, &B);
  ck_assert_int_eq(_return1, OK);
  ck_assert_int_eq(_return2, OK);
  generate_matrix(&A, 1, 3, 1.23);
  generate_matrix(&B, 0, 2, 3.45);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  int _return = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(_return, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_5) {
  matrix_t A, B, C;
  int r = 3, c = 5;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r - 1, c + 2, &B);
  ck_assert_int_eq(_return1, OK);
  ck_assert_int_eq(_return2, OK);
  generate_matrix(&A, 1, 3, 1.23);
  generate_matrix(&B, 0, 2, 3.45);
  A.columns = -1;
  int _return = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_6) {
  int r = 3, c = 5;
  matrix_t A = {NULL, r, c}, B, C;
  int _return2 = s21_create_matrix(r - 1, c + 2, &B);
  ck_assert_int_eq(_return2, OK);
  generate_matrix(&B, 0, 2, 3.45);
  ck_assert_ptr_null(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  int _return = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  // s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_7) {
  int r = 3, c = 5;
  matrix_t B, C;
  int _return2 = s21_create_matrix(r - 1, c + 2, &B);
  ck_assert_int_eq(_return2, OK);
  generate_matrix(&B, 0, 2, 3.45);
  ck_assert_ptr_nonnull(B.matrix);
  int _return = s21_mult_matrix(&B, NULL, &C);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  // s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_8) {
  matrix_t A, B;
  int r = 3, c = 5;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r - 1, c + 2, &B);
  ck_assert_int_eq(_return1, OK);
  ck_assert_int_eq(_return2, OK);
  generate_matrix(&A, 1, 3, 1.23);
  generate_matrix(&B, 0, 2, 3.45);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  int _return = s21_mult_matrix(&A, &B, NULL);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_multm() {
  Suite *s = suite_create("s21_mult_matrix");
  TCase *tc = tcase_create("s21_mult_matrix_tc");

  tcase_add_test(tc, s21_mult_matrix_1);  // ок
  tcase_add_test(tc, s21_mult_matrix_2);  // ок с разными размерами
  tcase_add_test(tc, s21_mult_matrix_3);  // не ок с разными размерами
  tcase_add_test(tc, s21_mult_matrix_4);  // не ок с разными размерами
  tcase_add_test(tc, s21_mult_matrix_5);  // одна матрица неправильная
  tcase_add_test(tc, s21_mult_matrix_6);  // одна матрица с NULL-матрицей
  tcase_add_test(tc, s21_mult_matrix_7);  // одна матрица чистый NULL
  tcase_add_test(tc, s21_mult_matrix_8);  // результирующая матрица NULL
  suite_add_tcase(s, tc);
  return s;
}