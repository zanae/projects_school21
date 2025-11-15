#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *S1 = (unsigned char *)dest;
  unsigned char *S2 = (unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    S1[i] = S2[i];
  }
  return dest;
}
