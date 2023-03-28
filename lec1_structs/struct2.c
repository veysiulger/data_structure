#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct
{
    char schoolName[20];

} School;

typedef struct
{

    char studentName[20];
    int studentID;
    School school;
} Student;

int main()
{
    // Dogrudan erisim
    Student s1;
    strcpy(s1.studentName, "lorem");
    strcpy(s1.school.schoolName, "lorem ipsum");
    s1.studentID = 111;
    printf("Name:%s School:%s ID:%d\n", s1.studentName, s1.school.schoolName, s1.studentID);

    // Alternatif olarak; School yapisindan veri ureterek atama yapilabilir.
    School sch;
    Student s2;
    strcpy(sch.schoolName, "Lorem Ipsum Dolor");
    strcpy(s2.studentName, "lorem");
    s2.studentID = 222;
    s2.school = sch;

    printf("Name:%s School:%s ID:%d\n", s2.studentName, s2.school.schoolName, s2.studentID);
    return 0;
}