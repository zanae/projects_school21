#include "s21_sprintf_handlers.h"

int s21_handle_string(char *buffer, const char *value,
                      struct formatSpecifiers *spec) {
  s21_size_t len = 0;
  while (value[len] != '\0') {
    len++;
  }
  if (spec->precision >= 0 && (s21_size_t)spec->precision < len) {
    len = spec->precision;
  }
  int total_len = (int)len;
  int padding = spec->width - total_len;
  int i = 0;
  while (i < padding && i < spec->width) {
    buffer[i++] = ' ';
  }
  for (s21_size_t j = 0; j < len; j++) {
    buffer[i++] = value[j];
  }
  buffer[i] = '\0';
  return spec->width > total_len ? spec->width : total_len;
}
