#include <stdio.h>
#include <stdlib.h>

struct STRNUM {
    int data;
    struct STRNUM *next;
};

int main()
{
    struct STRNUM *top = NULL, *new = NULL, *ptr = NULL, *destr = NULL;
    int num;
    setbuf(stdout,NULL);

    do
    {
        printf("Dame un numero (0 para terminar): ");
        scanf("%d", &num);


        if (num != 0)
        {
            new = malloc(sizeof(struct STRNUM));
            new->data = num;
            new->next = top;

            top = new;
        }
        

    } while (num != 0);
    
    ptr = top;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    
    // Destruir los nodos
    ptr = top;
    while (ptr != NULL)
    {
        destr = ptr;
        ptr = ptr->next;
        free(destr);
    }
    

}