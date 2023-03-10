/*
 * EJEMPLO cómo usar typedef
 *
 *  Created on: 23 ene 2023
 *      Author: jluis
 */
#include <stdio.h>

typedef int entero;

struct FECHASTR {
	int dia,mes,anio;
};

// Aquí se vuelven a nombrar, para referirse a fechastr como FECHA
typedef struct FECHASTR FECHA;

int main()
{
	entero i,j;

	struct FECHASTR f1 = {23,1,2023};
	struct FECHASTR *fp = &f1;

	FECHA f2 = {24,1,2023};
	FECHA *pf2 = &f2;


}
