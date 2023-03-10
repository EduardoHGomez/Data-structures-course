/*
 * ejemplo_vec3.c
 *
 *  Created on: 22 feb 2023
 *      Author: jluis
 */
#include <stdio.h>
#include "vec3.h"

int main()
{
	VEC3 v1 = vec3_create(2.0,5.5,6.7);
	VEC3 vx;
	float mag = vec3_magnitude(v1);
	printf("La magnitud del vector es %7.4f\n",mag);
	vec3_to_unit(v1);
	vec3_print(v1);
	vec3_destroy(v1);

	vx = vec3_create(5.0,7.0,8.0);
	vec3_print(vx);
	vec3_to_unit(vx);
	mag = vec3_magnitude(vx);
	printf("La magnitud del vector es %7.4f\n",mag);
}

