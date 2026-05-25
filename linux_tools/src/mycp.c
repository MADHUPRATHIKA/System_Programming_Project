#include <stdio.h>
#include "utils.h"

int main(int argc, char *argv[])
{
    FILE *src, *dest;
    char ch;

    if (argc != 3)
    {
        printf("Usage: ./mycp <source> <destination>\n");
        return 1;
    }

    src = fopen(argv[1], "r");

    if (src == NULL)
    {
        print_error("source file");
        return 1;
    }

    dest = fopen(argv[2], "w");

    if (dest == NULL)
    {
        print_error("destination file");
        fclose(src);
        return 1;
    }

    while ((ch = fgetc(src)) != EOF)
    {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);

    return 0;
}
