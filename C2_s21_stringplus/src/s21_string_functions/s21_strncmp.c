#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t res = 0;
  s21_size_t i = 0;
  while (i < n && str1[i] != '\0' && str2[i] != '\0' && res == 0) {
    if (str1[i] != str2[i]) {
      res = (unsigned char)str1[i] - (unsigned char)str2[i];
    }
    ++i;
  }
  if (i < n && res == 0) {
    res = (unsigned char)str1[i] - (unsigned char)str2[i];
  }
  return res;
}
