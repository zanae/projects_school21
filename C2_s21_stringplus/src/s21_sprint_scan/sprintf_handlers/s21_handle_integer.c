#include "s21_sprintf_handlers.h"

int s21_handle_integer(char *buffer, long int value,
                       struct formatSpecifiers *spec) {
  spec->zero_padding = spec->precision != -1 ? false : spec->zero_padding;
  char temp[20];  // достаточно места для 64-битного целого числа
  int length = number_to_string(value, spec->precision, temp, 10);
  int extraSymbol = value < 0 || spec->space || (spec->plus_sign && value > 0);
  if (spec->zero_padding) {
    // после знака нули размещаем
    if (spec->precision < (spec->width - extraSymbol)) {
      spec->precision = spec->width - extraSymbol;
    }
    spec->width = 0;
  }
  int width1 = length > spec->precision ? length : spec->precision;
  int zeroPadding = width1 - length;
  // еще нужно нули тут распечатать, если zero_padding есть и число < 0
  int totalWidth = extraSymbol + width1;
  int startIndexDigits = width_padding(buffer, *spec, totalWidth);
  startIndexDigits = sign_prefix(buffer, startIndexDigits, (value < 0), *spec);
  for (int i = 0; i < zeroPadding; i++) {
    buffer[startIndexDigits++] = '0';
  }
  for (int i = 0; i < length; i++) {
    // запись цифр в обратном порядке
    buffer[startIndexDigits++] = temp[length - i - 1];
  }
  // Возвращаем общее количество записанных символов
  return spec->width > totalWidth ? spec->width : totalWidth;
}
