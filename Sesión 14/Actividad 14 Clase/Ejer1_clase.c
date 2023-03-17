#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Usar la dirección: Cambiar el contenido
 * Enviar el apuntador: Extraer la información
*/
#define LIMIT 20

typedef struct STRNODE {
    int num;
    struct STRNODE *next;
} node;

typedef struct {
    struct STRNODE *first;
    struct STRNODE *last;
} LIST;

#define LISTINIT {NULL, NULL}
//-----------Funciones----------
void insert(LIST *list, int i);

int main()
{
    srand(time(NULL));
    LIST list = {NULL,NULL};
    int n;

    for (int i = 0; i < LIMIT; i++)
    {
        n = rand() % LIMIT;
        insert(&list, n);
    }
    
    node *ptr = list.first;
    while (ptr != NULL)
    {
        printf("%d ", ptr->num);
        ptr = ptr->next;
    }
    


}

void insert(LIST *list, int i)
{
    node *n = malloc(sizeof(node));
    n->num = i;
    n->next = NULL;

    if (list->first == NULL)
    {
        list->first = n;
    }
    else
    {
        list->last->next = n;
    }
    list->last = n;
    
}
