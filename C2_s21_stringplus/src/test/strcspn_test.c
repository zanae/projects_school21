#include "s21_tests.h"

START_TEST(test_s21_strcspn_1) {
  char str1[] = "Aryuna";
  char str2[] = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  char str3[] = "";
  char str4[] = "aryuna";
  ck_assert_int_eq(s21_strcspn(str3, str4), strcspn(str3, str4));
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  char str5[] = "";
  char str6[] = "";
  ck_assert_int_eq(s21_strcspn(str5, str6), strcspn(str5, str6));
}

START_TEST(test_s21_strcspn_4) {
  char str7[] = "goodbye\0world";
  char str8[] = "w";
  ck_assert_int_eq(s21_strcspn(str7, str8), strcspn(str7, str8));
}
END_TEST

START_TEST(test_s21_strcspn_5) {
  char str9[] = "goodbye";
  char str10[] = "d\0e";
  ck_assert_int_eq(s21_strcspn(str9, str10), strcspn(str9, str10));
}

START_TEST(test_s21_strcspn_6) {
  char str11[] = "aryu\0na";
  char str12[] = "n\0a";
  ck_assert_int_eq(s21_strcspn(str11, str12), strcspn(str11, str12));
}

START_TEST(test_s21_strcspn_7) {
  char str13[] = "Goodbye, World!";
  char str14[] = "zxeo";
  ck_assert_int_eq(s21_strcspn(str13, str14), strcspn(str13, str14));
}

START_TEST(test_s21_strcspn_8) {
  char str15[] = "Goodbye, World!";
  char str16[] = "exoz";
  ck_assert_int_eq(s21_strcspn(str15, str16), strcspn(str15, str16));
}

START_TEST(test_s21_strcspn_9) {
  char str17[] = "Goodbye, World!";
  char str18[] = "oxd";
  ck_assert_int_eq(s21_strcspn(str17, str18), strcspn(str17, str18));
}
END_TEST

Suite *suite_strcspn() {
  Suite *s = suite_create("s21_strcspn");
  TCase *tc = tcase_create("s21_strcspn_tc");

  tcase_add_test(tc, test_s21_strcspn_1);
  tcase_add_test(tc, test_s21_strcspn_2);
  tcase_add_test(tc, test_s21_strcspn_3);
  tcase_add_test(tc, test_s21_strcspn_4);
  tcase_add_test(tc, test_s21_strcspn_5);
  tcase_add_test(tc, test_s21_strcspn_6);
  tcase_add_test(tc, test_s21_strcspn_7);
  tcase_add_test(tc, test_s21_strcspn_8);
  tcase_add_test(tc, test_s21_strcspn_9);
  suite_add_tcase(s, tc);
  return s;
}
