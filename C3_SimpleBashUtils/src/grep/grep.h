#ifndef GREP_H
#define GREP_H
#include <regex.h>
#include <stdio.h>

#include "../common/common.h"
Options grepOptions();
void grep(const char *filename, Options *grep_opt, const char *reg,
          const int severalFlag);
void options(const char *filename, const Options grep_opt, const regex_t *ptreg,
             const int severalFlag);
int process_line(const char *buf, const char *filename, const Options grep_opt,
                 const regex_t *ptreg, const int severalFlag, const int num);
#endif
