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
    struct STRNUM *first = NULL, *last = NULL, *ptr = NULL, *destr = NULL;
    int limite;

    for (int i = 2; i < MAX; i++)
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
            limite = sqrt(i);
            ptr = first;
            while(ptr != NULL && i % ptr->num != 0 && ptr->num <= limite)
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

    ptr = first;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->num);
        ptr = ptr->next;
    }
    
    //Destruir la lista
    ptr = first;
    while (ptr != NULL)
    {
        destr = ptr;
        ptr = ptr->next;
        free(destr);
    }
    
    

}