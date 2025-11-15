#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  char *S = S21_NULL;
  if (str) {
    s21_size_t len = s21_strlen(str);
    S = (char *)malloc((len + 1) * sizeof(char));
    if (S != S21_NULL) {
      for (s21_size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          S[i] = str[i] - 32;
        } else {
          S[i] = str[i];
        }
      }
      S[len] = '\0';
    }
  }
  return (void *)S;
}
