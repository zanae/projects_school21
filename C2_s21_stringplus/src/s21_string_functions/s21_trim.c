#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *trimmed_str = S21_NULL;

  if (src != S21_NULL && trim_chars != S21_NULL && s21_strlen(src) > 0 &&
      s21_strlen(trim_chars) > 0) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t start_index = 0;
    s21_size_t end_index = src_len - 1;

    while (start_index < src_len &&
           s21_strchr(trim_chars, src[start_index]) != S21_NULL) {
      start_index++;
    }
    while (end_index > start_index &&
           s21_strchr(trim_chars, src[end_index]) != S21_NULL) {
      end_index--;
    }
    s21_size_t trimmed_len = end_index - start_index + 1;
    trimmed_str = (char *)calloc(trimmed_len + 1, sizeof(char));

    if (trimmed_str != S21_NULL) {
      s21_strncpy(trimmed_str, src + start_index, trimmed_len);
      trimmed_str[trimmed_len] = '\0';
    }
  } else if (src != S21_NULL && s21_strlen(src) == 0) {
    trimmed_str = (char *)malloc(1);
    if (trimmed_str != NULL) {
      trimmed_str[0] = '\0';
    }
  }

  return trimmed_str;
}
