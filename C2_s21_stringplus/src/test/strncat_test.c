#include "s21_tests.h"

START_TEST(test_s21_strncat_1) {
  char dest1[50] = "Goodbye, ";
  char dest2[50] = "Goodbye, ";
  const char src[] = "World!";
  s21_size_t n1 = 8;
  ck_assert_ptr_eq(s21_strncat(dest1, src, n1), dest1);
  ck_assert_ptr_eq(strncat(dest2, src, n1), dest2);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_strncat_2) {
  char dest3[50] = "Goodbye ";
  char dest4[50] = "Goodbye ";
  const char src2[] = "World";
  s21_size_t n2 = 6;
  ck_assert_ptr_eq(s21_strncat(dest3, src2, n2), dest3);
  ck_assert_ptr_eq(strncat(dest4, src2, n2), dest4);
  ck_assert_str_eq(dest3, dest4);
}
END_TEST

START_TEST(test_s21_strncat_3) {
  char dest5[50] = "Goodbye world: ";
  char dest6[50] = "Goodbye world: ";
  const char src3[] = "";
  s21_size_t n3 = 7;
  ck_assert_ptr_eq(s21_strncat(dest5, src3, n3), dest5);
  ck_assert_ptr_eq(strncat(dest6, src3, n3), dest6);
  ck_assert_str_eq(dest5, dest6);
}
END_TEST

START_TEST(test_s21_strncat_4) {
  char dest7[50] = "Goodbye world test: ";
  char dest8[50] = "Goodbye world test: ";
  const char src4[] = "Egfbd cfv dl ropjs";
  s21_size_t n4 = 0;
  ck_assert_ptr_eq(s21_strncat(dest7, src4, n4), dest7);
  ck_assert_ptr_eq(strncat(dest8, src4, n4), dest8);
  ck_assert_str_eq(dest7, dest8);
}
END_TEST

START_TEST(test_s21_strncat_5) {
  char dest9[50] = "Kpajvbyo pamt: ";
  char dest10[50] = "Kpajvbyo pamt: ";
  const char src5[] = "Fpamt";
  s21_size_t n5 = 10;
  ck_assert_ptr_eq(s21_strncat(dest9, src5, n5), dest9);
  ck_assert_ptr_eq(strncat(dest10, src5, n5), dest10);
  ck_assert_str_eq(dest9, dest10);
}
END_TEST

START_TEST(test_s21_strncat_6) {
  char dest11[50] = "";
  char dest12[50] = "";
  const char src6[] = "Fpp pi aloym";
  s21_size_t n6 = 12;
  ck_assert_ptr_eq(s21_strncat(dest11, src6, n6), dest11);
  ck_assert_ptr_eq(strncat(dest12, src6, n6), dest12);
  ck_assert_str_eq(dest11, dest12);
}
END_TEST

Suite *suite_strncat() {
  Suite *s = suite_create("s21_strncat");
  TCase *tc = tcase_create("s21_strncat_tc");

  tcase_add_test(tc, test_s21_strncat_1);
  tcase_add_test(tc, test_s21_strncat_2);
  tcase_add_test(tc, test_s21_strncat_3);
  tcase_add_test(tc, test_s21_strncat_4);
  tcase_add_test(tc, test_s21_strncat_5);
  tcase_add_test(tc, test_s21_strncat_6);
  suite_add_tcase(s, tc);
  return s;
}
