
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
		if(prev == NULL) {
	//		printf("first node is initialized\n");
			list->first = newNode;
		} else {
			prev->next = newNode;
		}
		newNode->next = NULL;
	} else {
		if(compare(curr->data, newObj) == 0) {
			free(newNode);
			if(curr->data != newObj) {
				list->destroy(newObj);
			}
			printf("node was freed because of duplicate \n");
			return 0;
		}
		if(prev == NULL) {
			newNode->next = curr;
			list->first = newNode;
		} else {
			newNode->next = curr;
			prev->next = newNode;
		}
	}
	newNode->numPointers++;
	printf("%s %d\n",(char *)(newNode->data),newNode->numPointers);
	return 1;
}

/*This method removes nodes from the sorted list, selected by data object.
 * However, node is disconnected from sorted list but not destroyed unless
 * no pointers (including iterator pointers) are pointing to it.*/
int SLRemove(SortedListPtr list, void *newObj) {
	Node *prev, *curr;
	for(curr = list->first, prev = NULL; curr != NULL; curr = curr->next) {
		if(curr->data == newObj) {
			break;
		}
		prev = curr;
	}
	if (curr == NULL){
		return 0;
	} 
	if(prev == NULL){
		list->first = list->first->next;
	}
	else{
		prev->next = curr->next;

	}
	curr->numPointers--;
	printf("Remove: %s %d\n",(char *)(curr->data),curr->numPointers);
	checkPointers(curr,list->destroy);
	return 1;
}

/*This method creates the iterator that points to the 1st element in the SortedList.*/
SortedListIteratorPtr SLCreateIterator(SortedListPtr list) {
	if(list == NULL) {
		return NULL;
	}
	if(list->first == NULL) {
		return NULL;
	}
	SortedListIteratorPtr iter = (SortedListIteratorPtr) malloc(sizeof(struct SortedListIterator));