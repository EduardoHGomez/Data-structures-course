#include <stdio.h>

void swap_pointers(int **pointer_a, int **pointer_b)
{
    // This funcion will have the goal to change where the pointers point so:
    // pointer b will point to the address of the integer a
    // pointer a will poin to the address of the integer b

    printf("Direcciones ingresadas: a = %p b = %p\n", pointer_a, pointer_b);
    // This address will give us what &ptr_a and &ptr_b values are in main
    int *temporal_pointer = *pointer_a;
    *pointer_a = *pointer_b;
    *pointer_b = temporal_pointer;

    // The reason pointer_a = *pointer_b is not used is because we would be changing
    // where the current temporal pointer_a (from this function) and thus won't have an effect
    // after leaving the function 

    // En pocas palabras, acceder con *pointer_a y cambiar el valor que guarda
}

void swap_integers(int *a, int *b)
{    // This function only changes the values of the pointers, but not where it points
    printf("Address of pointers saved in temporal memory: a = %p b = %p\n", &a, &b);
    // In this printf functions it is proved that the address of a and b changes
    // as their contecnt (addres where it points) doesn't
    // a "copy" of the pointers is created while it's contect address remains the same
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 20;
    int b = 50;

    int *ptr_a = &a;
    int *ptr_b = &b;

    printf("Valores iniciales: %d %d\n", *ptr_a, *ptr_b);
    printf("DIRECCIONES DE LOS INTEGERS INICIALES: %p %p\n", ptr_a, ptr_b);

    printf("----------------------\n");
    printf("Address of pointers saved in memory: a = %p b = %p\n", &ptr_a, &ptr_b);
    
    swap_integers(ptr_a, ptr_b);

    printf("----------------------\n");
    printf("Valores finales: a = %d b = %d\n", *ptr_a, *ptr_b);
    printf("Direcciones final: a = %p b = %p\n", ptr_a, ptr_b);

    printf("\n---------Change of address on pointers------\n");
    ptr_a = &a;
    ptr_b = &b;

    printf("\nValores antes de cambiar direccion: %d %d\n", *ptr_a, *ptr_b);
    swap_pointers(&ptr_a, &ptr_b);
    printf("Direcciones despues de cambiarlos en la funcion: a = %p b = %p\n", ptr_a, ptr_b); // Where they point
    printf("Valores despues de cambiar direccion: %d %d\n", *ptr_a, *ptr_b);
    printf("\n");
}

