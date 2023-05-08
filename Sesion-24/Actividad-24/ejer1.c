#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct STRMLNODE {
	char key[60];
	char data[80];
	struct STRMLNODE *next;
	struct STRMLNODE *prev;
};

struct STRMAPLIST {
	struct STRMLNODE *first;
	struct STRMLNODE *last;
};

#define M 10

struct STRMAPLIST table[M];

void list_insert (int posicion, char *key, char *nombre)
{

    // Crear la nueva estructura
    struct STRMLNODE *toinsert = malloc(sizeof(struct STRMLNODE));
    toinsert->next = NULL;
    toinsert->prev = NULL;
    strcpy(toinsert->key, key);
    strcpy(toinsert->data, nombre);

    struct STRMLNODE *tomove = table[posicion].first;

    if (table[posicion].first == NULL) {
        table[posicion].first = toinsert;
        table[posicion].last = toinsert;
    } 
    else 
    {
        toinsert->prev = table[posicion].last;
        table[posicion].last->next = toinsert;
        table[posicion].last = toinsert;
    }

    
}

int hash(char *s);
void inicializarTabla();

int main()
{
	char key[60];
	char nombre[80];

	int p;
    long long hash_result;

    table->first = NULL;
    table->last = NULL;

	setbuf(stdout, NULL);

	while(1)
	{
		printf("Dame una llave, FIN para terminar: ");
		scanf("%s",key);
		if(strcmp(key,"FIN")==0)
			break;
		printf("Nombre completo: ");
		scanf("%s",nombre);

		hash_result = hash(key);
        p = hash_result % 10;

        list_insert(p, key, nombre);

	}


    // Imprimir tabla hash
    for (int i = 0; i < 10; i++)
    {
        printf("%d: ", i);
        struct STRMLNODE *toprint = table[i].first;
        while (toprint != NULL)
        {
            printf("<%s>, <%s> ", toprint->key, toprint->data);
            toprint = toprint->next;
        }

        printf("\n");
    }

}

int hash(char *s)
{
	return  toupper(s[0]) - 65;
}

void inicializarTabla()
{
    for (int i = 0; i < 10; i++)
    {
        table[i].first = NULL;
        table[i].last = NULL;
    }
    
}
