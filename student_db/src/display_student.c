#include <stdio.h>
#include "student.h"

void display_students()
{
    FILE *fp = fopen(FILE_NAME, "r");

    Student s;

    if (fp == NULL)
    {
        printf("No records found\n");
        return;
    }

    printf("\nStudent Records\n\n");

    while (fscanf(fp, "%d %s %f",
                  &s.id,
                  s.name,
                  &s.marks) != EOF)
    {
        printf("ID: %d\n", s.id);
        printf("Name: %s\n", s.name);
        printf("Marks: %.2f\n\n", s.marks);
    }

    fclose(fp);
}
