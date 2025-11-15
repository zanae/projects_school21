#include "s21_sprintf_handlers.h"

int s21_handle_unsigned(char *buffer, unsigned long int value,
                        struct formatSpecifiers *spec) {  // готово
  spec->zero_padding = spec->precision != -1 ? false : spec->zero_padding;
  char temp[20];  // Достаточно места для 64-битного целого числа
  int length = number_to_string(value, spec->precision, temp, 10);
  int totalWidth = (length > spec->precision ? length : spec->precision);
  int zeroPadding = totalWidth - length;
  int startIndexDigits = width_padding(buffer, *spec, totalWidth);
  for (int i = 0; i < zeroPadding; i++) {
    buffer[startIndexDigits++] = '0';
  }
  for (int i = 0; i < length; i++) {
    buffer[startIndexDigits++] = temp[length - i - 1];
  }
  // Возвращаем общее количество записанных символов
  return spec->width > totalWidth ? spec->width : totalWidth;
}
