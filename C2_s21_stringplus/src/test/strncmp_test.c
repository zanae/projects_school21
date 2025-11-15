#include "s21_tests.h"

START_TEST(test_s21_strncmp_1) {
  char str1[] = "Jkair";
  char str2[] = "Jkair";
  size_t n1 = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n1), strncmp(str1, str2, n1));
}
END_TEST

START_TEST(test_s21_strncmp_2) {
  char str3[] = "Jkair, World!";
  char str4[] = "Jkair";
  size_t n2 = 5;
  ck_assert_int_eq(s21_strncmp(str3, str4, n2), strncmp(str3, str4, n2));
}
END_TEST

START_TEST(test_s21_strncmp_3) {
  char str5[] = "Jkair";
  char str6[] = "World";
  size_t n3 = 5;
  ck_assert_int_eq(s21_strncmp(str5, str6, n3), strncmp(str5, str6, n3));
}
END_TEST

START_TEST(test_s21_strncmp_4) {
  char str7[] = "Goodbye";
  char str8[] = "World";
  size_t n4 = 0;
  ck_assert_int_eq(s21_strncmp(str7, str8, n4), strncmp(str7, str8, n4));
}
END_TEST

START_TEST(test_s21_strncmp_5) {
  char str9[] = "";
  char str10[] = "";
  size_t n5 = 1;
  ck_assert_int_eq(s21_strncmp(str9, str10, n5), strncmp(str9, str10, n5));
}
END_TEST

START_TEST(test_s21_strncmp_6) {
  char str11[] = "Gpor";
  char str12[] = "Gpor";
  size_t n6 = 5;
  ck_assert_int_eq(s21_strncmp(str11, str12, n6), strncmp(str11, str12, n6));
}
END_TEST

START_TEST(test_s21_strncmp_7) {
  char str13[] = "Podkt";
  char str14[] = "Hpflt";
  size_t n7 = 5;
  ck_assert_int_eq(s21_strncmp(str13, str14, n7), strncmp(str13, str14, n7));
}
END_TEST

START_TEST(test_s21_strncmp_8) {
  char str15[] = "Jpcmy World";
  char str16[] = "Jpcmy World";
  size_t n8 = 6;
  ck_assert_int_eq(s21_strncmp(str15, str16, n8), strncmp(str15, str16, n8));
}
END_TEST

START_TEST(test_s21_strncmp_9) {
  char str17[] = "Hell\n";
  char str18[] = "Hell\t";
  size_t n9 = 5;
  ck_assert_int_eq(s21_strncmp(str17, str18, n9), strncmp(str17, str18, n9));
}
END_TEST

START_TEST(test_s21_strncmp_10) {
  char str19[] = "Hell\0Hell";
  char str20[] = "Hell\0Ppvmtodkt";
  size_t n10 = 8;
  ck_assert_int_eq(s21_strncmp(str19, str20, n10), strncmp(str19, str20, n10));
}
END_TEST

Suite *suite_strncmp() {
  Suite *s = suite_create("s21_strnmp");
  TCase *tc = tcase_create("s21_strnmp_tc");

  tcase_add_test(tc, test_s21_strncmp_1);
  tcase_add_test(tc, test_s21_strncmp_2);
  tcase_add_test(tc, test_s21_strncmp_3);
  tcase_add_test(tc, test_s21_strncmp_4);
  tcase_add_test(tc, test_s21_strncmp_5);
  tcase_add_test(tc, test_s21_strncmp_6);
  tcase_add_test(tc, test_s21_strncmp_7);
  tcase_add_test(tc, test_s21_strncmp_8);
  tcase_add_test(tc, test_s21_strncmp_9);
  tcase_add_test(tc, test_s21_strncmp_10);
  suite_add_tcase(s, tc);
  return s;
}
