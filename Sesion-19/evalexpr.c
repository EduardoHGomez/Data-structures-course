/*
 * evalexpr.c
 *
 *  Created on: 10 abr 2023
 *      Author: jluis
 */
#include <stdio.h>
#include <math.h>
#include "stack.h"

BOOL isoperando(char c);
BOOL isoperador(char c);
int precedencia(char op);
void stack_operation(STACK operandos,STACK operadores);

int main()
{
	STACK operandos = stack_create();
	STACK operadores = stack_create();
	char expresion[20];
	char *ptr = expresion;
	float result;

	setbuf(stdout,NULL);

	printf("Escribe una expresión aritmética :");
	scanf("%s",expresion);

	while(*ptr!='\0')	// Mientras no lleguemos al final
	{
		if(*ptr=='(')
			stack_push(operadores,char_create(*ptr));

		else if(isoperando(*ptr))
			stack_push(operandos,float_create(*ptr-'0'));
		else if (isoperador(*ptr))
		{
			while(!stack_empty(operadores) &&
					precedencia(*ptr)<=precedencia(char_val(stack_peek(operadores))))
					stack_operation(operandos,operadores);
			stack_push(operadores,char_create(*ptr));
		}
		else if(*ptr==')')
		{
			while(char_val(stack_peek(operadores))!='(')
				stack_operation(operandos,operadores);
			stack_pop(operadores);
		}
		ptr++;
	}

	while(!stack_empty(operadores))
		stack_operation(operandos,operadores);

	result = *((float *) stack_pop(operandos));

	printf("Reusltado = %f\n",result);
}

BOOL isoperando(char c)
{
	return(c>='0' && c<='9');
}

BOOL isoperador(char c)
{
	return(c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

int precedencia(char op)
{
	int retval = -1;

	if(op=='^')
		retval = 3;
	if(op=='*' || op=='/')
		retval = 2;
	if(op=='+' || op=='-')
		retval = 1;

	return(retval);
}

void stack_operation(STACK operandos,STACK operadores)
{
	float op2 = float_val(stack_pop(operandos));
	float op1 = float_val(stack_pop(operandos));
	char operador = *((char *)stack_pop(operadores));
	float result;

	switch(operador)
	{
		case '*':
			result = op1 * op2;
			break;
		case '/':
			result = op1 / op2;
			break;
		case '+':
			result = op1 + op2;
			break;
		case '-':
			result = op1 - op2;
			break;
	}
	stack_push(operandos,float_create(result));
}
