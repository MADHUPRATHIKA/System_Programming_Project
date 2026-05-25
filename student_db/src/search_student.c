#include <stdio.h>
#include "student.h"

void search_student()
{
    int id;
    Student s;

    printf("Enter student ID to search: ");
    scanf("%d", &id);

    if (find_student(id, &s))
    {
        printf("\nStudent Found\n");
        printf("ID: %d\n", s.id);
        printf("Name: %s\n", s.name);
        printf("Marks: %.2f\n", s.marks);
    }
    else
    {
        printf("Student not found\n");
    }
}
