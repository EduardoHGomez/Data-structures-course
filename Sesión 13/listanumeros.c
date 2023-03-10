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

void insert(LIST *l,int n);

int main()
{
	LIST lista = {NULL,NULL};
	struct STRNUM *ptr = NULL,*todestroy = NULL;

	int num;

	setbuf(stdout,NULL);

	do {
		printf("Dame un numero (0 para terminar) :");
		scanf("%d",&num);
		if(num!=0)
		{
			// Buscar a ver si está en la lista
			ptr = lista.first; // Apunta al inicio

			// Mientras no llegue al final de la lista
			// y además no hemos encontrado el número
			while(ptr!=NULL && ptr->num != num)
				ptr = ptr->next; // Hacemos que ptr
								 // apunte al siguiente

			// Si no se encontró
			if(ptr==NULL)
				insert(&lista,num);
            else
                printf("El numero %d ya está en la lista\n", num);
		}

	} while(num!=0);

	// Recorrer la lista y mostrar los números
	ptr = lista.first;

	// Mientras no llegue al final de la lista
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->num);
		ptr = ptr->next;
	}

	// Destruir la lista para liberar la memoria
	ptr=lista.first;
	while(ptr!=NULL)
	{
		todestroy = ptr;
		ptr = ptr->next;
		free(todestroy);
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
