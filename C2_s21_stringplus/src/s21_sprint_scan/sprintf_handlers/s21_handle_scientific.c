#include "s21_sprintf_handlers.h"

static long double round_double(long double value, int precision) {
  long double rounded = value;
  if (precision > 0) {
    long double factor = pow(10, precision);
    rounded = roundl(value * factor) / factor;
  } else
    rounded = roundl(value);
  return rounded;
}

int s21_handle_scientific(char *buffer, double value,
                          struct formatSpecifiers *spec, bool trailingZeroes) {
  int exponent = 0;
  double mantissa = 0;
  if (value != 0.0) {
    exponent = floor(log10(fabs(value)));  // 1-4 digits (1-3 number and 1 for
                                           // minus), pad with 0 if 1 digit (1)
    mantissa = round_double(value / pow(10.0, exponent), spec->precision);
  }
  mantissa = fabsl(mantissa);
  char exp_buffer[7];
  int totalWidth = 0, expLength = 0;
  if (spec->specifier == 'e' || spec->specifier == 'g') {
    expLength = s21_sprintf(exp_buffer, "e%+03d", exponent);
  } else {
    expLength = s21_sprintf(exp_buffer, "E%+03d", exponent);
  }
  if (exponent == 0) {
    exp_buffer[1] = '+';
  }
  char *tmpBuffer = (char *)calloc(spec->precision + 2, sizeof(char));
  if (tmpBuffer) {
    struct formatSpecifiers specTmp = {0};
    specTmp.precision = spec->precision;
    int length =
        s21_handle_float(tmpBuffer, mantissa, &specTmp, trailingZeroes);
    int extraSymbol =
        value < 0 || spec->space || (spec->plus_sign && value > 0);
    totalWidth += length + expLength + extraSymbol;
    int startIndexDigits = width_padding(buffer, *spec, totalWidth);
    startIndexDigits =
        sign_prefix(buffer, startIndexDigits, (value < 0), *spec);
    for (int i = 0; i < length; i++) {
      buffer[startIndexDigits++] = tmpBuffer[i];
    }
    for (int i = 0; i < expLength; i++) {
      buffer[startIndexDigits++] = exp_buffer[i];
    }
    free(tmpBuffer);
  }
  return spec->width > totalWidth ? spec->width : totalWidth;
}
