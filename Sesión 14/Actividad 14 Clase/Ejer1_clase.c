#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Usar la dirección: Cambiar el contenido
 * Enviar el apuntador: Extraer la información
*/
#define LIMIT 10

typedef struct STRNODE {
    int num;
    struct STRNODE *next;
} node;

typedef struct {
    node *first;
    node *last;
} LIST;

#define LISTINIT {NULL,NULL}
//-----------Funciones----------
void insert(LIST *list, int i);

int main()
{
    srand(time(NULL));
    LIST list = LISTINIT;

    for(int i = 0; i < LIMIT; i++)
    {
        //int n = rand() % LIMIT;
        insert(&list, i);
    }

    node *ptr = list.first;
    for (int i = 0; i < LIMIT; i++)
    {
        printf("%d ", ptr->num);
    }
    

}

void insert(LIST *list, int i)
{
    node *n = malloc(sizeof(node));

    n->num = i;
    n->next = NULL;
    n->next = list->first;
    list->first = n;
}