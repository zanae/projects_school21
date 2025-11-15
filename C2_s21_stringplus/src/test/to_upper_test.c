#include "s21_tests.h"

START_TEST(test_s21_to_upper_1) {
  const char *str = "goodbye";
  char *result = (char *)s21_to_upper(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "GOODBYE");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_upper_2) {
  const char *str = "Goodbye WoRLD";
  char *result = (char *)s21_to_upper(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "GOODBYE WORLD");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_upper_3) {
  const char *str = "GOODBYE";
  char *result = (char *)s21_to_upper(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "GOODBYE");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_upper_4) {
  const char *str = "";
  char *result = (char *)s21_to_upper(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_upper_5) {
  const char *str = "goodbye world";
  char *result = (char *)s21_to_upper(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "GOODBYE WORLD");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_upper_6) {
  const char *str = "   ";
  char *result = (char *)s21_to_upper(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "   ");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_upper_7) {
  char *result = s21_to_upper(S21_NULL);
  // ck_assert_ptr_null(result);
  ck_assert_pstr_eq(result, S21_NULL);
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_upper_8) {
  const char *str = "goodbye123";
  char *result = (char *)s21_to_upper(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "GOODBYE123");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_upper_9) {
  const char *str = "goodbye&!@";
  char *result = (char *)s21_to_upper(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "GOODBYE&!@");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_upper_10) {
  const char *str =
      "evjnskdv jvnklefe wfiqokaeg rnvjkvnfd wivnffnve rigvbtbeuvn eirvotnr";
  char *result = (char *)s21_to_upper(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(
      result,
      "EVJNSKDV JVNKLEFE WFIQOKAEG RNVJKVNFD WIVNFFNVE RIGVBTBEUVN EIRVOTNR");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_upper_11) {
  const char *str = "goodbye world";
  char *result = (char *)s21_to_upper(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "GOODBYE WORLD");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_to_upper_12) {
  const char *str = "t";
  char *result = (char *)s21_to_upper(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "T");
  if (result) free(result);
}
END_TEST

Suite *suite_to_upper() {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc = tcase_create("s21_to_upper_tc");

  tcase_add_test(tc, test_s21_to_upper_1);
  tcase_add_test(tc, test_s21_to_upper_2);
  tcase_add_test(tc, test_s21_to_upper_3);
  tcase_add_test(tc, test_s21_to_upper_4);
  tcase_add_test(tc, test_s21_to_upper_5);
  tcase_add_test(tc, test_s21_to_upper_6);
  tcase_add_test(tc, test_s21_to_upper_7);
  tcase_add_test(tc, test_s21_to_upper_8);
  tcase_add_test(tc, test_s21_to_upper_9);
  tcase_add_test(tc, test_s21_to_upper_10);
  tcase_add_test(tc, test_s21_to_upper_11);
  tcase_add_test(tc, test_s21_to_upper_12);
  suite_add_tcase(s, tc);
  return s;
}