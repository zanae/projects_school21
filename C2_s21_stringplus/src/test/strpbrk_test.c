#include "s21_tests.h"

START_TEST(test_s21_strpbrk_1) {
  char str1[] = "hello";
  char str2[] = "";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_2) {
  char str3[] = "";
  char str4[] = "vnr";
  ck_assert_ptr_eq(s21_strpbrk(str3, str4), strpbrk(str3, str4));
}
END_TEST

START_TEST(test_s21_strpbrk_3) {
  char str5[] = "";
  char str6[] = "";
  ck_assert_ptr_eq(s21_strpbrk(str5, str6), strpbrk(str5, str6));
}
END_TEST

START_TEST(test_s21_strpbrk_4) {
  char str7[] = "hello\0world";
  char str8[] = "w";
  ck_assert_ptr_eq(s21_strpbrk(str7, str8), strpbrk(str7, str8));
}
END_TEST

START_TEST(test_s21_strpbrk_5) {
  char str9[] = "hello";
  char str10[] = "e\0o";
  ck_assert_ptr_eq(s21_strpbrk(str9, str10), strpbrk(str9, str10));
}
END_TEST

START_TEST(test_s21_strpbrk_6) {
  char str11[] = "hello";
  char str12[] = "xyz";
  ck_assert_ptr_eq(s21_strpbrk(str11, str12), strpbrk(str11, str12));
}
END_TEST

START_TEST(test_s21_strpbrk_7) {
  char str13[] = "Goodbye World!";
  char str14[] = "xyoz";
  ck_assert_ptr_eq(s21_strpbrk(str13, str14), strpbrk(str13, str14));
}
END_TEST

START_TEST(test_s21_strpbrk_8) {
  char str15[] = "Goodbye World!";
  char str16[] = "yox";
  ck_assert_ptr_eq(s21_strpbrk(str15, str16), strpbrk(str15, str16));
}
END_TEST

Suite *suite_strpbrk() {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc = tcase_create("s21_strpbrk_tc");

  tcase_add_test(tc, test_s21_strpbrk_1);
  tcase_add_test(tc, test_s21_strpbrk_2);
  tcase_add_test(tc, test_s21_strpbrk_3);
  tcase_add_test(tc, test_s21_strpbrk_4);
  tcase_add_test(tc, test_s21_strpbrk_5);
  tcase_add_test(tc, test_s21_strpbrk_6);
  tcase_add_test(tc, test_s21_strpbrk_7);
  tcase_add_test(tc, test_s21_strpbrk_8);
  suite_add_tcase(s, tc);
  return s;
}
