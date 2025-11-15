#ifndef CAT_H
#define CAT_H
#include <stdio.h>

#include "../common/common.h"

Options catOptions();
char cat(const char *filename, Options cat_opt, int *num, char prevch);
char options(FILE **file, Options cat_opt, int *num, char prevCh);

#endif
