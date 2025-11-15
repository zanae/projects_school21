#include "s21_tests.h"

START_TEST(test_s21_strerror_1) {
#if defined(__APPLE__) || defined(__MACH__)
#define S21_ERRLIST_SIZE 107
#else
#define S21_ERRLIST_SIZE 134
#endif
  int invalid_errnums[] = {-1, -100, S21_ERRLIST_SIZE, S21_ERRLIST_SIZE + 100};
  for (size_t i = 0; i < sizeof(invalid_errnums) / sizeof(invalid_errnums[0]);
       i++) {
    ck_assert_str_eq(s21_strerror(invalid_errnums[i]),
                     strerror(invalid_errnums[i]));
  }
}
END_TEST

START_TEST(test_s21_strerror_2) {
#if defined(__APPLE__) || defined(__MACH__)
#define S21_ERRLIST_SIZE 107
#else
#define S21_ERRLIST_SIZE 134
#endif
  for (int i = 0; i < S21_ERRLIST_SIZE; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

Suite *suite_strerror() {
  Suite *s = suite_create("s21_strerror");
  TCase *tc = tcase_create("s21_strerror_tc");

  tcase_add_test(tc, test_s21_strerror_1);
  tcase_add_test(tc, test_s21_strerror_2);
  suite_add_tcase(s, tc);
  return s;
}