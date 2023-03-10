#include <stdio.h>
#include <stdlib.h>

typedef struct strdate {
    int year;
    int month;
    int day;
    struct strdate *next;
} DATE;

void printdates(DATE *d);
void print3dates(DATE d);
void insert(DATE **ptrinciolista,DATE *n);

int main()
{
    DATE d1={1,10,2019,NULL};
    DATE d2={2,02,2020,NULL};
    DATE d3={3,03,2021,NULL};

    DATE *iniciolista=NULL;

    insert(&iniciolista,&d1);
    insert(&iniciolista,&d2);
    insert(&iniciolista,&d3);

    printdates(iniciolista);
}

void insert(DATE **ptriniciolista,DATE *n)
{
    /* Si la lista está vacia, es decir *ptriniciolista es NULL, debe apuntar
       al primer elemento que se inserta
       Si la lista no está vacía, hay que recorrer la lista hasta llegar al final
       para insertar el elemento 
    */

   DATE *currentDate;
   if (*ptriniciolista == NULL)
   {
    *ptriniciolista = n;
   }
   else
   {
        currentDate = *ptriniciolista;
        while(currentDate->next != NULL)
            currentDate = currentDate->next;
        currentDate->next = n;
   }
   
}

void printdates(DATE *d)
{
   DATE *ptr=d;

   while(ptr!=NULL)
   {
       printf("%d,%d,%d\n",ptr->year,ptr->month,ptr->day);
       ptr=ptr->next;
   }
}