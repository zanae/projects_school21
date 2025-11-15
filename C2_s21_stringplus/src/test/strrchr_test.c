#include "s21_tests.h"

START_TEST(test_s21_strrchr_1) {
  char str1[] = "goodbye world";
  int c1 = 'o';
  ck_assert_ptr_eq(s21_strrchr(str1, c1), strrchr(str1, c1));
}
END_TEST

START_TEST(test_s21_strrchr_2) {
  char str2[] = "goodbye world";
  int c2 = 'z';
  ck_assert_ptr_eq(s21_strrchr(str2, c2), strrchr(str2, c2));
}
END_TEST

START_TEST(test_s21_strrchr_3) {
  char str3[] = "goodbye\0world";
  int c3 = '\0';
  ck_assert_ptr_eq(s21_strrchr(str3, c3), strrchr(str3, c3));
}
END_TEST

START_TEST(test_s21_strrchr_4) {
  char str4[] = "";
  int c4 = 's';
  ck_assert_ptr_eq(s21_strrchr(str4, c4), strrchr(str4, c4));
}
END_TEST

START_TEST(test_s21_strrchr_5) {
  char str5[] = "dkedkedke";
  int c5 = 'k';
  ck_assert_ptr_eq(s21_strrchr(str5, c5), strrchr(str5, c5));
}
END_TEST

START_TEST(test_s21_strrchr_6) {
  char str6[] = "aryuna";
  int c6 = 'a';
  ck_assert_ptr_eq(s21_strrchr(str6, c6), strrchr(str6, c6));
}
END_TEST

START_TEST(test_s21_strrchr_7) {
  char str7[] = "vkxcvci";
  int c7 = 'i';
  ck_assert_ptr_eq(s21_strrchr(str7, c7), strrchr(str7, c7));
}
END_TEST

START_TEST(test_s21_strrchr_8) {
  char str8[] = "";
  int c8 = '\0';
  ck_assert_ptr_eq(s21_strrchr(str8, c8), strrchr(str8, c8));
}
END_TEST

Suite *suite_strrchr() {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc = tcase_create("s21_strrchr_tc");

  tcase_add_test(tc, test_s21_strrchr_1);
  tcase_add_test(tc, test_s21_strrchr_2);
  tcase_add_test(tc, test_s21_strrchr_3);
  tcase_add_test(tc, test_s21_strrchr_4);
  tcase_add_test(tc, test_s21_strrchr_5);
  tcase_add_test(tc, test_s21_strrchr_6);
  tcase_add_test(tc, test_s21_strrchr_7);
  tcase_add_test(tc, test_s21_strrchr_8);
  suite_add_tcase(s, tc);
  return s;
}
