#include "s21_sprintf_handlers.h"
int width_padding(char* buffer, const struct formatSpecifiers spec,
                  int totalWidth) {
  int start = spec.minus_left_align ? totalWidth : 0,
      end_padding = spec.width - totalWidth;
  if (spec.width > totalWidth) {
    char fillChar = ' ';
    if (!spec.minus_left_align && spec.zero_padding) fillChar = '0';
    for (int i = start; i < start + end_padding; i++) {
      buffer[i] = fillChar;
    }
  }
  return spec.width <= totalWidth || spec.minus_left_align ? 0 : end_padding;
}
int sign_prefix(char* buffer, long int start, bool is_negative,
                const struct formatSpecifiers spec) {
  if (is_negative) {
    buffer[start++] = '-';
  } else if (spec.plus_sign) {
    buffer[start++] = '+';
  } else if (spec.space) {
    buffer[start++] = ' ';
  }
  return start;
}

int number_to_string(long int value, int precision, char* tmp, unsigned base) {
  int length = 0;
  value = labs(value);
  if (value == 0 && precision != 0) {
    tmp[length++] = '0';
  }
  while (value > 0) {
    tmp[length++] = (value % base) + '0';
    // base - основание системы счисления
    value = value / base;
  }
  return length;
}