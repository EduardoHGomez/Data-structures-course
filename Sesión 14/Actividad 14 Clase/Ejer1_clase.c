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

#define LISTINIT {NULL,NULL}
//-----------Funciones----------
void insert(node **list, int i);

int main()
{
    srand(time(NULL));
    node *list = 3;

    for (int i = 0; i < 10; i++)
    {
        insert(&list, i);
    }
    printf("Direccion al salir: %p\n", list);

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%d ", ptr->num);
        ptr = ptr->next;
    }

    
    

}

void insert(node **list, int i)
{

    printf("Direccion en funcion: %p\n", *list);
    node *n = malloc(sizeof(node));
    n->num = i;
    n->next = NULL;

}
