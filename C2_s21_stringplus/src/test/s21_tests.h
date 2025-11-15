#ifndef S21_TESTS_H
#define S21_TESTS_H

#define _POSIX_C_SOURCE 200809L

#include <check.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

#include "../s21_sprint_scan/s21_sprint_scan.h"
#include "../s21_string.h"

Suite *suite_memchr();
Suite *suite_memcmp();
Suite *suite_memcpy();
Suite *suite_memset();
Suite *suite_strncat();
Suite *suite_strlen();
Suite *suite_strchr();
Suite *suite_strncmp();
Suite *suite_strncpy();
Suite *suite_strcspn();
Suite *suite_strerror();
Suite *suite_strpbrk();
Suite *suite_strrchr();
Suite *suite_strstr();
Suite *suite_strtok();
Suite *suite_sprintf();
Suite *suite_strcpy();
Suite *suite_strerror();
Suite *suite_sprintf();
Suite *suite_to_upper();
Suite *suite_to_lower();
Suite *suite_insert();
Suite *suite_trim();

#endif
