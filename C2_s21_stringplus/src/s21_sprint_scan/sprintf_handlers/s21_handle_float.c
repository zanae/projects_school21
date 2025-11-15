#include "s21_sprintf_handlers.h"

int s21_handle_float(char *buffer, long double value,
                     struct formatSpecifiers *spec, bool trailingZeroes) {
  if (spec->precision == 0) value = roundl(value);
  long int integer_part = (long int)value;
  long double fractional_part = fabsl(value - integer_part);
  spec->zero_padding = spec->precision != -1 ? false : spec->zero_padding;
  char temp[20];  // для целой части
  int length = number_to_string(integer_part, spec->precision, temp, 10);
  long double fractional_scaled = fractional_part * pow(10, spec->precision);
  long int frac_int = (long int)(fractional_scaled + 0.5L);
  if (spec->sharp_add0numeralSystem) {
    trailingZeroes = true;
  }
  int decimalPartLen =
      spec->precision +
      ((spec->precision > 0 || spec->sharp_add0numeralSystem) ? 1 : 0);
  if (frac_int == 0 && !trailingZeroes) {
    decimalPartLen = 0;
  }
  int extraSymbol = value < 0 || spec->space || (spec->plus_sign && value > 0);
  int totalWidth = extraSymbol + length + decimalPartLen;
  int startIndexDigits = width_padding(buffer, *spec, totalWidth);
  startIndexDigits = sign_prefix(buffer, startIndexDigits, (value < 0), *spec);
  for (int i = 0; i < length; i++) {
    buffer[startIndexDigits++] = temp[length - i - 1];
  }
  if (spec->precision > 0) {
    if (frac_int > 0 || trailingZeroes) {
      buffer[startIndexDigits++] = '.';
      char *tmp = (char *)calloc(spec->precision + 2, sizeof(char));
      if (tmp) {
        int frac_length = number_to_string(frac_int, spec->precision, tmp, 10);
        while (trailingZeroes && frac_length < spec->precision) {
          tmp[frac_length++] = '0';
        }
        for (int i = frac_length - 1; i >= 0; i--) {
          buffer[startIndexDigits++] = tmp[i];
        }
        free(tmp);
      }
    }
  } else if (spec->sharp_add0numeralSystem) {
    buffer[startIndexDigits++] = '.';
  }
  return spec->width > totalWidth ? spec->width : totalWidth;
}