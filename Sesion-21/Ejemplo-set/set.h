#ifndef SET_H_

#include "datatypes.h"

struct STRTNODE {
	TYPE elem;
	struct STRTNODE *left;
	struct STRTNODE *right;
};

struct STRSET {
	struct STRTNODE *tree_root;
	int size;
	COMPAREFUNC cf;
	PRINTFUNC pf;
};

typedef struct STRSET * SET;

SET set_create(COMPAREFUNC cf,PRINTFUNC pf);
SET set_add(SET set, TYPE e);
void treeinsert(struct STRTNODE **root, int n);
int setSize(SET set);

#define SET_H_
#endif /* SET_H_ */