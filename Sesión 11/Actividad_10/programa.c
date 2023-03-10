#include <stdio.h>
#include <stdlib.h>

int main(void) {

  // Inicializamos las matrices & su espacio
  int **matA = (int **)malloc(3 * sizeof(int *));
  int *matAFull = (int *)malloc(9 * sizeof(int));

  int **matB = (int **)malloc(3 * sizeof(int *));
  int *matBFull = (int *)malloc(9 * sizeof(int));

  int **matC = (int **)malloc(3 * sizeof(int *));
  int *matCFull = (int *)malloc(9 * sizeof(int));

  // Si hay un error al asignar memoria
  if (matA == NULL || matAFull == NULL || matB == NULL || matBFull == NULL ||
      matC == NULL || matCFull == NULL) {
    fprintf(stderr, "Error al solicitar la memoria\n");
    exit(1);
  }

  // Hacemos que cada puntero de la matriz apunte a una sección del bloque de
  // memoria
  for (int i = 0; i < 3; i++) {
    *(matA + i) = matAFull + i * 3;
    *(matB + i) = matBFull + i * 3;
    *(matC + i) = matCFull + i * 3;
  }

  // Pedimos los datos de la matriz A
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("Dame el dato matA[%d][%d]: ", i, j);
      scanf("%d", (*(matA + i) + j));
    }
  }
  printf("\e[1;1H\e[2J");

  // Se comprueba la escritura en a
  FILE *a = fopen("a.txt", "w");
  if (a == NULL) {
    fprintf(stderr, "No se puede el archivo\n");
    exit(1);
  }
  // Creamos el archivo a.txt
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      fprintf(a, "%d ", *(*(matA + i) + j));
    }
    fprintf(a, "\n");
  }
  fclose(a);

   // Pedimos los datos de la matriz B
 for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("Dame el dato matB[%d][%d]: ", i, j);
      scanf("%d", (*(matB + i) + j));
    }
  }

  
  // Se comprueba la escritura en b
  FILE *b = fopen("b.txt", "w");
  if (b == NULL) {
    fprintf(stderr, "No se puede el archivo\n");
    exit(1);
  }

  // Para cada celda se almacenará 
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      fscanf(b, "%d", (*(matB + i) + j));
      fprintf(b, "%d ", *(*(matB + i) + j));
    }
    fprintf(b, "\n");
  }
  fclose(b);

  // Guardamos las datos en la Matriz A del archivo de texto
  a = fopen("a.txt", "r");
  if (a == NULL) {
    fprintf(stderr, "No se puede el archivo\n");
    exit(1);
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      fscanf(a, "%d", (*(matA + i) + j));
    }
  }
  fclose(a);

  // Guardamos las datos en la Matriz B del archivo de texto
  b = fopen("b.txt", "r");

  if (b == NULL) {
    fprintf(stderr, "No se puede el archivo\n");
    exit(1);
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      fscanf(b, "%d", (*(matB + i) + j));
    }
  }
  fclose(b);

  // Multplicacion
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int sum = 0;
      for (int k = 0; k < 3; k++) {
        sum += *(*(matA + i) + k) * *(*(matB + k) + j);
      }
      *(*(matC + i) + j) = sum;
    }
  }

  // Escritura en out.txt
  FILE *c = fopen("c.txt", "w");
  if (c == NULL) {
    fprintf(stderr, "No se puede el archivo\n");
    exit(1);
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      fprintf(c, "%d ", *(*(matC + i) + j));
    }
    fprintf(c, "\n");
  }

  fclose(c);

  // Liberar memoria
  free(matAFull);
  free(matBFull);
  free(matCFull);

  free(matA);
  free(matB);
  free(matC);

  return 0;
}
