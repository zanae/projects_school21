#include "cat.h"

#include <stdio.h>
#include <stdlib.h>

#include "../common/common.h"

/*
diff <(cat -benstv kosha.txt romeo_and_juliet.txt) <(./s21_cat -benstv kosha.txt
romeo_and_juliet.txt)
*/

Options catOptions() {
  const struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {NULL, 0, NULL, 0}};
  Options cat_opt = initOptions("benstvTE", 6);
  // cat_opt - int array[6], флаги cat: b, e, n, s, t, v.
  // T, E не включены, т.к. это -t и -e без -v
  cat_opt.long_options = (struct option *)malloc(sizeof(long_options));
  for (size_t i = 0; i < sizeof(long_options) / sizeof(long_options[0]); i++)
    cat_opt.long_options[i] = long_options[i];
  return cat_opt;
}

char cat(const char *filename, Options cat_opt, int *num, char prevch) {
  FILE *file = fopen(filename, "r");
  unsigned char ch = ' ';
  if (file != NULL) {
    ch = options(&file, cat_opt, num, prevch);
    fclose(file);
  } else
    fprintf(stderr, "Unable to open the file %s\n", filename);
  return ch;
}

/*
cat_opt.opts[0] - b
cat_opt.opts[1] - e
cat_opt.opts[2] - n
cat_opt.opts[3] - s
cat_opt.opts[4] - t
cat_opt.opts[5] - v
*/

char options(FILE **file, Options cat_opt, int *num, char prevCh) {
  unsigned char ch = '\n';
  int numBlankLines = 0;
  while ((ch = fgetc(*file)) != (unsigned char)EOF) {
    int charWillChange = 0;
    if (cat_opt.opts[3]) {  // flag s
      if (ch == '\n' && prevCh == '\n') {
        numBlankLines++;
        charWillChange = numBlankLines >= 2 ? 1 : 0;
      } else if (ch != '\n' && prevCh == '\n' && numBlankLines > 0) {
        numBlankLines = 0;
      }
    }
    if ((cat_opt.opts[2] || cat_opt.opts[0]) &&
        charWillChange == 0) {  // flags n and b
      if (prevCh == '\n' &&
          ((cat_opt.opts[0] && ch != '\n') || cat_opt.opts[2])) {
        printf("%6d	", ++*num);
      }
    }
    if (cat_opt.opts[1]) {  // flag e
      if (ch == '\n' &&
          (!cat_opt.opts[3] || (cat_opt.opts[3] && numBlankLines < 2))) {
        printf("$");
      }
    }
    if (cat_opt.opts[4]) {  // flag t
      if (ch == '\t') {
        printf("^I");
        charWillChange = 1;
      }
    }
    if (cat_opt.opts[5]) {  // flag v
      charWillChange = (ch <= 31 && ch != '\t' && ch != '\n') || ch >= 127
                           ? 1
                           : charWillChange;
      if (ch < 32 && ch != '\t' && ch != '\n') {
        printf("^%c", ch + 64);
      } else if (ch > 127 && ch < 160) {
        printf("M-^%c", ch - 64);
      } else if (ch >= 160) {
        printf("M-%c", ch - 128);
      } else if (ch == 127) {
        printf("^?");
      }
    }
    if (charWillChange == 0) putchar(ch);
    prevCh = ch;
  }
  return ch == (unsigned char)EOF ? prevCh : ch;
}
