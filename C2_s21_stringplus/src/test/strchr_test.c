#include "s21_tests.h"
START_TEST(test_s21_strchr_1) {
  const char str1[] = "Goodbye, World!";
  int c1 = 'o';
  ck_assert_ptr_eq(s21_strchr(str1, c1), strchr(str1, c1));
}
END_TEST

START_TEST(test_s21_strchr_2) {
  const char str2[] = "Hello Aryuna";
  int c2 = 'A';
  ck_assert_ptr_eq(s21_strchr(str2, c2), strchr(str2, c2));
}
END_TEST

START_TEST(test_s21_strchr_3) {
  const char str3[] = "Hello aryuna";
  int c3 = 'a';
  ck_assert_ptr_eq(s21_strchr(str3, c3), strchr(str3, c3));
}
END_TEST

START_TEST(test_s21_strchr_4) {
  const char str4[] = "Aryuna";
  int c4 = '\0';
  ck_assert_str_eq(s21_strchr(str4, c4), strchr(str4, c4));
}
END_TEST

START_TEST(test_s21_strchr_5) {
  const char str5[] = "Hello Aryuna!";
  int c5 = 'z';
  ck_assert_ptr_eq(s21_strchr(str5, c5), strchr(str5, c5));
}
END_TEST

START_TEST(test_s21_strchr_6) {
  const char str6[] = "";
  int c6 = 's';
  ck_assert_ptr_eq(s21_strchr(str6, c6), strchr(str6, c6));
}
END_TEST

START_TEST(test_s21_strchr_7) {
  const char str7[] = "Goodbye World, Goodbye!";
  int c7 = 'o';
  ck_assert_ptr_eq(s21_strchr(str7, c7), strchr(str7, c7));
}
END_TEST

START_TEST(test_s21_strchr_8) {
  const char str8[] = "Goodbye World";
  int c8 = ' ';
  ck_assert_ptr_eq(s21_strchr(str8, c8), strchr(str8, c8));
}

START_TEST(test_s21_strchr_9) {
  const char str9[] = "Hello aryuna";
  int c9 = (unsigned char)-1;
  ck_assert_ptr_eq(s21_strchr(str9, c9), strchr(str9, c9));
}
END_TEST

START_TEST(test_s21_strchr_10) {
  const char str10[] = "Hello Aryuna";
  int c10 = 255;
  ck_assert_ptr_eq(s21_strchr(str10, c10), strchr(str10, c10));
}
END_TEST

Suite *suite_strchr() {
  Suite *s = suite_create("s21_strchr");
  TCase *tc = tcase_create("s21_strchr_tc");

  tcase_add_test(tc, test_s21_strchr_1);
  tcase_add_test(tc, test_s21_strchr_2);
  tcase_add_test(tc, test_s21_strchr_3);
  tcase_add_test(tc, test_s21_strchr_4);
  tcase_add_test(tc, test_s21_strchr_5);
  tcase_add_test(tc, test_s21_strchr_6);
  tcase_add_test(tc, test_s21_strchr_7);
  tcase_add_test(tc, test_s21_strchr_8);
  tcase_add_test(tc, test_s21_strchr_9);
  tcase_add_test(tc, test_s21_strchr_10);
  suite_add_tcase(s, tc);
  return s;
}
