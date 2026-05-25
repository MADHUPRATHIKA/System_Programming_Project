#include <stdio.h>
#include <dirent.h>
#include "utils.h"

int main()
{
    DIR *d;
    struct dirent *dir;

    d = opendir(".");

    if (d == NULL)
    {
        print_error("opendir");
        return 1;
    }

    while ((dir = readdir(d)) != NULL)
    {
        printf("%s\n", dir->d_name);
    }

    closedir(d);

    return 0;
}
