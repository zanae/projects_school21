#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  while (dest[i] != 0) ++i;
  s21_size_t C = 0;
  while (src[C] != 0 && C < n) {
    dest[i + C] = src[C];
    C++;
  }
  dest[i + C] = '\0';
  return dest;
}
