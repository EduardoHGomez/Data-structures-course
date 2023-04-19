#include "set.h"

SET set_create(COMPAREFUNC cf,PRINTFUNC pf)
{
	SET new_set = malloc(sizeof(struct STRSET));
	new_set->tree_root = NULL;	//Inicia con el árbol vacío
	new_set->size = 0;
	new_set->cf = cf;
	new_set->pf = pf;

	return new_set;
}

void set_add(SET set,TYPE e)
{
	if(tree_insert(&set->tree_root,e,set->cf))
		set->size = set->size + 1;
}

int set_size(SET set)
{
	return set->size;
}

void set_print(SET set)
{
	tree_print(0,set->tree_root,set->pf);
}

// Funciones para el manejo de los árboles
int tree_insert(struct STRTNODE **root,TYPE e,COMPAREFUNC cf)
{
	int inserted = 0;
	if(*root==NULL)
	{
		*root = malloc(sizeof(struct STRTNODE));
		(*root)->elem = e;
		(*root)->left = NULL;
		(*root)->right = NULL;
		inserted = 1;
	}
	else if(cf(e,(*root)->elem)<0)
		inserted = tree_insert(&(*root)->left,e,cf);
	else if(cf(e,(*root)->elem)>0)
		inserted = tree_insert(&(*root)->right,e,cf);

	return inserted;
}

void tree_print(int level,struct STRTNODE *root,PRINTFUNC pf)
{
	int i;
	if(root!=NULL)
	{
		tree_print(level+1,root->right,pf);

		for(i=0;i<level;i++)
			printf("\t");
		pf(root->elem);

		tree_print(level+1,root->left,pf);
	}
}