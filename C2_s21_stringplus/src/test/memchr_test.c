#include "s21_tests.h"

START_TEST(s21_memchr_1) {
  const char str[] = "Goodbye, World!";
  int ch = 'W';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(s21_memchr(str, ch, len), memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_2) {
  char str[] = "Goodbye, World!";
  int ch = 'X';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(s21_memchr(str, ch, len), memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_3) {
  char str[] = "";
  int ch = ' ';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(s21_memchr(str, ch, len), memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_4) {
  char str[] = "\0";
  int ch = '\0';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(s21_memchr(str, ch, len), memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_5) {
  char str[] = "Goodbye\0World!";
  int ch = '\0';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(s21_memchr(str, ch, len), memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_6) {
  unsigned char bytes[] = {2, 3, 4, 5, 6};
  int ch = 4;
  s21_size_t len = sizeof(bytes);
  ck_assert_ptr_eq(s21_memchr(bytes, ch, len), memchr(bytes, ch, len));
}
END_TEST

START_TEST(s21_memchr_7) {
  const char *str = "\x01\x02\x03";
  int ch = '\x02';
  size_t n = strlen(str);
  void *result = s21_memchr(str, ch, n);
  void *result2 = memchr(str, ch, n);
  ck_assert_ptr_eq(result, result2);
}
END_TEST

START_TEST(s21_memchr_8) {
  unsigned char str[] = {0xFF, 0xFE, 0xFF};
  int ch = -1;
  size_t n = strlen((char *)str);
  void *result = s21_memchr(str, ch, n);
  void *result2 = memchr(str, ch, n);
  ck_assert_ptr_eq(result, result2);
}
END_TEST

START_TEST(s21_memchr_9) {
  const char *str = "\0Goodbye, World!";
  int ch = '\0';
  size_t n = strlen(str);
  void *result = s21_memchr(str, ch, n);
  void *result2 = memchr(str, ch, n);
  ck_assert_ptr_eq(result, result2);
}
END_TEST

START_TEST(s21_memchr_10) {
  const char *str = "Goodbye, World!\0";
  int ch = '\0';
  size_t n = strlen(str);
  void *result = s21_memchr(str, ch, n);
  void *result2 = memchr(str, ch, n);
  ck_assert_ptr_eq(result, result2);
}
END_TEST

START_TEST(s21_memchr_11) {
  const char *str = "Schoo, World!";
  int ch = 'W';
  size_t n = 14;
  void *result = s21_memchr(str, ch, n);
  void *result2 = memchr(str, ch, n);
  ck_assert_ptr_eq(result, result2);
}
END_TEST

START_TEST(s21_memchr_12) {
  const char *str = "Goodbye, World!";
  int ch = 'o';
  size_t n = 0;
  void *result = s21_memchr(str, ch, n);
  void *result2 = memchr(str, ch, n);
  ck_assert_ptr_eq(result, result2);
}
END_TEST

START_TEST(s21_memchr_13) {
  const char *str = "Goodbye, World!";
  int ch = 'H';
  size_t n = strlen(str);
  void *result = s21_memchr(str, ch, n);
  void *result2 = memchr(str, ch, n);
  ck_assert_ptr_eq(result, result2);
}
END_TEST

START_TEST(s21_memchr_14) {
  const char *str = "Goodbye, World!";
  int ch = '!';
  size_t n = strlen(str);
  void *result = s21_memchr(str, ch, n);
  void *expected = memchr(str, ch, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(s21_memchr_15) {
  const char *str = "Fyrio, World!";
  int ch = 'o';
  size_t n = strlen(str);
  void *result = s21_memchr(str, ch, n);
  void *result2 = memchr(str, ch, n);
  ck_assert_ptr_eq(result, result2);
}
END_TEST

Suite *suite_memchr() {
  Suite *s = suite_create("s21_memchr");
  TCase *tc = tcase_create("s21_memchr_tc");

  tcase_add_test(tc, s21_memchr_1);
  tcase_add_test(tc, s21_memchr_2);
  tcase_add_test(tc, s21_memchr_3);
  tcase_add_test(tc, s21_memchr_4);
  tcase_add_test(tc, s21_memchr_5);
  tcase_add_test(tc, s21_memchr_6);
  tcase_add_test(tc, s21_memchr_7);
  tcase_add_test(tc, s21_memchr_8);
  tcase_add_test(tc, s21_memchr_9);
  tcase_add_test(tc, s21_memchr_10);
  tcase_add_test(tc, s21_memchr_11);
  tcase_add_test(tc, s21_memchr_12);
  tcase_add_test(tc, s21_memchr_13);
  tcase_add_test(tc, s21_memchr_14);
  tcase_add_test(tc, s21_memchr_15);
  suite_add_tcase(s, tc);
  return s;
}
