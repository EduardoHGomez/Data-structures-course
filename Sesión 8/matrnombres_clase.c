#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int totnombres;
	char **nombres;
	char nombre[40];
	int i;

	setbuf(stdout,NULL);
	printf("¿Cuántos nombres vas a guardar?");
	scanf("%d",&totnombres);

	nombres = malloc(totnombres * sizeof(char *));
	if(nombres==NULL)
	{
		fprintf(stderr,"Error al solicitar memoria\n");
		exit(1);
	}

	for(i=0;i<totnombres;i++)
	{
		printf("¿Cómo se llama la persona %d?",i+1);
		scanf("%s",nombre);
		nombres[i] = malloc(strlen(nombre)+1);
		if(nombres[i]==NULL)
		{
			fprintf(stderr,"Error al solicitar memoria\n");
			exit(1);
		}
		strcpy(nombres[i],nombre);
	}

	// Mostrar la matriz de nombres
	for(i=0;i<totnombres;i++)
		printf("%s\n",nombres[i]);

	// Liberar la memoria
	for(i=0;i<totnombres;i++)
		free(nombres[i]);
	free(nombres);
}
