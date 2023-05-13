#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "map.h"

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
	for (int i = 0; i < m; i++)
	{
		table[i].list->first = NULL;
		table[i].list->last = NULL;
	}
	
}

void maplist_insert(MAPLIST *lista_indice,char *key,char *data)
{
	struct STR_LIST_NODE *ptr = lista_indice->list->first;

	while(ptr!=NULL && strcmp(ptr->key,key)!=0)
		ptr = ptr->next;

	if(ptr==NULL)
	{
		ptr = malloc(sizeof(struct STR_LIST_NODE));
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

void map_insert(MAPLIST *map,char *key,char *data, int M)
{
	unsigned long long hashcode = hash(key);
	int p = (int) hashcode % M;

	printf("El código es %016llX\n",hashcode);
	p = (int) (hashcode % M);
	printf("Posición en la tabla(p) es %d\n",p);

	maplist_insert(&map[p].list,key,data);
}

void maplist_display(MAPLIST list)
{
	struct STR_LIST_NODE *ptr = list.list;

	while(ptr!=NULL)
	{
		printf("<\"%s\",\"%s\"> ",ptr->key,ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}