#include <stdio.h>
#include <stdlib.h>

struct STRNUM {
	int num;
	struct STRNUM *next;
};

/**
 * Se crea una estructura dado que resulta más fácil pasarlo como
 * una sola variable, accediendo así tanto al inicio de la lista
 * como el final
*/

typedef struct {
	struct STRNUM *first, *last;
} LIST;

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

/**
 * Pseudocódigo:
 * for todos los números
 *      Si de todos los elemenetos almacenados, es divisible entre el mismo
 * 
*/


int main()
{
	LIST lista = {NULL,NULL};
	struct STRNUM *ptr = NULL;

    int n, size = 0;
    printf("Ingrese el numero limite: ");
    scanf("%d", &n);

	for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < size; j++)
        {
            
        }
        
    }
    

}


