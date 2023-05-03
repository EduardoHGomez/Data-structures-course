#include <stdio.h>
#include "priorityqueue.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define FIN -1

int compints(TYPE n1,TYPE n2);
void printint(TYPE n);

STRING int_to_roman(int num);
int roman_code(char *s);
int comparador_romanos(TYPE a, TYPE b);
void print_romano(TYPE data);
int equivalente_entero(char letra);

int main()
{
    srand(time(NULL));
	PRIORITYQUEUE pq1 = priorityqueue_create(100, compints, printint);
    PRIORITYQUEUE pq2 = priorityqueue_create(100, comparador_romanos, print_romano);
	int *n;
    STRING s;

    int random;
    STRING romano;
    for (int i = 0; i < 15; i++)
    {
        random = rand() % 100;
        printf("%d ", random);
        priorityqueue_offer(pq1, int_create(random));
        romano = int_to_roman(random); 
        priorityqueue_offer(pq2, string_create(romano));
    }

    printf("\n");
	while(!priorityqueue_isempty(pq1))
	{
		n = priorityqueue_poll(pq1);
		printf("%d ",*n);
	}

    printf("\n");
    while(!priorityqueue_isempty(pq2))
	{
		s = priorityqueue_poll(pq2);
		printf("%s ", s);
	}


}

int compints(TYPE n1,TYPE n2)
{
	int num1 = *((int *) n1);
	int num2 = *((int *) n2);

	return num1 - num2;
}

void printint(TYPE n)
{
	int num = *((int *) n);
	printf("%d ",num);
}

//-----------Funciones----------------------
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

void print_romano(TYPE data)
{
	printf("%s",(char *) data);
	printf("\n");
}