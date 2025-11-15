#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  int exit = 0;
  char *res = S21_NULL;
  int S = s21_strlen(str);
  for (int i = S; i >= 0 && !exit; i--) {
    if (str[i] == c) {
      res = ((char *)str) + i;
      exit = 1;
    }
  }
  return res;
}
