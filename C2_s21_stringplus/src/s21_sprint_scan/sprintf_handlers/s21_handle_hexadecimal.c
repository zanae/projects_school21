#include "s21_sprintf_handlers.h"
static int hexNumber_to_string(long int value, int precision, char *tmp,
                               int uppercase) {
  int length = 0;
  if (value == 0 && precision != 0) {
    tmp[length++] = '0';
  }
  while (value > 0) {
    int digit = value % 16;
    if (digit < 10) {
      tmp[length++] = digit + '0';  // Цифры от 0 до 9
    } else {
      tmp[length++] =
          (uppercase ? 'A' : 'a') + (digit - 10);  // Буквы от A до F или a до f
    }
    value /= 16;
  }
  return length;
}

int s21_handle_hexadecimal(char *buffer, unsigned long int value,
                           struct formatSpecifiers *spec,
                           int uppercase) {  // готово
  spec->zero_padding = spec->precision != -1 ? false : spec->zero_padding;
  char temp[20];
  int length = hexNumber_to_string(value, spec->precision, temp, uppercase);
  int width1 = (length > spec->precision ? length : spec->precision);
  int zeroPadding = width1 - length;
  int extraSymbol = spec->sharp_add0numeralSystem;
  int totalWidth = (extraSymbol ? 2 : 0) + width1;
  int startIndexDigits = width_padding(buffer, *spec, totalWidth);
  if (spec->sharp_add0numeralSystem) {
    buffer[startIndexDigits++] = '0';
    buffer[startIndexDigits++] = (uppercase ? 'X' : 'x');
  }
  for (int i = 0; i < zeroPadding; i++) {
    buffer[startIndexDigits++] = '0';
  }
  for (int i = 0; i < length; i++) {
    buffer[startIndexDigits++] = temp[length - i - 1];
  }
  return spec->width > totalWidth ? spec->width : totalWidth;
}
