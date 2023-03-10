#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
  char temp[10];
  strcpy(temp, a); // copia el valor de "a" a temp
  strcpy(a, b);    // copia el valor de "a" a "b"
  strcpy(b, temp); // copia el valor de temp a "b"
}

void printnames(void *names, int len) {
  for (int i = 0; i < len; i++) {
    printf("%s\n", (char *) names); // cast para imprimir los nombres oredenados
    names += len; //+=len(10), para que imprima el siguiente nombre
  }
}

void sortnames(void *nombres, int len) {
  char *nombre = nombres;
  int i, j;
  // Bubble sort, se desplaza el string "mayor" hacia la derecha
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) // Para los 10 nombres
    {
      // Si el lado izquierdo es mayor que el segundo
      if (strcmp(nombre, (nombre + len)) >= 1) // aqui compara toda la cadena con la segunda, sucesivamente
      {
        // Swap izquierda por derecha
        swap(nombre, (nombre + len));
      }

      nombre += len; // Hace un swap por cada ciclo
    }
    nombre = nombres;
    /* Al terminar un ciclo por swap, se regresa
       hasta el inicio con base en la dirección de nombres y repite
       el ciclo for anidado que hace el swap
    */
  }
  return;
}

int main(void) {
  char nombres[10][10] = {"Jose", "Juan",    "Gaby",    "Maria",   "Karla",
                          "Luis", "Antonio", "Cecilia", "Roberto", "Francisco"};

  sortnames(nombres, 10); // ordena nombres
  printnames(nombres, 10);

  return 0;
}