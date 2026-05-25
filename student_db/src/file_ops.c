#include <stdio.h>
#include "student.h"

void write_student(Student s)
{
    FILE *fp = fopen(FILE_NAME, "a");

    if (fp == NULL)
    {
        printf("File opening error\n");
        return;
    }

    fprintf(fp, "%d %s %.2f\n", s.id, s.name, s.marks);

    fclose(fp);
}

int find_student(int id, Student *s)
{
    FILE *fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        return 0;
    }

    while (fscanf(fp, "%d %s %f",
                  &s->id,
                  s->name,
                  &s->marks) != EOF)
    {
        if (s->id == id)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}
