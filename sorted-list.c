
#include "sorted-list.h"
#include <stdio.h>
/*This method checks if a node has no external pointers pointing to it, and if not, deletes the node*/
void checkPointers(Node *node,DestructFuncT destroy) {
	if(node == NULL) {
		return;
	}
	if(node->numPointers <= 0) {
		destroy(node->data);
		free(node);
	}
}

/*This function creates the SortedList entity.*/
SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df) {

	SortedListPtr SL = (SortedListPtr) malloc(sizeof(struct SortedList));

	if(SL == NULL) {
		return NULL;
	}
	SL->first = NULL;
	SL->compare = cf;
	SL->destroy = df;

	return SL;
}