#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct Student
{

    char studentName[20];
    int studentID;
};

typedef struct
{

    char bookName[20];
    int bookID;

} Book;

int main()
{

    //// Dogrudan Erisim (Direct):
    struct Student student1;
    student1.studentID = 1;
    strcpy(student1.studentName, "test1");
    printf("Name: %s \n ID:%d \n", student1.studentName, student1.studentID);
    
    //// Dolayli Erisim (Undirect):
    /**Pointer ile saglanir. Student2 icin hafizada yer acildi*/
    struct Student *student2 = (struct Student *)malloc(sizeof(struct Student));
    strcpy(student2->studentName, "test2");
    student2->studentID = 2;
    printf("Name: %s \n ID:%d \n", student2->studentName, student2->studentID);

    // Typedef-Direct
    Book b1;
    b1.bookID = 3;
    strcpy(b1.bookName, "Book name test1");
    printf("\n Book name:%s Book ID:%d \n", b1.bookName, b1.bookID);
        
    // Typedef-Undirect
    Book *b2 = (Book *)malloc(sizeof(Book));
    b2->bookID = 4;
    strcpy(b2->bookName, "Book name test2");
    printf("\n Book name:%s Book ID:%d \n", b2->bookName, b2->bookID);
    return 0;
}