#define _POSIX_C_SOURCE 200809L
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/common.h"
#include "grep.h"

void grep_options_search(int rez, Options *grep_opt, char **reg);
int regexp_flag(const char *new_reg, char **reg);  // 117
int file_flag(const char *file_reg, char **reg);   // 136
void escape_braces_parentheses(char **reg);        // 160
void check_opts(int argc, char **argv, char *reg);

int main(int argc, char **argv) {
  int rez;
  char *reg = (char *)malloc(1), *tmp = NULL;
  reg[0] = '\0';
  Options grep_opt = grepOptions();
  // check_opts(argc, argv, reg);
  while (grep_opt.errors == 0 &&
         (rez = getopt_long(argc, argv, grep_opt.short_options,
                            grep_opt.long_options, NULL)) != -1) {
    grep_options_search(rez, &grep_opt, &reg);
  }
  // check_opts(argc, argv, reg);
  if (optind < argc && grep_opt.errors == 0) {
    if (!grep_opt.opts[0] && !grep_opt.opts[8]) {
      tmp = (char *)realloc(reg, strlen(argv[optind]) + strlen(reg) + 1);
      if (tmp) {
        reg = tmp;
        strcat(reg, argv[optind]);
        int n = strlen(reg);
        reg[n] = '\0';
        optind++;
      } else
        grep_opt.errors++;
    } else {  // убрать лишний |, если он есть
      int n = strlen(reg);
      reg[n - 1] = '\0';
      tmp = (char *)realloc(reg, n);
      if (tmp)
        reg = tmp;
      else
        grep_opt.errors++;
    }
    // check_opts(argc, argv, reg);
    int severalFiles = optind < argc - 1;
    escape_braces_parentheses(&reg);
    //   printf("%s\n", reg);
    while (optind < argc && grep_opt.errors == 0) {
      grep(argv[optind], &grep_opt, reg, severalFiles);
      optind++;
    }
  } else if (!grep_opt.opts[7]) {
    fprintf(stderr, "No filename.\n");
    grep_opt.errors++;
  }
  clearOptions(grep_opt);
  free(reg);
  return 0;
}

void grep_options_search(int rez, Options *grep_opt, char **reg) {
  switch (rez) {
    case 'e': {
      grep_opt->opts[0] = 1;
      regexp_flag(optarg, reg);
      /*if (regexp_flag(optarg, reg) < 0) {
        free(*reg);
        grep_opt->errors++;
        *reg = NULL;
      }*/
      break;
    }
    case 'i': {
      grep_opt->opts[1] = 1;
      break;
    }
    case 'v': {
      grep_opt->opts[2] = 1;
      break;
    }
    case 'c': {
      grep_opt->opts[3] = 1;
      break;
    }
    case 'l': {
      grep_opt->opts[4] = 1;
      break;
    }
    case 'n': {
      grep_opt->opts[5] = 1;
      break;
    }
    case 'h': {
      grep_opt->opts[6] = 1;
      break;
    }
    case 's': {
      grep_opt->opts[7] = 1;
      break;
    }
    case 'f': {
      grep_opt->opts[8] = 1;
      if (!file_flag(optarg, reg)) {
        fprintf(stderr, "Unable to open file: %s\n", optarg);
        grep_opt->errors++;
      }
      break;
    }
    case 'o': {
      grep_opt->opts[9] = 1;
      break;
    }
    case '?':
    default: {
      fprintf(stderr, "Unknown option.\n");
      grep_opt->errors++;
      break;
    }
  }
}

int regexp_flag(const char *new_reg, char **reg) {
  char *tmp = NULL;
  int len_reg = strlen(*reg), len_new_reg = strlen(new_reg);
  tmp = (char *)realloc(*reg, len_new_reg + len_reg + 2);  // |\0
  if (tmp) {
    *reg = tmp;
    strcat(*reg, new_reg);
  }
  strcat(*reg, "|");
  len_reg = strlen(*reg);
  return len_reg;
}

int file_flag(const char *file_reg, char **reg) {
  int ok = 0;
  FILE *f = fopen(file_reg, "r");
  if (f) {
    ok = 1;
    char *buf = NULL;
    size_t bufsize = 32;
    while (getline(&buf, &bufsize, f) >= 0) {
      int b = strlen(buf);
      buf[b - 1] = buf[b - 1] == '\n' ? '\0' : buf[b - 1];
      char *tmp = (char *)realloc(*reg, b + 1 + strlen(*reg));
      if (tmp) {
        *reg = tmp;
        strcat(*reg, buf);
        strcat(*reg, "|");
      } else
        ok = 0;
    }
    // printf("%s\n", *reg);
    free(buf);
    fclose(f);
  }
  return ok;
}

void escape_braces_parentheses(char **reg) {
  // 'cause BRE doesn't process (){}
  int len_reg = strlen(*reg);
  char *escaped = (char *)malloc(len_reg * 2 + 1);
  if (escaped && len_reg > 0) {
    int j = 0;
    for (int i = 0; i < len_reg; ++i) {
      if ((*reg)[i] == '(' || (*reg)[i] == ')' || (*reg)[i] == '{' ||
          (*reg)[i] == '}') {
        escaped[j++] = '\\';
      }
      escaped[j++] = (*reg)[i];
    }
    escaped[j] = '\0';
    char *tmp = (char *)realloc(escaped, j + 1);
    if (tmp) {
      // && len_reg != j - уже не помню, зачем стояло. Почему-то вызывает утечку
      escaped = tmp;
      tmp = (char *)realloc(*reg, j + 1);  // '\0'
      if (tmp) {
        *reg = tmp;
        strcpy(*reg, escaped);
      }
    }
  }
  free(escaped);
}

void check_opts(int argc, char **argv, char *reg) {
  for (int i = 1; i < argc; i++)
    printf("%d\t%s\t%d%s\n", argc, argv[i], i, reg);
}
