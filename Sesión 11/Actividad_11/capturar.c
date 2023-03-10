#include <stdio.h>
#include <stdlib.h>

void toLower(char *word);

int main(void) {
  // Buffer de memoria
  setbuf(stdout, NULL);

  // Definimos el epsacio de memroria para las matrices
  int **matA = (int **)malloc(3 * sizeof(int *));
  int *numerosA = malloc(9 * sizeof(int));
  int **matB = (int **)malloc(3 * sizeof(int *));
  int *numerosB = malloc(9 * sizeof(int));

  // Asignamos memoria individualmente a cada columna
  for (int i = 0; i < 3; i++) {
    *(matA + i) = numerosA + i * 3;
    *(matB + i) = numerosB + i * 3;
  }

  
   // Le pedimos al usuario la Matriz a llengar
   char matriz[2];
   printf("Cual matriz deseas ingresar los numeros (A o B): ");
   scanf("%s", matriz);
   toLower(matriz);

   // En base a la tabla ascci hacemos la comparacion
   if (*matriz == 65) {
     for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
         printf("Ingrese el número de matrizA[%d][%d]: ", i, j);
         scanf("%d", *(matA + i) + j);
       }
     }
   } else {
     for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
         printf("Ingrese el número de matrizB[%d][%d]: ", i, j);
         scanf("%d", *(matB + i) + j);
       }
     }
   }

   // Llenamos el archivo de binarios
   FILE *entrada = fopen("entrada.bin", "r+b");

   if (entrada == NULL) {
     fprintf(stderr, "No se puede el archivo\n");
     exit(1);
   }

   if (*matriz == 65) {
     fwrite(numerosA, sizeof(int), 9, entrada);
   } else {
     fseek(entrada, sizeof(int) * 9, SEEK_SET);
     fwrite(numerosB, sizeof(int), 9, entrada);
   }

   fclose(entrada); 

  // Liberamos la memoria de adentro hacia afuera
  free(numerosA);
  free(numerosB);

  // Lo que esta "mas afuera"
  free(matA);
  free(matB);
}

// Convertimos a o b = A o B
void toLower(char *word) {
  if (*word == 97 || *word == 98) {
    *word -= 32;
  }
}