#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  int exit = 0;
  char *S1 = (char *)str1;
  while (*S1 && !exit) {
    char *S2 = (char *)str2;
    while (*S2 && !exit) {
      if (*S1 == *S2) {
        result = S1;
        exit = 1;
      }
      ++S2;
    }
    ++S1;
  }
  return result;
}
