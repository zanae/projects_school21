#include "s21_sprint_scan.h"

static void s21_parse_format(const char **format,
                             struct formatSpecifiers *spec);

void s21_set_specifier(const char **format, struct formatSpecifiers *spec,
                       va_list *args) {
  spec->precision = -1;
  s21_parse_format(format, spec);
  if (spec->star_width) spec->width = va_arg(*args, int);
  if (spec->star_precision) spec->precision = va_arg(*args, int);
  if (spec->precision == -1 && s21_strchr("feE", spec->specifier))
    spec->precision = 6;
}

static void s21_parse_format(const char **format,
                             struct formatSpecifiers *spec) {
  int exitLoop = 0;
  while (exitLoop == 0 && **format) {
    int moveFormat = 1;
    if (**format == '-') {
      spec->minus_left_align = true;
    } else if (**format == '+') {
      spec->plus_sign = true;
    } else if (**format == ' ') {
      spec->space = true;
    } else if (**format == '0') {
      spec->zero_padding = true;
    } else if (**format == '#') {
      spec->sharp_add0numeralSystem = true;
    } else if (**format == '*') {
      spec->star_width = true;
    } else if (**format >= '1' && **format <= '9') {
      spec->width = strtol(*format, (char **)format, 10);
      moveFormat = 0;  // continue;
    } else if (**format == '.') {
      (*format)++;
      if (**format == '*') {
        spec->star_precision = true;
        (*format)++;
      } else {
        if (**format >= '0' && **format <= '9') {
          spec->precision = strtol(*format, (char **)format, 10);
        } else {  // числа может не быть, тогда считаем точность за 0
          spec->precision = 0;
        }
      }
      moveFormat = 0;  // continue;
    } else if (s21_strchr("hlL", **format)) {
      spec->length = **format;
    } else  // if (s21_strchr("cdfsugGeExXop", **format))
    {
      spec->specifier = **format;  // спецификатор c d f s u g G e E x X o p
      exitLoop = 1;  // выходим из цикла после нахождения спецификатора
    }
    if (!exitLoop && moveFormat) {
      (*format)++;
    }
  }
}