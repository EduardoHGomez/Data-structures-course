#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int totnombres;
    char **nombres;
    char nombre[40];

    setbuf(stdout, NULL);
    printf("Cuantos nombres vas a guardar? ");
    scanf("%d", &totnombres);

    nombres = malloc(totnombres * sizeof(char *));

    for (int i = 0; i < totnombres; i++)
    {
        printf("Como se llama la persona %d? ", i+1);
        scanf("%s", &nombre);

        /**
         * Se agrega el +1 por el character '\0'
        */
        nombres[i] = malloc(strlen(nombre)+1); //No se agrega *sizeof(char) dado que es 1
        if (nombres[i] == NULL)
        {
            fprintf(stderr, "Error al solicitar memoria");
            exit(1);
        }
        strcpy(nombres[i], nombre);
    }

    //Mostrar la matriz de nombres
    for (int i = 0; i < totnombres; i++)
    {
        printf("%s\n", nombres[i]);
    }
    
    //Liberar la memoria
    for (int i = 0; i < totnombres; i++)
    {
        printf("%p\n", nombres[i]);
        free(nombres[i]);
    }
    free(nombres);
    
    
}