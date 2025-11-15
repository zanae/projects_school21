#include "s21_tests.h"

START_TEST(test_s21_trim_1) {
  char str1[] = "   Goodbye, World!   ";
  char str2[] = " ";
  char *result = s21_trim(str1, str2);
  ck_assert_pstr_eq(result, "Goodbye, World!");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_2) {
  char str1[] = "\t\tAryuna 16\t\t";
  char str2[] = "\t";
  char *result = s21_trim(str1, str2);
  ck_assert_pstr_eq(result, "Aryuna 16");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_3) {
  char str1[] = " \t Fori Ct \t ";
  char str2[] = " \t";
  char *result = s21_trim(str1, str2);
  ck_assert_pstr_eq(result, "Fori Ct");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_4) {
  char str1[] = "Go jkflkl kjdvs";
  char str2[] = "mbz";
  char *result = s21_trim(str1, str2);
  ck_assert_pstr_eq(result, "Go jkflkl kjdvs");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_5) {
  char str1[] = "";
  char str2[] = " ";
  char *result = s21_trim(str1, str2);
  ck_assert_pstr_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_6) {
  ck_assert_pstr_eq(s21_trim(S21_NULL, S21_NULL), S21_NULL);
}
END_TEST

START_TEST(test_s21_trim_7) {
  char str1[] = "  \tHell Dty!  \t";
  char str2[] = " \t";
  char *result = s21_trim(str1, str2);
  ck_assert_pstr_eq(result, "Hell Dty!");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_8) {
  char str1[] = "\n\nHell Uorpgkr\n\n";
  char str2[] = "\n";
  char *result = s21_trim(str1, str2);
  ck_assert_pstr_eq(result, "Hell Uorpgkr");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_9) {
  char str1[] = "YUYHell GtYUY";
  char str2[] = "YUY";
  char *result = s21_trim(str1, str2);
  ck_assert_pstr_eq(result, "Hell Gt");
  free(result);
}
END_TEST

Suite *suite_trim() {
  Suite *s = suite_create("s21_trim");
  TCase *tc = tcase_create("s21_trim_tc");

  tcase_add_test(tc, test_s21_trim_1);
  tcase_add_test(tc, test_s21_trim_2);
  tcase_add_test(tc, test_s21_trim_3);
  tcase_add_test(tc, test_s21_trim_4);
  tcase_add_test(tc, test_s21_trim_5);
  tcase_add_test(tc, test_s21_trim_6);
  tcase_add_test(tc, test_s21_trim_7);
  tcase_add_test(tc, test_s21_trim_8);
  tcase_add_test(tc, test_s21_trim_9);

  suite_add_tcase(s, tc);
  return s;
}