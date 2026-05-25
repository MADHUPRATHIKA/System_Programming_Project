#include <stdio.h>
#include "student.h"

void add_student()
{
    Student s;

    printf("Enter ID: ");
    scanf("%d", &s.id);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    write_student(s);

    printf("Student added successfully\n");
}
