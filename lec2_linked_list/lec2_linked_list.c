/*Bagli listenin elemanlari bellekte farkli
alanlarda konumlanabilir.*/

/*Bagli listeler, farkli turde veri
barindirabilmektedir.*/

/*Linked list yapisi gerceklenirken, listenin basi
 * ve sonunu gosteren isaretci kullanilmaktadir.
 * Araya eleman eklendiginde yada bir eleman
 * silindiginde, head(first) ve tail(last) guncellenir.
 */

/**Liste bosken, yani henuz eleman yok iken,
 * first ve last, null gostermektedir.
 *
 * Eger listede tek eleman varsa, first ve last
 * o elemani gosterir.
 *
 * Eger birden fazla eleman varsa, first ilk elemani
 * last ise, son elemani gostermek zorundadir.
 */

#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};

// first, last
struct node *first = NULL;
struct node *last = NULL;

int addNode(int data)
{

    if (first == NULL)
    {

        struct node *temp = (struct node *)malloc(sizeof(struct node));
        // parametre olarak gelen datayi, temp'in datasi olarak ayarlariz.
        temp->data = data;
        temp->next = NULL;
        first = last = temp;
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = NULL;
        // Listenin sonundaki eleman, yeni ekleneni gostermesi icin:
        last->next = temp;
        // Listenin sonu artik, yeni eklenen eleman olacak:
        last = temp;
    }
}
int addNodeToHead(int data)
{
    if (first == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = NULL;
        first = last = temp;
    }
    else
    {

        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = first;

        first = temp;
    }
}
void printList()
{
    struct node *index = first;
    // index, listenin ilk elemanini gosterir.
    while (index != NULL)
    {

        printf("%d - ", index->data);
        index = index->next;//Bir sonrakine gec.
    }
    puts("");
}
int deleteNode(int data)
{
    struct node *prev = NULL;
    struct node *index = first;
    // index ilk olarak bastaki elemani gostersin.
    if (first == NULL)
    {
        puts("Bagli liste bos!");
        return 1;
    }
    if (first->data == data)
    //ilk eleman silinecek ise.
    {
        struct node *temp = first;
        first = first->next;
        free(temp);
    }
    while (index != NULL && index->data != data)
    {
     //Listenin sonuna kadar gidilir.
        prev = index;//mevcut index'i tutariz.
        index = index->next;//Bir sonraki dugume gec.
    }
    if (index == NULL)
    {
        puts("Veri bulunamadi!");
        return 1;
    }
    prev->next = index->next;
    if (last->data == data)
    {
        last = prev;
    }
    free(index);
    return 1;
}
int main()
{

    addNode(5);
    addNode(6);
    addNode(7);
    addNodeToHead(13);
    printList();
    deleteNode(6);
    printList();

}
