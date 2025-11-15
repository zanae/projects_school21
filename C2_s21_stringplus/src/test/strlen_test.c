#include "s21_tests.h"

START_TEST(test_s21_strlen_1) {
  char *str1 = "Goodbye, World!";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(test_s21_strlen_2) {
  char *str2 = "";
  ck_assert_int_eq(s21_strlen(str2), strlen(str2));
}
END_TEST

START_TEST(test_s21_strlen_3) {
  char *str3 = "Goodbye, \0World!";
  ck_assert_int_eq(s21_strlen(str3), strlen(str3));
}
END_TEST

START_TEST(test_s21_strlen_4) {
  char *str4 = "\0";
  ck_assert_int_eq(s21_strlen(str4), strlen(str4));
}
END_TEST

START_TEST(test_s21_strlen_5) {
  char *str5 = "G";
  ck_assert_int_eq(s21_strlen(str5), strlen(str5));
}
END_TEST

Suite *suite_strlen() {
  Suite *s = suite_create("s21_strlen");
  TCase *tc = tcase_create("s21_strlen_tc");

  tcase_add_test(tc, test_s21_strlen_1);
  tcase_add_test(tc, test_s21_strlen_2);
  tcase_add_test(tc, test_s21_strlen_3);
  tcase_add_test(tc, test_s21_strlen_4);
  tcase_add_test(tc, test_s21_strlen_5);

  suite_add_tcase(s, tc);
  return s;
}
