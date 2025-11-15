#include "s21_tests.h"

START_TEST(test_s21_sprintf_1) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%6.2s", "world");
  int res2 = s21_sprintf(str2, "%6.2s", "world");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_2) {
  char str1[1000];
  char str2[1000];
  int res1 = sprintf(str1, "%%");
  int res2 = s21_sprintf(str2, "%%");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_3) {
  char str1[1000];
  char str2[1000];
  int res1 = sprintf(str1, "%*.*f", 10, 5, 123.456);
  int res2 = s21_sprintf(str2, "%*.*f", 10, 5, 123.456);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_4) {
  char str1[1000];
  char str2[1000];
  int res1 = sprintf(str1, "%*s%c%*d", 5, "test", 'x', 3, 42);
  int res2 = s21_sprintf(str2, "%*s%c%*d", 5, "test", 'x', 3, 42);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_5) {
  char str1[1000];
  char str2[1000];
  int x = 10;
  int res1 = sprintf(str1, "%20.3f %d %d %d", 1.001, x + 1, x + 2, x + 3);
  int res2 = s21_sprintf(str2, "%20.3f %d %d %d", 1.001, x + 1, x + 2, x + 3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_6) {
  char str1[1000];
  char str2[1000];
  int res1 = sprintf(str1, "%.16f", 10.2);
  int res2 = s21_sprintf(str2, "%.16f", 10.2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_7) {
  char str1[1000];
  char str2[1000];
  int res1 = sprintf(str1, "%*f %*f %*f\n", 20, 10.2, 30, 10.53423, 18, 0.01);
  int res2 =
      s21_sprintf(str2, "%*f %*f %*f\n", 20, 10.2, 30, 10.53423, 18, 0.01);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_8) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%*f %*f %*f\n", 20, 10.2, 30, 10.53423, 18, 0.01);
  int res2 =
      s21_sprintf(str2, "%*f %*f %*f\n", 20, 10.2, 30, 10.53423, 18, 0.01);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_9) {
  char str1[1000];
  char str2[1000];
  int res1 = sprintf(str1, "%.17f\n", 1.00001);
  int res2 = s21_sprintf(str2, "%.17f\n", 1.00001);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_10) {
  char str1[1000];
  char str2[1000];

  int res1 =
      sprintf(str1, "abc %+*.10lf def %5.5f ghi %-5c", 10, 20.20, 1000.43, 'X');
  int res2 = s21_sprintf(str2, "abc %+*.10lf def %5.5f ghi %-5c", 10, 20.20,
                         1000.43, 'X');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_11) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%78.16f", 123.12555);
  int res2 = s21_sprintf(str2, "%78.16f", 123.12555);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_12) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%78.64f", 0.0);
  int res2 = s21_sprintf(str2, "%78.64f", 0.0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_13) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%78.64d", 50);
  int res2 = s21_sprintf(str2, "%78.64d", 50);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_14) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%.*s", 7, "Goodbye World!");
  int res2 = s21_sprintf(str2, "%.*s", 7, "Goodbye World!");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_15) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%*c  %s %.*s", 5, 'H', "mem", 7, "Goodbye World!");
  int res2 =
      s21_sprintf(str2, "%*c  %s %.*s", 5, 'H', "mem", 7, "Goodbye World!");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_16) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%-10d 1", 42);
  int res2 = s21_sprintf(str2, "%-10d 1", 42);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_17) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%*c  %s %.*s", 5, 'H', "mem", 7, "Goodbye World!");
  int res2 =
      s21_sprintf(str2, "%*c  %s %.*s", 5, 'H', "mem", 7, "Goodbye World!");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_18) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%.7f\n", -0.123);
  int res2 = s21_sprintf(str2, "%.7f\n", -0.123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_19) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%+.7e\n", 0.123);
  int res2 = s21_sprintf(str2, "%+.7e\n", 0.123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}

START_TEST(test_s21_sprintf_20) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%+.7E\n", 0.123456789);
  int res2 = s21_sprintf(str2, "%+.7E\n", 0.123456789);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_21) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "% .7E\n", 0.123456789);
  int res2 = s21_sprintf(str2, "% .7E\n", 0.123456789);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_22) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "% .7E\n", -0.123456789);
  int res2 = s21_sprintf(str2, "% .7E\n", -0.123456789);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_23) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "% .7g\n", 0.123456789);
  int res2 = s21_sprintf(str2, "% .7g\n", 0.123456789);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_24) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "_%+04d_\n", -2);
  int res2 = s21_sprintf(str2, "_%+04d_\n", -2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_25) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "_%+4d_\n", -2);
  int res2 = s21_sprintf(str2, "_%+4d_\n", -2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_26) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "_%+4d_\n", 255);
  int res2 = s21_sprintf(str2, "_%+4d_\n", 255);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_27) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "_% 4d_\n", 2);
  int res2 = s21_sprintf(str2, "_% 4d_\n", 2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_28) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "_%15.0e_\n", 1.0);
  int res2 = s21_sprintf(str2, "_%15.0e_\n", 1.0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_29) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "_%15.13E_\n", -0.1231231123);
  int res2 = s21_sprintf(str2, "_%15.13E_\n", -0.1231231123);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_30) {
  char str1[1000];
  char str2[1000];

  double b = 123456.0;
  int res1 =
      sprintf(str1, "%e, %f, %g, %0#e, %0#f, %0#g, %-32.5e, %-32.5f, %-32.5g\n",
              b, b, b, b, b, b, b, b, b);
  int res2 = s21_sprintf(
      str2, "%e, %f, %g, %0#e, %0#f, %0#g, %-32.5e, %-32.5f, %-32.5g\n", b, b,
      b, b, b, b, b, b, b);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_31) {
  char str1[1000];
  char str2[1000];

  double b = 1234567.0;
  int res1 =
      sprintf(str1, "%e, %f, %G, %0#e, %0#f, %0#g, %-32.5e, %-32.5f, %-32.5g\n",
              b, b, b, b, b, b, b, b, b);
  int res2 = s21_sprintf(
      str2, "%e, %f, %G, %0#e, %0#f, %0#g, %-32.5e, %-32.5f, %-32.5g\n", b, b,
      b, b, b, b, b, b, b);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_32) {
  char str1[1000];
  char str2[1000];

  double b = -54.0;
  int res1 = sprintf(
      str1, "%e, %f, %g, %0#e, %0#f, %0#g, %-32.5e, %-32.5f, %.f, %-32.5g\n", b,
      b, b, b, b, b, b, b, b, b);
  int res2 = s21_sprintf(
      str2, "%e, %f, %g, %0#e, %0#f, %0#g, %-32.5e, %-32.5f, %.f, %-32.5g\n", b,
      b, b, b, b, b, b, b, b, b);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_33) {
  char str1[1000];
  char str2[1000];

  int a;
  int res1 = sprintf(str1, "%p, %13p, %12p, %-12p\n", (void *)&a, (void *)&a,
                     (void *)&a, (void *)&a);
  int res2 = s21_sprintf(str2, "%p, %13p, %12p, %-12p\n", (void *)&a,
                         (void *)&a, (void *)&a, (void *)&a);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_34) {
  char str1[1000];
  char str2[1000];

  const char *format = "Goodbye %nworld";
  int n1 = 0, n2 = 0;
  int res1 = s21_sprintf(str1, format, &n1);
  int res2 = sprintf(str2, format, &n2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_35) {
  char str1[1000];
  char str2[1000];

  unsigned int num = 123456;
  int res1 = sprintf(str1, "%u, %X, %x, %x\n", num, num, num, 0);
  int res2 = s21_sprintf(str2, "%u, %X, %x, %x\n", num, num, num, 0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_36) {
  char str1[1000];
  char str2[1000];

  unsigned int num2 = 123456;
  int res1 = sprintf(str1, "minus 16.9 hi %-16.9hi\n", num2);
  int res2 = s21_sprintf(str2, "minus 16.9 hi %-16.9hi\n", num2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_37) {
  char str1[1000];
  char str2[1000];

  unsigned int num3 = 123456;
  int res1 = sprintf(str1, "%o\n", num3);
  int res2 = s21_sprintf(str2, "%o\n", num3);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_38) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%11ld %-11hi", 9999999999, 255);
  int res2 = s21_sprintf(str2, "%11ld %-11hi", 9999999999, 255);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_39) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%11ld %-11lf", 999999999999999999,
                     1234567890123456789.7868685857557);
  int res2 = s21_sprintf(str2, "%11ld %-11lf", 999999999999999999,
                         1234567890123456789.7868685857557);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_40) {
  char str1[1000];
  char str2[1000];

  int res1 =
      sprintf(str1, "%11lu %-11hu %2.4hu", 1234567890123456789, 255, 255);
  int res2 =
      s21_sprintf(str2, "%11lu %-11hu %2.4hu", 1234567890123456789, 255, 255);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_41) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%o %lo %-11ho %#-2.o %7.4o", 12345670,
                     123456701234567, 255, 255, 255);
  int res2 = s21_sprintf(str2, "%o %lo %-11ho %#-2.o %7.4o", 12345670,
                         123456701234567, 255, 255, 255);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_42) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%09x %lx %-11hx %.9X", 12345670, 123456701234567,
                     255, 12345670);
  int res2 = s21_sprintf(str2, "%09x %lx %-11hx %.9X", 12345670,
                         123456701234567, 255, 12345670);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_43) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%X %lX %-11hX", 12345670, 123456701234567, 255);
  int res2 = s21_sprintf(str2, "%X %lX %-11hX", 12345670, 123456701234567, 255);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_44) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%lf", 992474207.387724974987149);
  int res2 = s21_sprintf(str2, "%lf", 992474207.387724974987149);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_45) {
  char str1[1000];
  char str2[1000];

  int res1 = sprintf(str1, "%.19Lf", 7.515151515151515151515151L);
  int res2 = s21_sprintf(str2, "%.19Lf", 7.515151515151515151515151L);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_46) {
  char str1[1000];
  char str2[1000];
  int a = 999999;
  double b = 0.9999999;
  int res1 = sprintf(str1, "%09u %.9f %.9E", a, b, b);
  int res2 = s21_sprintf(str2, "%09u %.9f %.9E", a, b, b);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_47) {
  char str1[1000];
  char str2[1000];
  double b = 7.515151515;
  int res1 = sprintf(str1, "%.2g %.G %.f %.e %.E", b, b, b, b, b);
  int res2 = s21_sprintf(str2, "%.2g %.G %.f %.e %.E", b, b, b, b, b);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_48) {
  char str1[1000];
  char str2[1000];

  setlocale(LC_ALL, "");
  int res1 = sprintf(str1, "wchar %18lc", L'在');
  int res2 = s21_sprintf(str2, "wchar %18lc", L'在');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_49) {
  char str1[1000];
  char str2[1000];

  setlocale(LC_ALL, "");
  int res1 = sprintf(str1, "wchar %-11lc", L'在');
  int res2 = s21_sprintf(str2, "wchar %-11lc", L'在');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_50) {
  char str1[1000];
  char str2[1000];

  setlocale(LC_ALL, "");
  int res1 = sprintf(str1, "wchar %lc", L'在');
  int res2 = s21_sprintf(str2, "wchar %lc", L'在');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *suite_sprintf() {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc = tcase_create("s21_sprintf_tc");

  tcase_add_test(tc, test_s21_sprintf_1);
  tcase_add_test(tc, test_s21_sprintf_2);
  tcase_add_test(tc, test_s21_sprintf_3);
  tcase_add_test(tc, test_s21_sprintf_4);
  tcase_add_test(tc, test_s21_sprintf_5);
  tcase_add_test(tc, test_s21_sprintf_6);
  tcase_add_test(tc, test_s21_sprintf_7);
  tcase_add_test(tc, test_s21_sprintf_8);
  tcase_add_test(tc, test_s21_sprintf_9);
  tcase_add_test(tc, test_s21_sprintf_10);
  tcase_add_test(tc, test_s21_sprintf_11);
  tcase_add_test(tc, test_s21_sprintf_12);
  tcase_add_test(tc, test_s21_sprintf_13);
  tcase_add_test(tc, test_s21_sprintf_14);
  tcase_add_test(tc, test_s21_sprintf_15);
  tcase_add_test(tc, test_s21_sprintf_16);
  tcase_add_test(tc, test_s21_sprintf_17);
  tcase_add_test(tc, test_s21_sprintf_18);
  tcase_add_test(tc, test_s21_sprintf_19);
  tcase_add_test(tc, test_s21_sprintf_20);
  tcase_add_test(tc, test_s21_sprintf_21);
  tcase_add_test(tc, test_s21_sprintf_22);
  tcase_add_test(tc, test_s21_sprintf_23);
  tcase_add_test(tc, test_s21_sprintf_24);
  tcase_add_test(tc, test_s21_sprintf_25);
  tcase_add_test(tc, test_s21_sprintf_26);
  tcase_add_test(tc, test_s21_sprintf_27);
  tcase_add_test(tc, test_s21_sprintf_28);
  tcase_add_test(tc, test_s21_sprintf_29);
  tcase_add_test(tc, test_s21_sprintf_30);
  tcase_add_test(tc, test_s21_sprintf_31);
  tcase_add_test(tc, test_s21_sprintf_32);
  tcase_add_test(tc, test_s21_sprintf_33);
  tcase_add_test(tc, test_s21_sprintf_34);
  tcase_add_test(tc, test_s21_sprintf_35);
  tcase_add_test(tc, test_s21_sprintf_36);
  tcase_add_test(tc, test_s21_sprintf_37);
  tcase_add_test(tc, test_s21_sprintf_38);
  tcase_add_test(tc, test_s21_sprintf_39);
  tcase_add_test(tc, test_s21_sprintf_40);
  tcase_add_test(tc, test_s21_sprintf_41);
  tcase_add_test(tc, test_s21_sprintf_42);
  tcase_add_test(tc, test_s21_sprintf_43);
  tcase_add_test(tc, test_s21_sprintf_44);
  tcase_add_test(tc, test_s21_sprintf_45);
  tcase_add_test(tc, test_s21_sprintf_46);
  tcase_add_test(tc, test_s21_sprintf_47);
  tcase_add_test(tc, test_s21_sprintf_48);
  tcase_add_test(tc, test_s21_sprintf_49);
  tcase_add_test(tc, test_s21_sprintf_50);
  suite_add_tcase(s, tc);
  return s;
}