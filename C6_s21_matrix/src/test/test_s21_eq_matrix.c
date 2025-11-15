#include "tests.h"

#define SUCCESS 1
#define FAILURE 0

START_TEST(s21_eq_matrix_1) {
  matrix_t A, B;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r, c, &B);
  ck_assert_int_eq(_return1, _return2);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  generate_matrix(&A, 1, 3, 1.11);
  generate_matrix(&B, 1, 3, 1.11);
  int _return = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(_return, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t A, B;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r, c, &B);
  ck_assert_int_eq(_return1, _return2);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  generate_matrix(&A, 1, 3, 1);
  generate_matrix(&B, 0, 3, 1);
  int _return = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(_return, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t A, B;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r * 2, c, &B);
  ck_assert_int_eq(_return1, OK);
  ck_assert_int_eq(_return2, OK);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  generate_matrix(&A, 1, 3, 1);
  generate_matrix(&B, 1, 3, 1);
  int _return = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(_return, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t A, B;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r, c, &B);
  ck_assert_int_eq(_return1, _return2);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  generate_matrix(&A, 1, 3, 1.11111110);
  generate_matrix(&B, 1, 3, 1.11111111);
  int _return = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(_return, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
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
  int _return = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(_return, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  matrix_t A, B;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A),
      _return2 = s21_create_matrix(r, c, &B);
  ck_assert_int_eq(_return1, _return2);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  ck_assert_ptr_nonnull(B.matrix);
  generate_matrix(&A, 1, 3, 1.111111);
  generate_matrix(&B, 1, 3, 1.111111);
  B.columns = -1;
  ck_assert_int_eq(validate_matrix(&B), INCORRECT_MATRIX);
  int _return = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(_return, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_7) {
  matrix_t A;
  int r = 5, c = 8;
  int _return1 = s21_create_matrix(r, c, &A);
  ck_assert_int_eq(_return1, OK);
  ck_assert_ptr_nonnull(A.matrix);
  generate_matrix(&A, 1, 3, 1.111110);
  int _return = s21_eq_matrix(&A, NULL);
  ck_assert_int_eq(_return, FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_eq() {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *tc = tcase_create("s21_eq_matrix_tc");

  tcase_add_test(tc, s21_eq_matrix_1);  // равно
  tcase_add_test(tc, s21_eq_matrix_2);  // неравно
  tcase_add_test(tc, s21_eq_matrix_3);  // разные размеры
  tcase_add_test(tc, s21_eq_matrix_4);
  /*мааааленькая разница в точности, но eps 1e-6,
  т.е. она не должна быть заметна*/
  tcase_add_test(tc, s21_eq_matrix_5);  // а тут должна быть заметна
  tcase_add_test(tc, s21_eq_matrix_6);  // неправильная матрица, columns = -1
  tcase_add_test(tc, s21_eq_matrix_7);  // одна из матриц NULL
  suite_add_tcase(s, tc);
  return s;
}