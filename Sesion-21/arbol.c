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
        (*root)->right = NULL;
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

void tree_inorder(struct STRTNODE *root)
{
    if (root != NULL)
    {
        tree_inorder(root->left);
        printf("%d ", root->num);
        tree_inorder(root->right);
    }
    
}

void tree_preorder(struct STRTNODE *root)
{
    if (root != NULL)
    {
        tree_preorder(root->right);
        printf("%d ", root->num);
        tree_preorder(root->left);
    }   
}

void tree_postorder(struct STRTNODE *root)
{
    if(root!=NULL)
    {
        tree_postorder(root->left);
        tree_postorder(root->right);
        printf("%d\t",root->num);
    }
}

void tree_print(int level,struct STRTNODE *root)
{
int i;
if(root!=NULL)
{
    for(i=0;i<level;i++)
        printf("\t");
    printf("%d\n",root->num);

}
}

int main()
{
    srand(time(NULL));

    struct STRTNODE *root = NULL;
    int n;
    for(int i = 0; i < 15; i++)
    {
        n = rand() % 100;
        printf("%d ", n);
        treeinsert(&root, n);
    }

    printf("\nNodo raiz: %d\n", root->num);

	printf("\nRecorrido en inorden\n");
	tree_inorder(root);

	printf("\nRecorrido en preorden\n");
	tree_preorder(root);
}