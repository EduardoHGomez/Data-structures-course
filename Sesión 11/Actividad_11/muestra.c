#include <stdio.h>
#include <stdlib.h>

int main() {
  // Buffer de memoria
  setbuf(stdout, NULL);

  // Sacamos los datos del archivo binario salida
  int numeros[3][3];
  FILE *entrada = fopen("salida.bin", "rb");

  if (entrada == NULL) {
    fprintf(stderr, "No se puede el archivo\n");
    exit(1);
  }

  fread(numeros, sizeof(int), 9, entrada);
  fclose(entrada);

  // Mostrar mastriz
  printf("Mostrar matriz resultante\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", *(*(numeros + i) + j));
    }
    printf("\n");
  }
}