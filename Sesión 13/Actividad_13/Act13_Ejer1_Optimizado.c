#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct STRNUM {
    int num;
    struct STRNUM *next;
};

int es_primo(int n) {
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]){
    struct STRNUM *first = NULL, *new = NULL, *todestroy = NULL, *ptr = NULL;

    int n = atoi(argv[1]);

    printf("Hasta que numero quieres que se verifique que numeros son primos: %d", n);
    printf("\n");

    for(int i = 2; i <= n; i++){
        if (es_primo(i)) {
            if (first == NULL) {
                new = malloc(sizeof(struct STRNUM));
                first = new;
                first->num = i;
                first->next = NULL;
            }
            else {
                ptr = first;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                new = malloc(sizeof(struct STRNUM));
                ptr->next = new;
                new->num = i;
                new->next = NULL;
            }
        }
    }

    ptr = first;
    while (ptr != NULL) {
        printf("%d\n", ptr->num);
        ptr = ptr->next;
    }

    ptr = first;
    while (ptr != NULL) {
        todestroy = ptr;
        ptr = ptr->next;
        free(todestroy);
    }

    return 0;
}
