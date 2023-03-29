/*
 * ejemplo_vec3.c
 *
 *  Created on: 22 feb 2023
 *      Author: jluis
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definición del TDA para VEC3
struct VEC3_STR {
	float x;
	float y;
	float z;
};

// Exponer, ¿cómo lo pueden ver desde el programa?
// Ocultar los datos que están adentro
typedef struct VEC3_STR * VEC3;

// Encabezados de las funciones para las operaciones del VEC3
VEC3 vec3_create(float x,float y,float z);
float vec3_magnitude(VEC3 v);
void vec3_to_unit(VEC3 v);
void vec3_print(VEC3 v);
void vec3_destroy(VEC3 v);

int main()
{
	VEC3 v1 = vec3_create(2.0,5.5,6.7);
	float mag = vec3_magnitude(v1);
	printf("La magnitud del vector es %7.4f\n",mag);
	vec3_to_unit(v1);
	vec3_print(v1);
	vec3_destroy(v1);
}

// Implementación de las funciones
VEC3 vec3_create(float x,float y,float z)
{
	VEC3 v = malloc(sizeof(struct VEC3_STR));
	if(v!=NULL)
	{
		v->x = x;
		v->y = y;
		v->z = z;
	}
	return(v);
}

float vec3_magnitude(VEC3 v)
{
	return sqrt(pow(v->x,2) + pow(v->y,2) + pow(v->z,2));
}

void vec3_to_unit(VEC3 v)
{
	float m = vec3_magnitude(v);
	v->x = v->x / m;
	v->y = v->y / m;
	v->z = v->z / m;
}

void vec3_print(VEC3 v)
{
	printf("{\n");
	printf("\t\"x\":%7.4f,\n",v->x);
	printf("\t\"y\":%7.4f,\n",v->y);
	printf("\t\"z\":%7.4f\n",v->z);
	printf("}\n");
}

void vec3_destroy(VEC3 v)
{
	free(v);
}
