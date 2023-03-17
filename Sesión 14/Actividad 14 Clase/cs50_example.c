#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node * next;
} node;

void insert(node **list, int i)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        exit(1);
    }

    n->number = i;
    n->next = NULL;
    n->next = *list;
    *list = n;
    
}

int main()
{
    node *list = NULL;

    for (int i = 0; i < 10; i++)
    {
        insert(&list, i);
    }

    node *ptr = list;
    for(node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->number);
        
    }
    
}