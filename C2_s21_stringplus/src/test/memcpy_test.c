#include "s21_tests.h"

START_TEST(test_s21_memcpy_1) {
  char src1[] = "Sorry, World!";
  char dest1[20] = {0};
  s21_size_t len1 = strlen(src1) + 1;
  ck_assert_ptr_eq(s21_memcpy(dest1, src1, len1), memcpy(dest1, src1, len1));
  ck_assert_str_eq(dest1, src1);
}

START_TEST(test_s21_memcpy_2) {
  char src2[] = "";
  char dest2[10] = {0};
  s21_size_t len2 = 1;
  ck_assert_ptr_eq(s21_memcpy(dest2, src2, len2), memcpy(dest2, src2, len2));
  ck_assert_str_eq(dest2, src2);
}
END_TEST

START_TEST(test_s21_memcpy_3) {
  char src3[] = "Sorry\0World";
  char dest3[20] = {0};
  s21_size_t len3 = 11;
  ck_assert_ptr_eq(s21_memcpy(dest3, src3, len3), memcpy(dest3, src3, len3));
  ck_assert_mem_eq(dest3, src3, len3);
}
END_TEST

START_TEST(test_s21_memcpy_4) {
  unsigned char src4[] = {1, 2, 3, 4, 5};
  unsigned char dest4[5] = {0};
  s21_size_t len4 = sizeof(src4);
  ck_assert_ptr_eq(s21_memcpy(dest4, src4, len4), memcpy(dest4, src4, len4));
  ck_assert_mem_eq(dest4, src4, len4);
}
END_TEST

START_TEST(test_s21_memcpy_5) {
  char src5[] = "Sorry, World!";
  char dest5[10] = {0};
  s21_size_t len5 = 5;
  ck_assert_ptr_eq(s21_memcpy(dest5, src5, len5), memcpy(dest5, src5, len5));
  ck_assert_mem_eq(dest5, src5, len5);
}
END_TEST

START_TEST(test_s21_memcpy_6) {
  char src6 = 'A';
  char dest6 = '\0';
  ck_assert_ptr_eq(s21_memcpy(&dest6, &src6, 1), memcpy(&dest6, &src6, 1));
  ck_assert_int_eq(dest6, src6);
}
END_TEST

START_TEST(test_s21_memcpy_7) {
  int src7[] = {1, 2, 3, 4, 5};
  int dest7[5] = {0};
  s21_size_t len7 = sizeof(src7);
  ck_assert_ptr_eq(s21_memcpy(dest7, src7, len7), memcpy(dest7, src7, len7));
  ck_assert_mem_eq(dest7, src7, len7);
}
END_TEST

START_TEST(test_s21_memcpy_8) {
  char src8[] = "Hell";
  char dest8[10] = {0};
  ck_assert_ptr_eq(s21_memcpy(dest8, src8, 0), memcpy(dest8, src8, 0));
  ck_assert_mem_eq(dest8, (char[10]){0}, 10);
}
END_TEST

Suite *suite_memcpy() {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc = tcase_create("s21_memcpy_tc");

  tcase_add_test(tc, test_s21_memcpy_1);
  tcase_add_test(tc, test_s21_memcpy_2);
  tcase_add_test(tc, test_s21_memcpy_3);
  tcase_add_test(tc, test_s21_memcpy_4);
  tcase_add_test(tc, test_s21_memcpy_5);
  tcase_add_test(tc, test_s21_memcpy_6);
  tcase_add_test(tc, test_s21_memcpy_7);
  tcase_add_test(tc, test_s21_memcpy_8);
  suite_add_tcase(s, tc);
  return s;
}
