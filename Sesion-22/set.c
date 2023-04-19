#include "set.h"

SET set_create(COMPAREFUNC cf, PRINTFUNC pf)
{
    SET new_set = malloc(sizeof(struct STRSET));
    new_set->tree_root = NULL; // Inicia ocn el árbol vacío

    new_set->size = 0;
    new_set->cf = cf;
    new_set->pf = pf;

    return new_set;
}

SET set_add(SET set, TYPE e)
{
    if (tree_insert(set->tree_root, e))
    {
        set->size = set->size + 1;
    }
}

// Funciones para el manejo de los árboles
void treeinsert(struct STRTNODE **root, int n)
{
    if(*root == NULL)
    {
        *root = malloc(sizeof(struct STRTNODE));
        (*root)->elem = n;
        (*root)->right = NULL;
        (*root)->left = NULL;
    
    }
    else if (cf,(e, (*root)->elem) < 0)
    {
        treeinsert(&(*root)->left, n);
    }
    else if (n > (*root) -> elem)
    {
        treeinsert(&(*root)->right, n);
    }

}

int set_size(SET set)
{
    return set->size;
}