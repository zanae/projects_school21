#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *S1 = (char *)str1;
  char *S2 = (char *)str2;
  int res = 0;
  for (s21_size_t i = 0; i < n && !res; i++) {
    if (S1[i] != S2[i]) {
      res = S1[i] - S2[i];
    }
  }
  return res;
}
