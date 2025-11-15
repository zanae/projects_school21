#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = S21_NULL;
  const unsigned char *S = (const unsigned char *)str;
  s21_size_t i = 0;
  while (i < n && *S != '\0' && *S != (unsigned char)c) {
    S++;
    i++;
  }
  if (i < n && *S == (unsigned char)c) {
    res = (void *)S;  // Устанавливаем результат, если символ найден
  }
  return res;
}
