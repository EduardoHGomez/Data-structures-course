#include "list.h"

LIST list_create()
{
	LIST new = malloc(sizeof(struct STR_LIST));
	new->first = NULL;
	new->last = NULL;
	new->size = 0;
	return new;
}

void list_add(LIST l,TYPE e)
{
	l->last = list_insert(l->first, e);
	
	l->size++;
}

struct STR_LIST_NODE* list_insert(struct STR_LIST_NODE *head, TYPE e)
{
	// EXTRAIDO DE https://www.geeksforgeeks.org/recursive-insertion-and-traversal-linked-list/
    // If linked list is empty, create a
    // new node (Assuming newNode() allocates
    // a new node with given data)
    if (head == NULL)
	{
		printf("Here\n");
		struct STR_LIST_NODE *new = malloc(sizeof(struct STR_LIST_NODE));
		new->elem = e;
        return new;
	}
 
    // If we have not reached end, keep traversing
    // recursively.
    else
        head->next = list_insert(head->next, e);
    return head;
}

int list_size(LIST l)
{
	return(l->size);
}

TYPE list_get(LIST l,int pos)
{
	struct STR_LIST_NODE *ptr = l->first;
	int i;

	for(i=0;i<pos;i++)
		ptr = ptr->next;

	return(ptr->elem);
}

void list_destroy(LIST l)
{
	struct STR_LIST_NODE *ptr, *toremove;

	ptr = l->first;

	while(ptr!=NULL)
	{
		toremove = ptr;
		ptr = ptr->next;
		free(toremove);
	}
	free(l);
}
