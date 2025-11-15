#include "s21_tests.h"

START_TEST(test_s21_memset_1) {
  char str1[20] = "Hello, World!";
  char str2[20] = "Hello, World!";
  char ch1 = '\0';
  s21_size_t len1 = strlen(str1);
  ck_assert_ptr_eq(s21_memset(str1, ch1, len1), str1);
  memset(str2, ch1, len1);
  ck_assert_mem_eq(str1, str2, len1);
}
END_TEST

START_TEST(test_s21_memset_2) {
  char str3[20] = "Hello, World!";
  char str4[20] = "Hello, World!";
  char ch2 = 'A';
  s21_size_t len2 = strlen(str3);
  ck_assert_ptr_eq(s21_memset(str3, ch2, len2), str3);
  memset(str4, ch2, len2);
  ck_assert_mem_eq(str3, str4, len2);
}
END_TEST

START_TEST(test_s21_memset_3) {
  char str5[20] = "";
  char str6[20] = "";
  char ch3 = 'A';
  s21_size_t len3 = 5;
  ck_assert_ptr_eq(s21_memset(str5, ch3, len3), str5);
  memset(str6, ch3, len3);
  ck_assert_mem_eq(str5, str6, len3);
}
END_TEST

START_TEST(test_s21_memset_4) {
  char str7[20] = "Hello, World!";
  char str8[20] = "Hello, World!";
  char ch4 = 'A';
  s21_size_t len4 = 0;
  ck_assert_ptr_eq(s21_memset(str7, ch4, len4), str7);
  memset(str8, ch4, len4);
  ck_assert_str_eq(str7, str8);
}
END_TEST

START_TEST(test_s21_memset_5) {
  char str9[10];
  char str10[10];
  ck_assert_ptr_eq(s21_memset(str9, 'A', 10), str9);
  memset(str10, 'A', 10);
  ck_assert_mem_eq(str9, str10, 10);
}
END_TEST

Suite *suite_memset() {
  Suite *s = suite_create("s21_memset");
  TCase *tc = tcase_create("s21_memset_tc");

  tcase_add_test(tc, test_s21_memset_1);
  tcase_add_test(tc, test_s21_memset_2);
  tcase_add_test(tc, test_s21_memset_3);
  tcase_add_test(tc, test_s21_memset_4);
  tcase_add_test(tc, test_s21_memset_5);
  suite_add_tcase(s, tc);
  return s;
}
