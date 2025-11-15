#include "s21_tests.h"

START_TEST(test_s21_strncpy_1) {
  char str1[] = "Sorry world";
  char str2[32] = "";
  char str3[32] = "";
  size_t n1 = 12;
  ck_assert_str_eq(s21_strncpy(str2, str1, n1), strncpy(str3, str1, n1));
}
END_TEST

START_TEST(test_s21_strncpy_2) {
  char str4[] = "Rpdktif dksiqmc";
  char str5[10] = "";
  char str6[10] = "";
  size_t n2 = 5;
  ck_assert_str_eq(s21_strncpy(str5, str4, n2), strncpy(str6, str4, n2));
}
END_TEST

START_TEST(test_s21_strncpy_3) {
  char str7[] = "";
  char str8[10] = "Hell";
  char str9[10] = "Hell";
  size_t n3 = 1;
  ck_assert_str_eq(s21_strncpy(str8, str7, n3), strncpy(str9, str7, n3));
}
END_TEST

START_TEST(test_s21_strncpy_4) {
  char str10[] = "Dpro aleir";
  char str11[20] = "Aprogq cmr ptofkt";
  char str12[20] = "Aprogq cmr ptofkt";
  size_t n4 = 0;
  ck_assert_str_eq(s21_strncpy(str11, str10, n4), strncpy(str12, str10, n4));
}
END_TEST

START_TEST(test_s21_strncpy_5) {
  char str13[] = "Hell\n\t\0Hell";
  char str14[20] = "";
  char str15[20] = "";
  size_t n5 = 10;
  ck_assert_str_eq(s21_strncpy(str14, str13, n5), strncpy(str15, str13, n5));
}
END_TEST

START_TEST(test_s21_strncpy_6) {
  char str16[] = "Sorry";
  char str17[20] = "";
  char str18[20] = "";
  size_t n6 = 15;
  ck_assert_str_eq(s21_strncpy(str17, str16, n6), strncpy(str18, str16, n6));
}
END_TEST

START_TEST(test_s21_strncpy_7) {
  char str19[] = "Aoe soei";
  char str20[20] = "Ope hell";
  char str21[20] = "Old hell";
  size_t n7 = 8;
  ck_assert_str_eq(s21_strncpy(str20, str19, n7), strncpy(str21, str19, n7));
}
END_TEST

START_TEST(test_s21_strncpy_8) {
  char str22[] = "P";
  char str23[10] = "Hell";
  char str24[10] = "Hell";
  size_t n8 = 1;
  ck_assert_str_eq(s21_strncpy(str23, str22, n8), strncpy(str24, str22, n8));
}
END_TEST

START_TEST(test_s21_strncpy_9) {
  char str25[] = "Soeirkv\0hell";
  char str26[20] = "Sch\0doie";
  char str27[20] = "Sch\0doie";
  size_t n9 = 12;
  ck_assert_mem_eq(s21_strncpy(str26, str25, n9), strncpy(str27, str25, n9),
                   n9);
}
END_TEST

Suite *suite_strncpy() {
  Suite *s = suite_create("s21_strncpy");
  TCase *tc = tcase_create("s21_strncpy_tc");

  tcase_add_test(tc, test_s21_strncpy_1);
  tcase_add_test(tc, test_s21_strncpy_2);
  tcase_add_test(tc, test_s21_strncpy_3);
  tcase_add_test(tc, test_s21_strncpy_4);
  tcase_add_test(tc, test_s21_strncpy_5);
  tcase_add_test(tc, test_s21_strncpy_6);
  tcase_add_test(tc, test_s21_strncpy_7);
  tcase_add_test(tc, test_s21_strncpy_8);
  tcase_add_test(tc, test_s21_strncpy_9);
  suite_add_tcase(s, tc);
  return s;
}
