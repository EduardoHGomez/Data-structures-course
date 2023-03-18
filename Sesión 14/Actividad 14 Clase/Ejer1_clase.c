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


//-----------Funciones----------
void insert(LIST *list, int i);
void display(LIST list);
int found(LIST list,int num);
void destroy(LIST list);

#define LISTINIT {NULL, NULL}

int main()
{
    srand(time(NULL));
    LIST list = {NULL,NULL};
    int n;

    for (int i = 0; i < LIMIT; i++)
    {
        n = rand() % LIMIT;
        if(!found(list,n))
            insert(&list,n);
    }

    display(list);

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

int found(LIST list,int num)
{
    node *ptr = list.first;
    while (ptr != NULL)
    {
        if (ptr->num == num)
        {
            return 1;
        }
        
        ptr = ptr->next;
    }

    return 0;   
}

void display(LIST list)
{
    node *ptr = list.first;
    while (ptr != NULL)
    {
        printf("%d ", ptr->num);
        ptr = ptr->next;
    }
}

void destroy(LIST list)
{
    node *next = NULL;

    for (node *ptr = list.first; ptr != NULL; ptr = ptr->next) // Otra forma
    {
        next = ptr->next;
        free(ptr);
        ptr = next;

    }
    
}