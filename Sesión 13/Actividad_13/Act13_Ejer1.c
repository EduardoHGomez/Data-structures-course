#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct STRNUM{
    int number;
    struct STRNUM *next;
};

typedef struct {
    struct STRNUM *first, *last;
} LIST;

void insert(LIST *lista, int prime);

int main()
{
    
    unsigned int limite, is_prime, SIZE = 1;
    printf("Ingrese un numero limite: ");
    scanf("%d", &limite);

    
    clock_t begin = clock();

    LIST lista = {NULL, NULL};
    struct STRNUM *ptr = NULL, *todestroy = NULL;

    //Establecer 2 como el primer número primo
    insert(&lista, 2);

    //Ciclo que revisa todo el ciclo
    for (int i = 2; i <= limite; i++)
    {
        //Hacer que ptr apunte al inicio de la lista
        ptr = lista.first;

        is_prime = 1;
        //Recorrer toda la lista de primos
        for (int j = 0; j < SIZE; j++)
        {
            if ((i != ptr->number) && (i % ptr->number == 0))
            {
                is_prime = 0;
                break;
            }
            ptr = ptr->next;
        }
        
        if (is_prime && i > 2)
        {
            
            SIZE++;
            insert(&lista, i);
        }
        
    }

    //printf("Numeros primos: \n");
    ptr = lista.first;
/**
 *     for (int i = 0; i < SIZE; i++)
    {
        //printf("%d ", ptr->number);
        ptr = ptr->next;
    }
*/

    ptr=lista.first;
	while(ptr!=NULL)
	{
		todestroy = ptr;
		ptr = ptr->next;
		free(todestroy);
	}
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTiempo de ejecucion %f\n", time_spent);
}

void insert(LIST *lista, int prime)
{
	struct STRNUM *new = malloc(sizeof(struct STRNUM));
	new->number = prime;
	new->next = NULL;

	if(lista->first==NULL)
		lista->first = new;
	else
		lista->last->next = new; 

	lista->last = new;	
}