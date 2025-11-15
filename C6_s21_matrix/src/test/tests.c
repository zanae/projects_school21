#include "tests.h"

#include <stdio.h>
void testing(Suite *testcase);

int main() {
  Suite *tests_list[] = {
      suite_create_matrix(), suite_remove_matrix(), suite_eq(),
      suite_sum(),           suite_sub(),           suite_multn(),
      suite_multm(),         suite_transpose(),     suite_complements(),
      suite_det(),           suite_inverse(),       NULL};
  for (Suite **current = tests_list; *current != NULL; current++) {
    testing(*current);
  }
  return 0;
}

void testing(Suite *testcase) {
  static int counter = 1;

  if (counter > 1) putchar('\n');
  printf("%d) ", counter);
  counter++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}
