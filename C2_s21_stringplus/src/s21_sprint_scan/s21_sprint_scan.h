#ifndef S21_SPRINT_SCAH_H
#define S21_SPRINT_SCAH_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <wchar.h>

#include "../s21_string.h"

struct formatSpecifiers {
  char specifier;         // спецификатор
  bool star_width;        // *
  int width;              // ширина
  bool star_precision;    // *
  int precision;          // точность
  bool minus_left_align;  // -
  bool plus_sign;         // + ('8' => '+8')
  bool space;  // ' ' перед положительными ('8' => ' 8')
  bool sharp_add0numeralSystem;  // # 0x, 0X для 8- и 16-ричной систем
  bool zero_padding;             // 0 заполнение нулями
  char length;                   // h, l, L
};

int s21_sprintf(char *buffer, const char *format, ...);
int s21_sscanf(const char *str, const char *format, ...);

void s21_set_specifier(const char **format, struct formatSpecifiers *spec,
                       va_list *args);
#endif