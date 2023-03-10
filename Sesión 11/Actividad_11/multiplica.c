#include <stdio.h>
#include <stdlib.h>

int main() { 
  
  // Buffer de memoria
  setbuf(stdout, NULL);

  // LLenamos las matricez en base a archivo binario
  int a[3][3], b[3][3], c[3][3];
  FILE *entrada = fopen("entrada.bin", "rb");

  if (entrada == NULL) {
    fprintf(stderr, "No se puede el archivo\n");
    exit(1);
  }

  fread(a, sizeof(int), 9, entrada);
  fseek(entrada, sizeof(int) * 9, SEEK_SET);
  fread(b, sizeof(int), 9, entrada);
  fclose(entrada);

  // Multipilicacion
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int sum = 0;
      for (int k = 0; k < 3; k++) {
        sum += *(*(a + i) + k) * *(*(b + k) + j);
      }
      *(*(c + i) + j) = sum;
    }
  }
  // Creamos el archvo de salida en base a la matriz c
  FILE *salida = fopen("salida.bin", "wb");
  
  if (salida == NULL) {
    fprintf(stderr, "No se puede el archivo\n");
    exit(1);
  }

  fwrite(c, sizeof(int), 9, salida);
  fclose(salida);

  printf("Matrices multiplicadas\n");
}