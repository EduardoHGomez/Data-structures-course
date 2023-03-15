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

    for (int i = 0; i < LIMIT; i++)
    {
        insert(&l, i);
    }
    
    struct STRNODE *ptr = l.first;
    while (ptr != NULL)
    {
        printf("%d ", ptr->num);
        ptr = ptr->next;
    }
    
    
    
    
}

void insert(LIST *l, int n)
{
	struct STRNODE *new = malloc(sizeof(struct STRNODE));

	new->num = n;
	new->next = NULL;

	if(l->first==NULL)
		l->first = new;
	else
		l->last->next = new; 

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
