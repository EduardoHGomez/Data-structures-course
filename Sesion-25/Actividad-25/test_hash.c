#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "map.h"

#define M 6

MAPLIST table[M];

int main()
{
	char key[60];
	char nombre[80];
	// unsigned long long hashcode;
	int i;
	// int p;

	maplist_table_init(table,M);

	setbuf(stdout,NULL);

	while(1)
	{
		printf("Dame una llave, FIN para terminar :");
		scanf("%s",key);
		if(strcmp(key,"FIN")==0)
			break;
		printf("Nombre completo :");
		scanf("%s",nombre);

		map_insert(table,key,nombre, M);

		// Despliega las listas
		for(i=0;i<M;i++)
		{
			printf("(%d)  ",i);
			maplist_display(table[i]);
		}
	}

	// Despliega las listas
	for(i=0;i<M;i++)
	{
		printf("(%d)  ",i);
		maplist_display(table[i]);
	}

}

