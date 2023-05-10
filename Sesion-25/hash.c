/*
 * hash.c
 *
 *  Created on: 3 may 2023
 *      Author: jluis
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct STRMLNODE {
	char key[60];
	char data[80];
	struct STRMLNODE *next;
};

struct STRMAPLIST {
	struct STRMLNODE *first;
	struct STRMLNODE *last;
};

typedef struct STRMAPLIST MAPLIST;

#define M 6

MAPLIST table[M];

unsigned long long hash(char *s);
void maplist_table_init(MAPLIST *table,int m);
void maplist_insert(MAPLIST *list,char *key,char *data);
void maplist_display(MAPLIST list);
void map_insert(MAPLIST *map,char *key,char *data);


int main()
{
	char key[60];
	char nombre[80];
	unsigned long long hashcode;
	int i;
	int p;

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

		hashcode = hash(key);
		printf("El código es %016llX\n",hashcode);
		p = (int) (hashcode % M);
		printf("Posición en la tabla(p) es %d\n",p);

		/* Insertar un nodo en la lista p correspondiente
		 * que contenga la llave y el nombre
		 */
		// maplist_insert(&table[p],key,nombre);
		map_insert(table,key,nombre);

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

unsigned long long hash(char *s)
{
	int len = strlen(s);
	int i=0;
	unsigned long long retcode = 0;
	char c;

	if(len>12)
		len = 12;

	while(i<len && s[i]!='\0')
	{
		c = toupper(s[i]);
		if(c>='A' && c<='Z')
		{
			retcode = retcode << 5;
			retcode = retcode | (c & 0x1F);
		}
		i++;
	}

	return retcode;
}

void maplist_table_init(MAPLIST *table,int m)
{
	int i;
	for(i=0;i<m;i++)
	{
		table[i].first=NULL;
		table[i].last=NULL;
	}
}

void maplist_insert(MAPLIST *list,char *key,char *data)
{
	struct STRMLNODE *ptr = list->first;

	while(ptr!=NULL && strcmp(ptr->key,key)!=0)
		ptr = ptr->next;

	if(ptr==NULL)
	{
		ptr = malloc(sizeof(struct STRMLNODE));
		strcpy(ptr->key,key);
		ptr->next = NULL;
		if(list->first==NULL)
			list->first = ptr;
		else
			list->last->next = ptr;

		list->last = ptr;
	}

	strcpy(ptr->data,data);
}

void map_insert(MAPLIST *map,char *key,char *data)
{
	unsigned long long hashcode = hash(key);
	int p = (int) hashcode % M;

	maplist_insert(&map[p],key,data);
}

void maplist_display(MAPLIST list)
{
	struct STRMLNODE *ptr = list.first;

	while(ptr!=NULL)
	{
		printf("<\"%s\",\"%s\"> ",ptr->key,ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
