#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct STRTNODE {
    int num;
    struct STRTNODE *left;
    struct STRTNODE *right;
};

void treeinsert(struct STRTNODE **root, int n)
{
    if(*root == NULL)
    {
        *root = malloc(sizeof(struct STRTNODE));
        (*root)->num = n;
        (*root)->left = NULL;
    
    }
    else if (n < (*root) -> num)
    {
        treeinsert(&(*root)->left, n);
    }
    else if (n > (*root) -> num)
    {
        treeinsert(&(*root)->right, n);
    }

}

int main()
{
    srand(time(NULL));

    struct STRTNODE *root = NULL;

    for(int i = 10; i < 15; i ++)
    {
        int n = rand() % 100;
        treeinsert(&root, n);
    }

    printf("Nodo raiz: %d\n", root->num);
}