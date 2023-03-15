#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Usar la dirección: Cambiar el contenido
 * Enviar el apuntador: Extraer la información
*/
#define LIMIT 20

struct STRNODE {
    int num;
    struct STRNODE *next;
};

typedef struct {
    struct STRNODE *first;
    struct STRNODE *last;
} LIST;

#define LISTINIT {NULL,NULL}

void insert(LIST *list,int num);
int found(LIST list,int num);
void display(LIST list);
void destroy(LIST list);

int main()
{
    srand(time(NULL));

    LIST l = LISTINIT; // Establece first y last como NULL
    int n;

    printf("%p %p\n", l.first, l.last);
    insert(&l, 4);
    insert(&l, 5);
    
    printf("%d %d", l.first->num, l.last->num);
}

void insert(LIST *l, int n)
{
    struct STRNODE *new = malloc(sizeof(struct STRNODE));
    new->num = n;

    if (l->first == NULL)
    {
        l->first = new;
        l->first->num = n;
    }
    else
    {   
        struct STRNODE *ptr = l->first;
        while (ptr != NULL)
        {
            ptr = ptr->next;
        }
        

        l->last->next = new;
    }
    l->last = new;
    	

}

int found(LIST list,int num)
{
    struct STRNODE *ptr = list.first;

    while (ptr != NULL && ptr->num != num)
    {
        
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
