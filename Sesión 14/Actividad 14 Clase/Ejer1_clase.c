#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Usar la dirección: Cambiar el contenido
 * Enviar el apuntador: Extraer la información
*/
#define LIMIT 10

typedef struct STRNODE {
    int num;
    struct STRNODE *next;
} node;

#define LISTINIT {NULL,NULL}
//-----------Funciones----------

int main()
{
    srand(time(NULL));
    node *list = NULL;

    

}
