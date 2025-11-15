#include "s21_tests.h"

START_TEST(test_s21_to_lower_1) {
  const char *str = "";
  char *result = (char *)s21_to_lower(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_lower_2) {
  char *result = s21_to_lower(S21_NULL);
  // ck_assert_ptr_null(result);
  ck_assert_pstr_eq(result, S21_NULL);
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_lower_3) {
  const char *str = "SORRY";
  char *result = (char *)s21_to_lower(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "sorry");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_lower_4) {
  const char *str = "SoRRy";
  char *result = (char *)s21_to_lower(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "sorry");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_lower_5) {
  const char *str = "sorry";
  char *result = (char *)s21_to_lower(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "sorry");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_lower_6) {
  const char *str = "GOODBYE WORLD";
  char *result = (char *)s21_to_lower(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "goodbye world");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_lower_7) {
  const char *str = "   ";
  char *result = (char *)s21_to_lower(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "   ");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_lower_8) {
  const char *str = "I";
  char *result = (char *)s21_to_lower(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "i");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_lower_9) {
  const char *str = "GOODBYE544";
  char *result = (char *)s21_to_lower(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "goodbye544");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_lower_10) {
  const char *str = "GOODBYE\tWORLD\n";
  char *result = (char *)s21_to_lower(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "goodbye\tworld\n");
  if (result) free(result);
}
END_TEST

Suite *suite_to_lower() {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc = tcase_create("s21_to_lower_tc");

  tcase_add_test(tc, test_s21_to_lower_1);
  tcase_add_test(tc, test_s21_to_lower_2);
  tcase_add_test(tc, test_s21_to_lower_3);
  tcase_add_test(tc, test_s21_to_lower_4);
  tcase_add_test(tc, test_s21_to_lower_5);
  tcase_add_test(tc, test_s21_to_lower_6);
  tcase_add_test(tc, test_s21_to_lower_7);
  tcase_add_test(tc, test_s21_to_lower_8);
  tcase_add_test(tc, test_s21_to_lower_9);
  tcase_add_test(tc, test_s21_to_lower_10);
  suite_add_tcase(s, tc);
  return s;
}