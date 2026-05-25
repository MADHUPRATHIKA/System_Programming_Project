#include <stdio.h>
#include "utils.h"

void print_error(const char *msg)
{
    perror(msg);
}
