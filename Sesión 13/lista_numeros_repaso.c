#include <stdio.h>
#include <stdlib.h>

struct STRNUM {
	int num;
	struct STRNUM *next;
};

typedef struct {
	struct STRNUM *first,*last;
} LIST;

void insert(LIST *l,int n);

int main()
{
	LIST lista = {NULL, NULL};
	struct STRNUM *currentNumPointer;

	int n;
	do
	{
		printf("Ingrese un numero (0 para salir): ");
		scanf("%d", &n);

		if (n != 0)
		{
			currentNumPointer = lista.first;

			/**
			 * El siguiente ciclo recorre toda la lista
			 * Se hace falsa cuando llega al final y
			 * el número es distinto del ingresado
			*/
			while(currentNumPointer != NULL && currentNumPointer->num != n)
				currentNumPointer = currentNumPointer->next;

			//Condición si no se encontró
			if (currentNumPointer == NULL)
			{
				insert(&lista, n);
			}
			else
				printf("El numero %d ya esta en la lista\n", n);
		}
	
	} while(n != 0);

	struct STRNUM *ptr = NULL, *todestroy = NULL;
	ptr = lista.first;
	while(ptr != NULL)
	{
		printf("%d\n", ptr->num);
		ptr = ptr->next;
	}

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
	struct STRNUM *new = malloc(sizeof(struct STRNUM));
	new->num = n;
	new->next = NULL;

	if (l->first == NULL)
	{
		l->first = new;
	}
	else
		l->last->next = new;

	l->last = new;
	
}