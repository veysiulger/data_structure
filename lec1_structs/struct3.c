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
    School *school;
} Student;

int main()
{

    School *sch = (School *)malloc(sizeof(School));
    // Bellekte yer acmaliyiz. Hafizada School yapisina ait bir yer acildi.
    // Bu yer, *sch ile gosterilir. *sch=adres tutarken, sch=deger tutar.
    strcpy(sch->schoolName, "Lorem ipsum dolor");

    Student s1;
    strcpy(s1.studentName, "Lorem");
    s1.studentID = 101;
    s1.school = sch;

    printf("Name:%s School:%s ID:%d\n", s1.studentName, s1.school->schoolName, s1.studentID);
    return 0;
}