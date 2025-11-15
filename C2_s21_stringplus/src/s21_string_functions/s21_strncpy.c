#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *str = dest;
  s21_size_t i = 0;
  while (src[i] != '\0' && i < n) {
    str[i] = src[i];
    ++i;
  }
  while (i < n) {
    str[i] = '\0';
    ++i;
  }
  return dest;
}
