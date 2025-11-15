#include "s21_sprintf_handlers.h"

int s21_handle_g(char *buffer, long double value,
                 struct formatSpecifiers *spec) {
  int P = 0;
  if (spec->precision == -1) {
    P = 6;
  } else if (spec->precision == 0) {
    P = 1;
  } else {
    P = spec->precision;
  }
  int exponent = value == 0.0 ? 0.0 : floor(log10(fabsl(value)));
  int written = 0;
  if (P > exponent && exponent >= -4) {
    spec->precision = (P - (exponent + 1));
    written = s21_handle_float(buffer, value, spec, false);
  } else {
    spec->precision = P - 1;
    written = s21_handle_scientific(buffer, value, spec, false);
  }
  return written;
}