#include <stdio.h>

int length (char *pcad)
{
    int cont=0; 
    while (*pcad)
    {
        cont++;
        pcad++; 
    }
    
    return cont; 
}

void reverse(char *str)
{
  
  int size = length(str);
  char temp;
  char *ultimo = str + size - 1;
  
  for (int i = 0; i < size/2; i++)
    {
      temp = *str;
      *str = *ultimo;
      *ultimo = temp;
      //printf("%c %c\n", *str, *ultimo);
      str++;
      ultimo--;
    }
  return; 
}


int main()
{
    char string1[] = "Guadalajara";
    reverse(string1);
    printf("%s\n", string1);  // Imprime arajaladauG
}