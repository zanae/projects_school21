#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = S21_NULL;

  if (src != S21_NULL && str != S21_NULL && start_index <= s21_strlen(src)) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    s21_size_t new_len = src_len + str_len + 1;

    result = (char *)calloc(new_len, sizeof(char));
    if (result != S21_NULL) {
      s21_strncpy(result, src, start_index);
      result[start_index] = '\0';
      s21_strncat(result, str, str_len);
      s21_strncpy(result + start_index + str_len, src + start_index,
                  src_len - start_index);
    }
  }

  return result;
}
