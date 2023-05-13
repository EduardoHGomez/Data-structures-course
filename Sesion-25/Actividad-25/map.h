#ifndef MAP_H_
#define MAP_H_

#include "datatypes.h"

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

unsigned long long hash(char *s);
void maplist_table_init(MAPLIST *table,int m);
void maplist_insert(MAPLIST *list,char *key,char *data);
void maplist_display(MAPLIST list);
void map_insert(MAPLIST *map,char *key,char *data);

#endif /* MAP_H_ */
