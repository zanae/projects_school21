#include "s21_tests.h"

START_TEST(test_s21_strtok_1) {
  char str1[] = "Fksf dkvsma ssdkvcs dvjdks";
  char str2[] = "Fksf dkvsma ssdkvcs dvjdks";
  char sym1[] = " ";
  ck_assert_str_eq(s21_strtok(str1, sym1), strtok(str2, sym1));
  ck_assert_str_eq(s21_strtok(NULL, sym1), strtok(NULL, sym1));
  ck_assert_str_eq(s21_strtok(NULL, sym1), strtok(NULL, sym1));
  ck_assert_str_eq(s21_strtok(NULL, sym1), strtok(NULL, sym1));
  ck_assert_ptr_eq(s21_strtok(NULL, sym1), strtok(NULL, sym1));
}
END_TEST

START_TEST(test_s21_strtok_2) {
  char str3[] = "fjknvkj;;;;kjscac!!!!vvskvkm";
  char str4[] = "fjknvkj;;;;kjscac!!!!vvskvkm";
  char sym2[] = ";!";
  ck_assert_str_eq(s21_strtok(str3, sym2), strtok(str4, sym2));
  ck_assert_str_eq(s21_strtok(NULL, sym2), strtok(NULL, sym2));
  ck_assert_str_eq(s21_strtok(NULL, sym2), strtok(NULL, sym2));
  ck_assert_ptr_eq(s21_strtok(NULL, sym2), strtok(NULL, sym2));
}
END_TEST

START_TEST(test_s21_strtok_3) {
  char str5[] = "!!Fdsckl!!dsklvskv,!!";
  char str6[] = "!!Fdsckl!!dsklvskv,!!";
  char sym3[] = "!";
  ck_assert_str_eq(s21_strtok(str5, sym3), strtok(str6, sym3));
  ck_assert_str_eq(s21_strtok(NULL, sym3), strtok(NULL, sym3));
  ck_assert_ptr_eq(s21_strtok(NULL, sym3), strtok(NULL, sym3));
}
END_TEST

START_TEST(test_s21_strtok_4) {
  char str7[] = "!!!!!!";
  char str8[] = "!!!!!!";
  char sym4[] = "!";
  ck_assert_ptr_eq(s21_strtok(str7, sym4), strtok(str8, sym4));
}
END_TEST

START_TEST(test_s21_strtok_5) {
  char str9[] = "";
  char str10[] = "";
  char sym5[] = "!";
  ck_assert_ptr_eq(s21_strtok(str9, sym5), strtok(str10, sym5));
}
END_TEST

START_TEST(test_s21_strtok_6) {
  char str11[] = "I";
  char str12[] = "I";
  char sym6[] = "!";
  ck_assert_str_eq(s21_strtok(str11, sym6), strtok(str12, sym6));
  ck_assert_ptr_eq(s21_strtok(NULL, sym6), strtok(NULL, sym6));
}
END_TEST

START_TEST(test_s21_strtok_7) {
  char str13[] = "fjd!fgm&dkbj.yotjk@hglknm";
  char str14[] = "fjd!fgm&dkbj.yotjk@hglknm";
  char sym7[] = "!&.@";
  ck_assert_str_eq(s21_strtok(str13, sym7), strtok(str14, sym7));
  ck_assert_str_eq(s21_strtok(NULL, sym7), strtok(NULL, sym7));
  ck_assert_str_eq(s21_strtok(NULL, sym7), strtok(NULL, sym7));
  ck_assert_str_eq(s21_strtok(NULL, sym7), strtok(NULL, sym7));
  ck_assert_str_eq(s21_strtok(NULL, sym7), strtok(NULL, sym7));
  ck_assert_ptr_eq(s21_strtok(NULL, sym7), strtok(NULL, sym7));
}
END_TEST

START_TEST(test_s21_strtok_8) {
  char str15[] = "dfkm\nkgfl\tfgkfhlb";
  char str16[] = "dfkm\nkgfl\tfgkfhlb";
  char sym8[] = "\n\t";
  ck_assert_str_eq(s21_strtok(str15, sym8), strtok(str16, sym8));
  ck_assert_str_eq(s21_strtok(NULL, sym8), strtok(NULL, sym8));
  ck_assert_str_eq(s21_strtok(NULL, sym8), strtok(NULL, sym8));
  ck_assert_ptr_eq(s21_strtok(NULL, sym8), strtok(NULL, sym8));
}
END_TEST

Suite *suite_strtok() {
  Suite *s = suite_create("s21_strtok");
  TCase *tc = tcase_create("s21_strtok_tc");

  tcase_add_test(tc, test_s21_strtok_1);
  tcase_add_test(tc, test_s21_strtok_2);
  tcase_add_test(tc, test_s21_strtok_3);
  tcase_add_test(tc, test_s21_strtok_4);
  tcase_add_test(tc, test_s21_strtok_5);
  tcase_add_test(tc, test_s21_strtok_6);
  tcase_add_test(tc, test_s21_strtok_7);
  tcase_add_test(tc, test_s21_strtok_8);
  suite_add_tcase(s, tc);
  return s;
}
