#include "s21_sprintf_handlers.h"

int s21_handle_octal(char *buffer, unsigned long int value,
                     struct formatSpecifiers *spec) {
  spec->zero_padding = spec->precision != -1 ? false : spec->zero_padding;
  char temp[20];
  int length = number_to_string(value, spec->precision, temp, 8);
  int width1 = (length > spec->precision ? length : spec->precision);
  int zeroPadding = width1 - length;
  int extraSymbol = spec->sharp_add0numeralSystem;
  int totalWidth = extraSymbol + width1;
  int startIndexDigits = width_padding(buffer, *spec, totalWidth);
  if (spec->sharp_add0numeralSystem) {
    buffer[startIndexDigits++] = '0';
  }
  for (int i = 0; i < zeroPadding; i++) {
    buffer[startIndexDigits++] = '0';
  }
  for (int i = 0; i < length; i++) {
    buffer[startIndexDigits++] = temp[length - i - 1];
  }
  return spec->width > totalWidth ? spec->width : totalWidth;
}
