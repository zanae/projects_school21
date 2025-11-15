#ifndef TESTS_H
#define TESTS_H
#define _POSIX_C_SOURCE 200809L

#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

Suite *suite_create_matrix();
Suite *suite_remove_matrix();
Suite *suite_eq();
Suite *suite_sum();
Suite *suite_sub();
Suite *suite_multn();
Suite *suite_multm();
Suite *suite_transpose();
Suite *suite_complements();
Suite *suite_det();
Suite *suite_inverse();
#endif