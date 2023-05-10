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

void hash_find(int posicion, char *key)
{
    // Crear la nueva estructura
    struct STRMLNODE *tofind = table[posicion].first;

    int indexFound = 0;
    while (tofind != NULL)
    {
        if (strcmp(tofind->key, key) == 0)
        {
            printf("Llave: %s Valor: %s Posicion de la tabla: %d Posicion de la lista hash %d\n",
            tofind->key, tofind->data, posicion, indexFound);
            return;
        }
        indexFound++;
        tofind = tofind->next;
    }
    
    printf("Llave no encontrada\n");
    
}

void hash_insert (int posicion, char *key, char *nombre)
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

	while(1)
	{
        setbuf(stdout, NULL);
		printf("Dame una llave, FIN para terminar: ");
		scanf("%s",key);
		if(strcmp(key,"FIN")==0)
			break;
        fflush(stdin);

		printf("Nombre completo: ");
		scanf("%s",nombre);
        fflush(stdin);

		hash_result = hash(key);
        p = hash_result % 10;

        hash_insert(p, key, nombre);
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

    // 3. Preguntar al usuario sobre una búsqueda
    while (1)
    {
		printf("Dame una llave para buscar, FIN para terminar: ");
		scanf("%s",key);
		if(strcmp(key,"FIN")==0)
			break;

		hash_result = hash(key);
        p = hash_result % 10;

        hash_find(p, key);
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
