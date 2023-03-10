#include <stdio.h>

int main()
{
    int arr[] = {97,98,99,100}; // 4 bytes

	void *vp;
	int *ip;

	vp = arr; 
	ip = vp; 

    //Imprime 1684234849 - a
    printf("%d - %c\n", *ip, *arr);
 

}