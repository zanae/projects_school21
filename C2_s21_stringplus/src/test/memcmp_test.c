#include "s21_tests.h"
START_TEST(test_s21_memcmp_1) {
  char str1[] = "Sorry, World!";
  char str2[] = "Sorry, World!";
  s21_size_t len = strlen((char *)str1);
  ck_assert_int_eq(s21_memcmp(&str1, &str2, len), memcmp(&str1, &str2, len));
}
END_TEST

START_TEST(test_s21_memcmp_2) {
  char str1[] = "Torpe";
  char str2[] = "Rotpe";
  s21_size_t len = strlen((char *)str1);
  ck_assert_int_eq(s21_memcmp(&str1, &str2, len), memcmp(&str1, &str2, len));
}
END_TEST

START_TEST(test_s21_memcmp_3) {
  char str5[] = "Sor\0ry";
  char str6[] = "Sor\0ry";
  s21_size_t len3 = 6;
  ck_assert_int_eq(s21_memcmp(str5, str6, len3), memcmp(str5, str6, len3));
}
END_TEST

START_TEST(test_s21_memcmp_4) {
  char str7[] = "\0";
  char str8[] = "\0";
  s21_size_t len4 = 1;
  ck_assert_int_eq(s21_memcmp(str7, str8, len4), memcmp(str7, str8, len4));
}
END_TEST

START_TEST(test_s21_memcmp_5) {
  char str9[] = "";
  char str10[] = "";
  s21_size_t len5 = 0;
  ck_assert_int_eq(s21_memcmp(str9, str10, len5), memcmp(str9, str10, len5));
}
END_TEST

START_TEST(test_s21_memcmp_6) {
  unsigned char bytes1[] = {1, 2, 3, 4, 5};
  unsigned char bytes2[] = {1, 2, 3, 4, 5};
  s21_size_t len6 = sizeof(bytes1);
  ck_assert_int_eq(s21_memcmp(bytes1, bytes2, len6),
                   memcmp(bytes1, bytes2, len6));
}
END_TEST

Suite *suite_memcmp() {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc = tcase_create("s21_memcmp_tc");

  tcase_add_test(tc, test_s21_memcmp_1);
  tcase_add_test(tc, test_s21_memcmp_2);
  tcase_add_test(tc, test_s21_memcmp_3);
  tcase_add_test(tc, test_s21_memcmp_4);
  tcase_add_test(tc, test_s21_memcmp_5);
  tcase_add_test(tc, test_s21_memcmp_6);
  suite_add_tcase(s, tc);
  return s;
}
