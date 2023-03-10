/*
Actividad 6
Harel Alejandro Olguín Gaytán
José Eduardo
*/
#include <stdio.h>

/*
=== PRINT CHAR ===
*/
void printchar (void *arr, char *format) {
  printf(format, *((char *) arr));
  printf("\n");
}

/*
=== PRINT SHORT ===
*/
void printshort (void *arr, char *format) {
  printf(format, *((short *) arr));
  printf("\n");
}

/*
=== PRINT INT ===
*/
void printint (void *arr, char *format) {
  printf(format, *((int *) arr));
  printf("\n");
}

/*
=== PRINT LONG ===
*/
void printlong (void *arr, char *format) {
  printf(format, *((long *) arr));
  printf("\n");
}

/*
=== PRINT DOUBLE ===
*/
void printdouble( void *arr, char *format){
  printf(format, *((double *) arr));
  printf("\n");
}

/*
=== PRINT FLOAT ===
*/
void printfloat(void *arr, char *format){
  printf(format, *((float *) arr));
  printf("\n");
}

int main(void) 
{ 
  char arr[] = {'A', 'B', 100, 20, 0x4E, 50, 60, 'M', 'D', 0x25, 040};
  char x = 100;


  //printf("%c %f", x, (float) arr[0]);

  printf("%f\n", *((float *) arr));
  
  for (int i = 0; i < sizeof(arr); i++) {
    printf("ITERACION %d\n", i + 1);
    printchar((arr + i), "%c"); //char
    printchar((arr + i), "%d"); //char
    printshort((arr + i), "%X"); //Short
    printint((arr + i), "%X"); //int
    printlong((arr + i), "%Lu"); //long
    printfloat((arr + i), "%f"); //float
    printdouble((arr + i), "%X"); //double
    printf("\n"); 
    
  }
  
    printf("%08X\n", (float *) arr);

    return 0;
}