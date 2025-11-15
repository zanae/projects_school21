#define _POSIX_C_SOURCE 200809L
#include "grep.h"

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#include "../common/common.h"

// grep -e "|" -e "(" symbols.txt
// grep -e "\(|\)" symbols.txt
/*
grep_opt->opts[0] - e
grep_opt->opts[1] - i
grep_opt->opts[2] - v
grep_opt->opts[3] - c
grep_opt->opts[4] - l
grep_opt->opts[5] - n
grep_opt->opts[6] - h
grep_opt->opts[7] - s
grep_opt->opts[8] - f
grep_opt->opts[9] - o

e v s f - отдельная песня
i > l > c h > n o
-vo - внезапно тоже отдельная песня, не выводит вообще ничего
*/
Options grepOptions() {
  const struct option long_options[] = {
      {"regexp", required_argument, NULL, 'e'},
      {"ignore-case", no_argument, NULL, 'i'},
      {"invert-match", no_argument, NULL, 'v'},
      {"count", no_argument, NULL, 'c'},
      {"files-with-matches", no_argument, NULL, 'l'},
      {"line-number", no_argument, NULL, 'n'},
      {"no-filename", no_argument, NULL, 'h'},
      {"file", required_argument, NULL, 'f'},
      {"only-matching", no_argument, NULL, 'o'},
      {NULL, 0, NULL, 0}};
  Options grep_opt = initOptions("e:ivclnhsf:o", 10);
  grep_opt.long_options = (struct option *)malloc(sizeof(long_options));
  for (size_t i = 0; i < sizeof(long_options) / sizeof(long_options[0]); i++)
    grep_opt.long_options[i] = long_options[i];
  return grep_opt;
}

void grep(const char *filename, Options *grep_opt, const char *reg,
          const int severalFlag) {
  FILE *file = fopen(filename, "r");
  regex_t ptreg;
  // i - ignore case
  int flags = grep_opt->opts[1] ? REG_EXTENDED | REG_ICASE : REG_EXTENDED;
  int value = regcomp(&ptreg, reg, flags);
  if (file == NULL) {
    if (!grep_opt->opts[7]) {
      fprintf(stderr, "Unable to open file: %s\n", filename);
    }
    grep_opt->errors++;
  } else {
    if (value == 0) {  // value = 0, if regex compiled
      fclose(file);
      options(filename, *grep_opt, &ptreg, severalFlag);
    } else {
      fprintf(stderr, "Didn't compile the regex correctly\n");
      grep_opt->errors++;
    }
  }
  regfree(&ptreg);
}

void options(const char *filename, const Options grep_opt, const regex_t *ptreg,
             const int severalFlag) {
  FILE *file = fopen(filename, "r");
  regmatch_t match;  // catch match
  int num = 0, countContains = 0, endSearching = 0;
  char *buf = NULL;
  size_t bufsize = 32;
  while (getline(&buf, &bufsize, file) >= 0 && !endSearching) {
    num++;
    /*
    regmatch_t match хранит подстроки, содержащие совпадения с регуляркой.
    в данном случае match должна иметь хотя бы 1 совпадение.
    0 - что-то про учитывание оператора конца строки (в оригинале eflags)
    */
    int matchflag = regexec(ptreg, buf, 1, &match, 0);
    matchflag = grep_opt.opts[2] ? !matchflag : matchflag;
    if (matchflag == 0) {
      countContains++;
      endSearching =
          process_line(buf, filename, grep_opt, ptreg, severalFlag, num);
    }
  }
  if (grep_opt.opts[3] && !grep_opt.opts[4]) {  // flag c
    if (severalFlag && !grep_opt.opts[6]) {
      printf("%s:", filename);
    }
    printf("%d\n", countContains);
  }
  free(buf);
  fclose(file);
}

int process_line(const char *buf, const char *filename, const Options grep_opt,
                 const regex_t *ptreg, const int severalFlag, const int num) {
  regmatch_t match;
  char *line = (char *)buf;
  int endSearching = grep_opt.opts[3] && !grep_opt.opts[4];
  // -c обрабатывается в конце - if он тут (без l), then бежать дальше
  int vo = grep_opt.opts[2] && grep_opt.opts[9];
  /*
  -vo вщ не обрабатывается, но доминирование -l и -c никто не отменял.
  Вообще, по идее, оно должно выводить все несовпадения в каждой строке,
  но почему-то в linux не выводится ничего. И слава богу, ибо пришлось бы
  придумывать махинации с regex,
  т.к. в match сохраняется наличие совпадения с обычной регуляркой.
  */
  int dontPrint = grep_opt.opts[4] || grep_opt.opts[3];  // l || c || vo
  while (!endSearching &&
         (regexec(ptreg, line, 1, &match, 0) == 0 ||
          (grep_opt.opts[2] && regexec(ptreg, buf, 1, &match, 0) != 0))) {
    if ((!vo && ((severalFlag && !grep_opt.opts[6]) || dontPrint)) ||
        (vo && dontPrint)) {  // !vo && l || !vo && several && !h || vo && l
      printf("%s", filename);
      endSearching = grep_opt.opts[4] || dontPrint;
      putchar(endSearching ? '\n' : ':');
    }
    endSearching += vo;
    if (!dontPrint && !endSearching) {
      if (grep_opt.opts[5]) {
        printf("%d:", num);
      }
      if (!grep_opt.opts[9]) {
        printf("%s", buf);
        endSearching = 1;
      } else {
        printf("%.*s\n", (int)(match.rm_eo - match.rm_so), line + match.rm_so);
        line += match.rm_eo;
      }
    }
    /*if (grep_opt.opts[5] && !dontPrint && !endSearching) {  // n
      printf("%d:", num);
    }
    if (!dontPrint && !endSearching) {
      if (!grep_opt.opts[9]) {
        printf("%s", buf);
        endSearching = 1;
      } else {
        printf("%.*s\n", (int)(match.rm_eo - match.rm_so), line + match.rm_so);
        line += match.rm_eo;
      }
    }*/
  }
  return grep_opt.opts[4];
}
