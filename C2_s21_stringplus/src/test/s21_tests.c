#include "s21_tests.h"

void testing(Suite *testcase);

int main() {
  Suite *tests_list[] = {suite_memchr(),   suite_memcmp(),  suite_memcpy(),
                         suite_memset(),   suite_strncat(), suite_strlen(),
                         suite_strchr(),   suite_strncmp(), suite_strerror(),
                         suite_strncpy(),  suite_strcspn(), suite_strpbrk(),
                         suite_strrchr(),  suite_strstr(),  suite_strtok(),
                         suite_trim(),     suite_insert(),  suite_to_upper(),
                         suite_to_lower(), suite_sprintf(), NULL};
  for (Suite **current = tests_list; *current != NULL; current++) {
    testing(*current);
  }
  return 0;
}

void testing(Suite *testcase) {
  static int counter = 1;

  if (counter > 1) putchar('\n');
  printf("%d ", counter);
  counter++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}
