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
	al3.siguiente = &al5;
	al5.siguiente = &al6;
	al6.siguiente = &al1;
	al1.siguiente = &al4;
	al4.siguiente = &al2;

	ptr = primero;

	while(ptr!=NULL)
	{
		printf("%d\t%s  %s\n",ptr->expediente, ptr->nombre,ptr->apellido);

		ptr = ptr->siguiente;
	}
    


}
