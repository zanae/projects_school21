#ifndef S21_SPRINTF_HANDLERS_H
#define S21_SPRINTF_HANDLERS_H

#include "../s21_sprint_scan.h"

//Вспомогательные функции
int width_padding(char *buffer, const struct formatSpecifiers spec,
                  int totalWidth);
int sign_prefix(char *buffer, long int start, bool is_negative,
                const struct formatSpecifiers spec);
int number_to_string(long int value, int precision, char *tmp, unsigned base);

// Обработчики для различных типов данных
int s21_handle_char(char *buffer, char value, struct formatSpecifiers *spec);
int s21_handle_wchar(char *buffer, wchar_t value,
                     struct formatSpecifiers *spec);
int s21_handle_integer(char *buffer, long int value,
                       struct formatSpecifiers *spec);
int s21_handle_float(char *buffer, long double value,
                     struct formatSpecifiers *spec, bool trailingZeroes);
int s21_handle_g(char *buffer, long double value,
                 struct formatSpecifiers *spec);
int s21_handle_string(char *buffer, const char *value,
                      struct formatSpecifiers *spec);
int s21_handle_unsigned(char *buffer, unsigned long int value,
                        struct formatSpecifiers *spec);
int s21_handle_octal(char *buffer, unsigned long int value,
                     struct formatSpecifiers *spec);
int s21_handle_hexadecimal(char *buffer, unsigned long int value,
                           struct formatSpecifiers *spec, int uppercase);
int s21_handle_pointer(char *buffer, void *pointer,
                       struct formatSpecifiers *spec);
int s21_handle_scientific(char *buffer, double value,
                          struct formatSpecifiers *spec, bool trailingZeroes);
#endif