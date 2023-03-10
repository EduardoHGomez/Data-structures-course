#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *p1, *p2;
    p1 = malloc(100 * sizeof(int));
    if (p1 == NULL)
    {
        fprintf(stderr, "Falló asignación de memoria");
        exit(1);
    }
    p2 = calloc(100, sizeof(int));
    if (p2 == NULL)
    {
        fprintf(stderr, "Falló asignación de memoria p2");
        exit(1);
    }
    
    printf("Contenido de los datos apuntados por p1: \n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", p1[i]);
    }
    
    printf("\nContenido de los datos apuntados por p2: \n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", p2[i]);
    }

    memset(p1, 0, 100*sizeof(int));
    printf("\nDespués de inicializar el contenido de p1:\n");
    for (int i = 0; i < 10; i++)
    {
        /* code */
    }
    
    
    free(p1);
    free(p2);
}