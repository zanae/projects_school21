#include "tests.h"

START_TEST(s21_sum_matrix_1) {
  matrix_t A, B, C;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r, c, &B);
  ck_assert_int_eq(_return1, _return2);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  generate_matrix(&B, 0, 2, 0.11);
  int _return = s21_sum_matrix(&A, &B, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(C.matrix[i][j], A.matrix[i][j] + B.matrix[i][j],
                              EPS);
    }
  }
  ck_assert_int_eq(_return, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t A, B, C;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r * 2, c * 3, &B);
  ck_assert_int_eq(_return1, _return2);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  generate_matrix(&A, 1, 3, 1);
  generate_matrix(&B, 0, 3, 1);
  int _return = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(_return, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  matrix_t A, B, C;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r, c, &B);
  ck_assert_int_eq(_return1, _return2);
  ck_assert_int_eq(_return1, OK);
  B.columns = -1;
  ck_assert_int_eq(validate_matrix(&B), INCORRECT_MATRIX);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  generate_matrix(&A, 1, 3, 1);
  int _return = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  int r = 5, c = 8;
  matrix_t A, B = {NULL, r, c}, C;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_null(B.matrix);
  // generate_matrix(&A, 1, 3, 1.11111110);
  int _return = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
  matrix_t A, B;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.111110);
  int _return = s21_sum_matrix(&A, NULL, &B);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_sum_matrix_6) {
  matrix_t A, B;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r, c, &B);
  ck_assert_int_eq(_return1, _return2);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  generate_matrix(&A, 1, 3, 1.111110);
  generate_matrix(&B, 1, 3, 1.111111);
  int _return = s21_sum_matrix(&A, &B, NULL);
  ck_assert_int_eq(_return, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_sum() {
  Suite *s = suite_create("s21_sum_matrix");
  TCase *tc = tcase_create("s21_sum_matrix_tc");

  tcase_add_test(tc, s21_sum_matrix_1);  // ок
  tcase_add_test(tc, s21_sum_matrix_2);  // разные размеры
  tcase_add_test(tc, s21_sum_matrix_3);  // одна матрица неправильная
  tcase_add_test(tc, s21_sum_matrix_4);  // одна матрица с NULL-матрицей
  tcase_add_test(tc, s21_sum_matrix_5);  // одна матрица чистый NULL
  tcase_add_test(tc, s21_sum_matrix_6);  // результирующая матрица NULL
  suite_add_tcase(s, tc);
  return s;
}