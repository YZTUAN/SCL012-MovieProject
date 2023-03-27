
#ifndef SORTED_LIST_H
#define SORTED_LIST_H
/*
 * sorted-list.h
 */

#include <stdlib.h>
/*
 * When your sorted list is used to store objects of some type, since the
 * type is opaque to you, you will need a comparator function to order
 * the objects in your sorted list.
 *
 * You can expect a comparator function to return -1 if the 1st object is
 * smaller, 0 if the two objects are equal, and 1 if the 2nd object is
 * smaller.
 *
 * Note that you are not expected to implement any comparator or destruct
 * functions.  You will be given a comparator function and a destruct
 * function when a new sorted list is created.
 */

typedef int (*CompareFuncT)( void *, void * );
typedef void (*DestructFuncT)( void * );


typedef struct node {
	void * data;
	int numPointers;
	struct node *next;
} Node;
/*
 * Sorted list type.  You need to fill in the type as part of your implementation.
 */
struct SortedList
{
Node *first;
CompareFuncT compare;
DestructFuncT destroy;
};
typedef struct SortedList* SortedListPtr;


/*
 * Iterator type for user to "walk" through the list item by item, from
 * beginning to end.  You need to fill in the type as part of your implementation.
 */
struct SortedListIterator
{
Node* SLNode;
DestructFuncT destroy;
};
typedef struct SortedListIterator* SortedListIteratorPtr;




/*
 * SLCreate creates a new, empty sorted list.  The caller must provide
 * a comparator function that can be used to order objects that will be
 * kept in the list, and a destruct function that gets rid of the objects
 * once they are no longer in the list or referred to in an iterator.
 * 
 * If the function succeeds, it returns a (non-NULL) SortedListT object,
 * otherwise, it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df);