#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  int exit = 0;
  char *S = S21_NULL;
  for (s21_size_t i = 0; i <= s21_strlen(str) && !exit; i++) {
    if (str[i] == (char)c) {
      S = ((char *)str) + i;
      exit = 1;
    }
  }
  return S;
}
