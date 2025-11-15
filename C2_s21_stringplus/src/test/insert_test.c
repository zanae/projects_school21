#include "s21_tests.h"

START_TEST(test_insert_1) {
  char str1[] = "Hello, world!";
  char str2[] = "Aryuna ";
  char *result = s21_insert(str1, str2, 7);
  ck_assert_pstr_eq(result, "Hello, Aryuna world!");
  free(result);
}
END_TEST

START_TEST(test_insert_2) {
  char str1[] = "Aryuna";
  char str2[] = "777";
  char *result = s21_insert(str1, str2, 2);
  ck_assert_pstr_eq(result, "Ar777yuna");
  free(result);
}
END_TEST

START_TEST(test_insert_3) {
  char str1[] = "Hpfkby14 ys ";
  char str2[] = "pbmtifu!";
  char *result = s21_insert(str1, str2, 12);
  ck_assert_pstr_eq(result, "Hpfkby14 ys pbmtifu!");
  free(result);
}
END_TEST

START_TEST(test_insert_4) {
  char str1[] = "48596";
  char str2[] = "Aryuna";
  char *result = s21_insert(str1, str2, 0);
  ck_assert_pstr_eq(result, "Aryuna48596");
  free(result);
}
END_TEST

START_TEST(test_insert_5) {
  char str1[] = "Aryuna";
  char str2[] = "211";
  char *result = s21_insert(str1, str2, 3);
  ck_assert_pstr_eq(result, "Ary211una");
  free(result);
}
END_TEST

START_TEST(test_insert_6) {
  char str1[] = "ARYUNA";
  char str2[] = "WOR";
  char *result = s21_insert(str1, str2, 5);
  ck_assert_pstr_eq(result, "ARYUNWORA");
  free(result);
}
END_TEST

START_TEST(test_insert_7) {
  char str1[] = "4 + 2 = ";
  char str2[] = "6";
  char *result = s21_insert(str1, str2, 8);
  ck_assert_pstr_eq(result, "4 + 2 = 6");
  free(result);
}
END_TEST

START_TEST(test_insert_8) {
  char str1[] = "Ios zmtif luogk ppo";
  char str2[] = " tofkt kzzu";
  char *result = s21_insert(str1, str2, 19);
  ck_assert_pstr_eq(result, "Ios zmtif luogk ppo tofkt kzzu");
  free(result);
}
END_TEST

START_TEST(test_insert_9) {
  char str1[] = "GOODBYE WORLD";
  char *result = s21_insert(str1, S21_NULL, 2);
  ck_assert_pstr_eq(result, S21_NULL);
  free(result);
}
END_TEST

START_TEST(test_insert_10) {
  char str1[] = "GOODBYE WORLD";
  char *result = s21_insert(S21_NULL, str1, 5);
  ck_assert_pstr_eq(result, S21_NULL);
  free(result);
}
END_TEST

START_TEST(test_insert_11) {
  char *result = s21_insert(S21_NULL, S21_NULL, 4);
  ck_assert_pstr_eq(result, S21_NULL);
  free(result);
}
END_TEST

START_TEST(test_insert_12) {
  char str1[] = "GOODBYE WORLD";
  char str2[] = "ofkbmtu";
  char *result = s21_insert(str1, str2, 20);
  ck_assert_pstr_eq(result, S21_NULL);
  free(result);
}
END_TEST

START_TEST(test_insert_13) {
  char str1[] = "GOODBYE WORLD";
  char str2[] = "dkrobn";
  char *result = s21_insert(str1, str2, -5);
  ck_assert_pstr_eq(result, S21_NULL);
  free(result);
}
END_TEST

Suite *suite_insert() {
  Suite *s = suite_create("s21_insert");
  TCase *tc = tcase_create("s21_insert_tc");

  tcase_add_test(tc, test_insert_1);
  tcase_add_test(tc, test_insert_2);
  tcase_add_test(tc, test_insert_3);
  tcase_add_test(tc, test_insert_4);
  tcase_add_test(tc, test_insert_5);
  tcase_add_test(tc, test_insert_6);
  tcase_add_test(tc, test_insert_7);
  tcase_add_test(tc, test_insert_8);
  tcase_add_test(tc, test_insert_9);
  tcase_add_test(tc, test_insert_10);
  tcase_add_test(tc, test_insert_11);
  tcase_add_test(tc, test_insert_12);
  tcase_add_test(tc, test_insert_13);

  suite_add_tcase(s, tc);
  return s;
}
