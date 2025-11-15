#include "s21_sprintf_handlers.h"

int s21_handle_pointer(char *buffer, void *pointer,
                       struct formatSpecifiers *spec) {
  unsigned long addr = (unsigned long)pointer;
  spec->sharp_add0numeralSystem = 1;
  spec->precision = -1;
  spec->zero_padding = 0;
  int length = s21_handle_hexadecimal(buffer, addr, spec, 0);
  // шестнадцатеричное представление адреса
  return length;  // общее количество записанных символов включая "0x"
}