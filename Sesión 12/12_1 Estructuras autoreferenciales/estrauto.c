/*
 * estrauto.c
 *
 *  Created on: 6 mar 2023
 *      Author: jluis
 */
#include <stdio.h>


struct STRALUM {
	char nombre[30];
	char apellido[30];
	int expediente;
	struct STRALUM *siguiente;
};

void encadenar(struct STRALUM *a, struct STARLUM *b)
{
    a->siguiente = b;
}

int main()
{
	struct STRALUM al1 = {"David Rodrigo","Leon",744025,NULL};
	struct STRALUM al2 = {"Ximena","Isaac",739032,NULL};
	struct STRALUM al3 = {"Luis Fernando","Chávez",734822,NULL};
	struct STRALUM al4 = {"Renata","Tejeda",739500,NULL};
	struct STRALUM al5 = {"Harel","Olguín",742621,NULL};
	struct STRALUM al6 = {"Brenda","Vela",740732,NULL};

	struct STRALUM *primero;
	struct STRALUM *ptr;

	primero = &al3;
    encadernar(&al3, &al5);
    encadernar(&al5, &al6);
    encadernar(&al6, &al1);
    encadernar(&al1, &al4);
    encadernar(&al4, &al2);
    encadernar(&al2, NULL);


	ptr = primero;

	while(ptr!=NULL)
	{
		printf("%d\t%s  %s\n",ptr->expediente, ptr->nombre,ptr->apellido);

		ptr = ptr->siguiente;
	}
}
