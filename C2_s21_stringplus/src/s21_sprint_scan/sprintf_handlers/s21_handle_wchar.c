#include "s21_sprintf_handlers.h"

int s21_handle_wchar(char *buffer, wchar_t value,
                     struct formatSpecifiers *spec) {
  int ret = 0;
  if (!spec->minus_left_align && spec->width > 0) {
    char tmp[12] = {'\0'};
    int numBytes = wctomb(tmp, value);
    ret = numBytes;
    int i = 0;
    while (i < spec->width - numBytes) {
      buffer[i] = (spec->zero_padding ? '0' : ' ');
      ret++;
      i++;
    }
    char *src = tmp;
    while ((buffer[i++] = *src++) != '\0') {
    }
  } else if (spec->width > 0) {
    int numBytes = wctomb(buffer, value);
    ret = numBytes;
    for (int i = numBytes; i < spec->width; i++) {
      buffer[i] = ' ';
      ret++;
    }
  } else {
    ret = wctomb(buffer, value);
  }
  return ret;
}