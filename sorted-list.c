
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

/*This function will destroy the Sorted list and all its nodes using the given destruct function*/
void DeleteNode(Node*, DestructFuncT);
void SLDestroy(SortedListPtr list){
	DeleteNode(list->first, list->destroy);
	free(list);
}

void DeleteNode(Node *node, DestructFuncT destroy) {
	if(node == NULL) {
		return;
	}
	DeleteNode(node->next, destroy);
	destroy(node->data);
	free(node);

	return;
}

/*This method creates and adds new nodes to the SortedList.*/
int SLInsert(SortedListPtr list, void *newObj) {
	if(newObj == NULL) {
		return 0;
	}

	Node *newNode = (Node *)malloc(sizeof(Node));

	if (newNode == NULL){
		printf("Error\n");
		return 0;
	}

	newNode->data = newObj;
	newNode->numPointers = 0;
	CompareFuncT compare = list->compare;

	Node *curr = list->first, *prev = NULL;
	while(curr != NULL && compare(curr->data, newObj) > 0) {
		prev = curr;
		curr = curr->next;
	}

	if(curr == NULL) {