#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t buf = 0;
  s21_size_t res = s21_strlen(str1);
  for (s21_size_t i = 0; i < s21_strlen(str2); ++i) {
    buf = 0;
    for (s21_size_t j = 0; str1[j] != str2[i] && j != s21_strlen(str1); ++j) {
      buf += 1;
    }
    if (buf < res) {
      res = buf;
    }
  }
  return res;
}
