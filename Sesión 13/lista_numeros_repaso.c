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
			 * Comprobando donde apunta currentNum
			*/
			while(currentNumPointer != NULL && currentNumPointer->num != n)
				currentNumPointer = currentNumPointer->next;

			if (currentNumPointer == NULL)
			{
				insert(&lista, n);
			}
			
			

		}
	
	} while(n != 0);

}

void insert(LIST *l,int n)
{
	struct STRNUM *new = malloc(sizeof(struct STRNUM));
	new->num = n;
	new->next = NULL;

	
	
}