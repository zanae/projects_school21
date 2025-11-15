#include "common.h"

#include <stdlib.h>

Options initOptions(const char* short_options, const unsigned int num_opt) {
  Options opt;
  opt.num_opt = num_opt;
  opt.opts = (int*)calloc(num_opt, sizeof(int));
  opt.errors = 0;
  opt.short_options = (char*)short_options;
  opt.long_options = NULL;
  return opt;
}

int clearOptions(Options opt) {
  free(opt.opts);
  free(opt.long_options);
  return 0;
}