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

void insert(struct STRALUM **first,struct STRALUM *alum_structure)
{
    struct STRALUM *ptr = NULL;
    if (*first == NULL)
    {   //Almacenar en first original la dirección de next
        *first = alum_structure;
    }
    else
    {
        ptr = *first;
        while(ptr->siguiente != NULL)
        {
            ptr = ptr->siguiente;
        }
        /**
         * ptr->siguiente solo se aplica para después de la primera iteración
         * donde se almacena la dirección de la que se envía
        */
        ptr->siguiente = alum_structure;
    }
    

}


int main()
{
	struct STRALUM al1 = {"David Rodrigo","Leon",744025,NULL};
	struct STRALUM al2 = {"Ximena","Isaac",739032,NULL};
	struct STRALUM al3 = {"Luis Fernando","Chávez",734822,NULL};
	struct STRALUM al4 = {"Renata","Tejeda",739500,NULL};
	struct STRALUM al5 = {"Harel","Olguín",742621,NULL};
	struct STRALUM al6 = {"Brenda","Vela",740732,NULL};

    struct STRALUM *primero = NULL; //Apuntador a estructuras tipo STRALUM
    struct STRALUM *ptr = NULL;

    insert(&primero, &al1);
    insert(&primero, &al2);
    insert(&primero, &al3);
    insert(&primero, &al4);
    insert(&primero, &al5);
    insert(&primero, &al6);

    ptr = primero->siguiente;
    while(ptr != NULL)
    {
        printf("%s\t%s\t%d\n", ptr->nombre, ptr->apellido, ptr->expediente);
        ptr = ptr->siguiente;
    }


}

