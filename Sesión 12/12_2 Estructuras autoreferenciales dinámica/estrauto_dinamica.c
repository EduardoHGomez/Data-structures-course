/*
 * estrauto.c
 * Encadenación con memoria dinámica y función
 */
#include <stdio.h>

struct STRALUM {
	char nombre[30];
	char apellido[30];
	int expediente;
	struct STRALUM *siguiente;
};

void encadenar(struct STRALUM *a,struct STRALUM *b);

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
	encadenar(&al3,&al5);
	encadenar(&al5,&al6);
	encadenar(&al6,&al1);
	encadenar(&al1,&al4);
	encadenar(&al4,&al2);
	encadenar(&al2,NULL);

	al2.siguiente = NULL;

	ptr = primero;

	while(ptr!=NULL)
	{
		printf("%d\t%s  %s\n",ptr->expediente,
				ptr->nombre,ptr->apellido);

		ptr = ptr->siguiente;
	}
}

void encadenar(struct STRALUM *a,struct STRALUM *b)
{
	a->siguiente = b;
}
