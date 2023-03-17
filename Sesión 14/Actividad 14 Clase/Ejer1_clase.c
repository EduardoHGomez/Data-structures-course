#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Usar la dirección: Cambiar el contenido
 * Enviar el apuntador: Extraer la información
*/
#define LIMIT 20

struct STRNODE {
    int num;
    struct STRNODE *next;
};

typedef struct {
    struct STRNODE *first;
    struct STRNODE *last;
} LIST;

#define LISTINIT {NULL,NULL}

int main()
{
    LIST l = LISTINIT;
    int i,n;

    srand(time(NULL));

    for(i=0;i<LIMIT;i++)
    {
        n = rand() % LIMIT;
        if(!found(l,n))
            insert(&l,n);
    }

}
