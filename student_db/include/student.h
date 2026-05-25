#ifndef STUDENT_H
#define STUDENT_H

#define FILE_NAME "students.txt"

typedef struct
{
    int id;
    char name[50];
    float marks;
} Student;

void add_student();
void search_student();
void display_students();

void write_student(Student s);
int find_student(int id, Student *s);

#endif
