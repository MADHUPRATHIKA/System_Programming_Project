#include <stdio.h>
#include "utils.h"

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if (argc != 2)
    {
        printf("Usage: ./mycat <file>\n");
        return 1;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        print_error("fopen");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }

    fclose(fp);

    return 0;
}
