#ifndef COMMON_H
#define COMMON_H
#include <getopt.h>

typedef struct {
  unsigned int num_opt;
  int* opts;
  int errors;
  char* short_options;
  struct option* long_options;
} Options;

Options initOptions(const char* short_options, const unsigned int num_opt);
int clearOptions(Options opt);

#endif
