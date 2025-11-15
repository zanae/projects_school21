#include <getopt.h>
#include <stdio.h>

#include "../common/common.h"
#include "cat.h"

void cat_options_search(char rez, Options *cat_opt);

int main(int argc, char **argv) {
  int rez = 0;
  Options cat_opt = catOptions();
  while (cat_opt.errors == 0 &&
         (rez = getopt_long(argc, argv, cat_opt.short_options,
                            cat_opt.long_options, NULL)) != -1) {
    cat_options_search(rez, &cat_opt);
  }
  int num = 0;  // на маке можно было б убрать эту переменную, но
  // linux cat при нескольких файлах продолжает нумерацию, а не начинает
  // заново...
  char ch = '\n';  // на маке тоже не обяз, но линуха...
  if (optind < argc && cat_opt.errors == 0) {
    do {
      ch = cat(argv[optind], cat_opt, &num, ch);
    } while (++optind < argc);
  } else {
    fprintf(stderr, "No filename.\n");
    cat_opt.errors++;
  }

  /*
  OMG im shocked, this line shows how getopt literally sorts the whole argv,
  omg, getopt is BOZHESTVENEN
  ./s21_cat -b -e -n *.txt -s -T

  for (int i = 1; i < argc; i++) printf("\t\t\t%s\n", argv[i]);

  Т.е. он отсортирует по порядку: сначала флаги, потом остальное
  */
  clearOptions(cat_opt);
  return 0;
}

void cat_options_search(char rez, Options *cat_opt) {
  switch (rez) {
    case 'b': {
      cat_opt->opts[0] = 1;
      cat_opt->opts[2] = 0;
      break;
    }
    case 'e': {
      cat_opt->opts[1] = 1;
      cat_opt->opts[5] = 1;
      break;
    }
    case 'n': {
      cat_opt->opts[2] = cat_opt->opts[0] == 0 ? 1 : 0;
      break;
    }
    case 's': {
      cat_opt->opts[3] = 1;
      break;
    }
    case 't': {
      cat_opt->opts[4] = 1;
      cat_opt->opts[5] = 1;
      break;
    }
    case 'v': {
      cat_opt->opts[5] = 1;
      break;
    }
    case 'T': {
      cat_opt->opts[4] = 1;
      break;
    }
    case 'E': {
      cat_opt->opts[1] = 1;
      break;
    }
    case '?':
    default: {
      fprintf(stderr, "Unknown option.\n");
      cat_opt->errors++;
      break;
    }
  }
}
