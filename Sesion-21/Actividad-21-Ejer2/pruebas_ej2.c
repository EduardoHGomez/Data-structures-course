#include <stdio.h>
#include <string.h>
#include "set_ejer2.h"
#include <time.h>
#include <stdlib.h>

int comparador_enteros(TYPE a,TYPE b);
void print_entero(TYPE data);

STRING int_to_roman(int num);
int roman_code(char *s);
int comparador_romanos(TYPE a, TYPE b);
void print_romano(TYPE data);
int equivalente_entero(char letra);

/*EJERCICIO 1: Desarrollar las funciones para imprimir, destruir, y comparar */

int main()
{
	srand(time(NULL));
	SET s1 = set_create(comparador_enteros, print_entero);
	SET s2 = set_create(comparador_romanos, print_romano);

	int random;
	STRING romano;
	for (int i = 0; i < 10; i++)
	{
		random = rand() % (100 + 1 - 1) + 1;
		set_add(s1, int_create(random));
		STRING romano = int_to_roman(random); // Primero creamos un STRING del número aleatorio
		set_add(s2, string_create(romano)); // Se añade a s2 para que pase de STRING a TYPE
	}
	

    set_delete(s1);
    set_delete(s2);

}

STRING int_to_roman(int num)
{
    char *conversion = malloc(20);  // Allocate sufficient memory for the Roman numeral string
    int index = 0;
    
    while(num != 0)
    {
        if (num >= 1000)       // 1000 - m
        {
            conversion[index] = 'm';
            index++;
            num -= 1000;
        }
        else if (num >= 900)   // 900 - cm
        {
            conversion[index] = 'c';
            index++;
            conversion[index] = 'm';
            index++;
            num -= 900;
        }        
        else if (num >= 500)   // 500 - d
        {           
            conversion[index] = 'd';
            index++;
            num -= 500;
        }
        else if (num >= 400)   // 400 - cd
        {
            conversion[index] = 'c';
            index++;
            conversion[index] = 'd';
            index++;
            num -= 400;
        }
        else if (num >= 100)   // 100 - c
        {
            conversion[index] = 'c';
            index++;
            num -= 100;                       
        }
        else if (num >= 90)    // 90 - xc
        {
            conversion[index] = 'x';
            index++;
            conversion[index] = 'c';
            index++;
            num -= 90;                                              
        }
        else if (num >= 50)    // 50 - l
        {
            conversion[index] = 'l';
            index++;
            num -= 50;                                                                     
        }
        else if (num >= 40)    // 40 - xl
        {
            conversion[index] = 'x';
            index++;
            conversion[index] = 'l';
            index++;          
            num -= 40;
        }
        else if (num >= 10)    // 10 - x
        {
            conversion[index] = 'x';
            index++;
            num -= 10;           
        }
        else if (num >= 9)     // 9 - ix
        {
            conversion[index] = 'i';
            index++;
            conversion[index] = 'x';
            index++;
            num -= 9;                         
        }
        else if (num >= 5)     // 5 - v
        {
            conversion[index] = 'v';
            index++;
            num -= 5;                                     
        }
        else if (num >= 4)     // 4 - iv
        {
            conversion[index] = 'i';
            index++;
            conversion[index] = 'v';
            index++;
            num -= 4;                                                            
        }
        else if (num >= 1)     // 1 - i
        {
            conversion[index] = 'i';
            index++;
            num -= 1;                                                                                   
        }
    }
    
    conversion[index] = '\0';
    return conversion;
}

int equivalente_entero(char letra)
{
    switch (letra)
    {
    case 'i':
        return 1;
        break;
    
    case 'v':
        return 5;
        break;
    
    case 'x':
        return 10;
        break;

    case 'l':
        return 50;
        break;
    
    case 'c':
        return 100;
        break;

    case 'd':
        return 500;
        break;
    
    case 'm':
        return 1000;
        break;
    default:
    break;
    }
}


int roman_code(char *romano) 
{

    int resultado = 0;
    for (int i = 0; i < strlen(romano); i++)
    {
        if (i + 1 < strlen(romano) && (equivalente_entero(romano[i]) < equivalente_entero(romano[i+1])))
        {
            resultado -= equivalente_entero(romano[i]);
        }
        else
        {
            resultado += equivalente_entero(romano[i]);
        }
        
    }
    
    return resultado;
}

int comparador_romanos(TYPE a, TYPE b)
{
	return (roman_code(a) - roman_code(b));
}

int comparador_enteros(TYPE a,TYPE b)
{
	int ia = *((int *) a);
	int ib = *((int *) b);
	return ia - ib;
}

void print_entero(TYPE data)
{
	printf("%d\n", *((int *)data));
}

void print_romano(TYPE data)
{
	printf("%s",(char *) data);
	printf("\n");
}
