#include <stdio.h>
#include <stdlib.h>

struct STRNUM{
    int number;
    struct STRNUM *next;
};

typedef struct {
    struct STRNUM *first, *last;
} LIST;

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

    //Hacer que ptr apunte al inicio de la lista
    ptr = lista.first;

    //Ciclo que revisa todo el ciclo
    for (int i = 2; i < limite; i++)
    {
        is_prime = 1;
        while (ptr != NULL)
        
    }
    
}

void insert(LIST *l,int n)
{
	// Crear el nodo
	struct STRNUM *new = malloc(sizeof(struct STRNUM));

	// Poner los valores en la estructura
	new->num = n;
	new->next = NULL;

	// Si first apunta a NULL es que la lista está vacía
	// y hay que poner el nodo como el primero de la lista
	if(l->first==NULL)
		l->first = new;
	else
		l->last->next = new; // Si no, hay que ponerlo después
							 // de last

	l->last = new;	// last debe apuntar al nodo que acabamos
					// de poner, que es el último
}