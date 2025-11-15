#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  int res = 0;
  int length_haystack = s21_strlen(haystack);
  int length_needle = s21_strlen(needle);
  int i = 0;
  while (i <= length_haystack - length_needle && res != 1) {
    int j = 0;
    while (j < length_needle && needle[j] == haystack[i + j]) {
      j++;
    }
    if (j == length_needle) {
      res = 1;
    }
    i++;
  }
  if (res == 1) {
    result = (char *)haystack + i - 1;
  } /*else {
    result = S21_NULL;
  }*/
  return result;
}
