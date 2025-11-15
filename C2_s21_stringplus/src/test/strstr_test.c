#include "s21_tests.h"

START_TEST(test_s21_strstr_1) {
  char str1[] = "Hello, World!";
  char str2[] = "World";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_s21_strstr_2) {
  char str3[] = "Roeovme ovmrua";
  char str4[] = "Roeo";
  ck_assert_ptr_eq(s21_strstr(str3, str4), strstr(str3, str4));
}
END_TEST

START_TEST(test_s21_strstr_3) {
  char str5[] = "Xoe Roeporp";
  char str6[] = "orp";
  ck_assert_ptr_eq(s21_strstr(str5, str6), strstr(str5, str6));
}
END_TEST

START_TEST(test_s21_strstr_4) {
  char str7[] = "Eodpf sdvlks";
  char str8[] = "";
  ck_assert_ptr_eq(s21_strstr(str7, str8), strstr(str7, str8));
}
END_TEST

START_TEST(test_s21_strstr_5) {
  char str9[] = "Rpovlx";
  char str10[] = "Dsldkm kfdvm sdldf";
  ck_assert_ptr_eq(s21_strstr(str9, str10), strstr(str9, str10));
}
END_TEST

START_TEST(test_s21_strstr_6) {
  char str11[] = "DFkj sdfamk assoscm";
  char str12[] = "tzp";
  ck_assert_ptr_eq(s21_strstr(str11, str12), strstr(str11, str12));
}
END_TEST

START_TEST(test_s21_strstr_7) {
  char str13[] = "ooooo";
  char str14[] = "oo";
  ck_assert_ptr_eq(s21_strstr(str13, str14), strstr(str13, str14));
}
END_TEST

START_TEST(test_s21_strstr_8) {
  char str15[] = "   orptivxdnd   ";
  char str16[] = " orp";
  ck_assert_ptr_eq(s21_strstr(str15, str16), strstr(str15, str16));
}
END_TEST

START_TEST(test_s21_strstr_9) {
  char str17[] = "l";
  char str18[] = "l";
  ck_assert_ptr_eq(s21_strstr(str17, str18), strstr(str17, str18));
}
END_TEST

START_TEST(test_s21_strstr_10) {
  char str19[] = "Hell\n\t\r";
  char str20[] = "\n\t";
  ck_assert_ptr_eq(s21_strstr(str19, str20), strstr(str19, str20));
}
END_TEST

Suite *suite_strstr() {
  Suite *s = suite_create("s21_strstr");
  TCase *tc = tcase_create("s21_strstr_tc");

  tcase_add_test(tc, test_s21_strstr_1);
  tcase_add_test(tc, test_s21_strstr_2);
  tcase_add_test(tc, test_s21_strstr_3);
  tcase_add_test(tc, test_s21_strstr_4);
  tcase_add_test(tc, test_s21_strstr_5);
  tcase_add_test(tc, test_s21_strstr_6);
  tcase_add_test(tc, test_s21_strstr_7);
  tcase_add_test(tc, test_s21_strstr_8);
  tcase_add_test(tc, test_s21_strstr_9);
  tcase_add_test(tc, test_s21_strstr_10);
  suite_add_tcase(s, tc);
  return s;
}
