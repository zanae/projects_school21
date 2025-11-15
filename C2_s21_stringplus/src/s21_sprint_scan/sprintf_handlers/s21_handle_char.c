#include "s21_sprintf_handlers.h"

int s21_handle_char(char *buffer, char value, struct formatSpecifiers *spec) {
  if (spec->width > 0) {
    if (spec->minus_left_align) {
      buffer[0] = value;
      for (int i = 0; i < spec->width - 1; i++) {
        buffer[i + 1] = ' ';
      }
    } else {
      int i = 0;
      while (i < spec->width - 1) {
        buffer[i++] = ' ';
      }
      buffer[i] = value;
    }
  } else {
    buffer[0] = value;
  }
  return spec->width > 0 ? spec->width : 1;
  // Возвращаем количество записанных символов
}