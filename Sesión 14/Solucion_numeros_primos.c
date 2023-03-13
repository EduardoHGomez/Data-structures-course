#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

struct STRNUM {
    int num;
    struct STRNUM *next;
};

int main()
{
    struct STRNUM *first = NULL, *last = NULL, *ptr = NULL;

    for (int i = 0; i < MAX; i++)
    {
        if (first == NULL)
        {
            first = malloc(sizeof(struct STRNUM));
            first->num = i;
            first->next = NULL;
            last = first;
        }
        else
        {
            ptr = first;
            while(ptr != NULL && i % ptr->num != 0)
                ptr = ptr->next;

            if (ptr == NULL)
            { //No hay un divisor en la lista
                ptr = malloc(sizeof(struct STRNUM));
                ptr->num = i;
                ptr->next = NULL;

                last->next = ptr;
                last = ptr;
            }
        }
    }
    

}