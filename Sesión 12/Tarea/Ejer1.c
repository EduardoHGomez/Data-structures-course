#include <stdio.h>
#include <stdlib.h>

typedef struct strdate {
    int year;
    int month;
    int day;
    struct strdate *next;
} DATE;

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