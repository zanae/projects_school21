#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last;
  char *result = S21_NULL;  // Инициализируем результат NULL
  char *p = str ? str : last;
  char *start = str ? str : last;
  while (*p && s21_strchr(delim, *p)) {
    p++;
  }
  if (!*p) {
    last = p;
  } else {
    start = p;
    // Находим конец токена
    while (*p && !s21_strchr(delim, *p)) {
      p++;
    }
    if (*p) {
      *p = '\0';
      last = p + 1;
    } else {
      last = p;
    }
    result = start;  // Устанавливаем результат
  }
  return result;
}
