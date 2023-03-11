#include <stdio.h>
#include <stdlib.h>

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
    int limite, is_prime, SIZE = 1;
    printf("Ingrese un numero limite: ");
    scanf("%d", &limite);

    LIST lista = {NULL, NULL};
    struct STRNUM *ptr = NULL, *todestro = NULL;

    //Establecer 2 como el primer número primo
    lista.first = malloc(sizeof(struct STRNUM));
    lista.first->number = 2;
    lista.last->next = NULL;

    //Ciclo que revisa todo el ciclo
    for (int i = 2; i < limite; i++)
    {
        //Hacer que ptr apunte al inicio de la lista
        ptr = lista.first;

        is_prime = 1;
        //Recorrer toda la lista de primos
        for (int j = 0; j < SIZE; j++)
        {
            if ((i != ptr->number) && (i % ptr->number == 0))
            {
                ptr = ptr->next;
                is_prime = 0;
                break;
            }
        }
        
        if (is_prime && i > 2)
        {
            printf("%d es primo\n", i);
            SIZE++;
            insert(&lista, i);
        }
        
    }
    
}

void insert(LIST *lista, int prime)
{
	// Crear el nodo
	struct STRNUM *new = malloc(sizeof(struct STRNUM));

	// Poner los valores en la estructura
	new->number = prime;
	new->next = NULL;

	// Si first apunta a NULL es que la lista está vacía
	// y hay que poner el nodo como el primero de la lista
	if(lista->first==NULL)
		lista->first = new;
	else
		lista->last->next = new; // Si no, hay que ponerlo después
							 // de last

	lista->last = new;	// last debe apuntar al nodo que acabamos
					// de poner, que es el último
}