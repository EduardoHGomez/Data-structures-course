/*
 * vec3.h
 *
 *  Created on: 22 feb 2023
 *      Author: jluis
 */

#ifndef VEC3_H_
#define VEC3_H_


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
// Solo la definición y no la implementación
VEC3 vec3_create(float x,float y,float z);
float vec3_magnitude(VEC3 v);
void vec3_to_unit(VEC3 v);
void vec3_print(VEC3 v);
void vec3_destroy(VEC3 v);




#endif /* VEC3_H_ */
