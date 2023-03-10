#include <stdio.h>
#include <stdlib.h>

struct STRNUM {
	int num;
	struct STRNUM *next;
};

//Estructuras FIFO
typedef struct {
	struct STRNUM *first,*last;
} LIST;

void insert(LIST *l,int n);

int main()
{
	LIST lista = {NULL, NULL};
	struct STRNUM *ptr = NULL;
	int num;

	setbuf(stdout,NULL);

	// Hasta que se presione 0, se ejecuta el programa
	do
	{
		printf("Ingrese el numero (0 para salir): ");
		scanf("%d", &num);

		if (num != 0)
		{
			//Apunta al inicio de la lista
			ptr = lista.first;

			/**
			 * Mientras no llegue al final de la lista
			 * y no hemos encontrado el número (evitar que se repita)
			*/

			while(ptr != NULL && ptr->num != num)
				ptr = ptr->next;

			if (ptr == NULL)
				insert(&lista,num);
			else
				printf("El numero %d ya esta en la lista\n", num);

		}


	} while(num != 0);







}