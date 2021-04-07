#include	<string.h>
#include	"sorted-list.h"
#include	<stdio.h>

typedef struct airplaneT {
	char *flight;
	int departHr;
	int departMin;
} Airplane;

int comparePlanes(void *p1, void *p2) {
	Airplane *a = (Airplane *)p1;
	Airplane *b = (Airplane *)p2;
	int timeA = (a->departHr)*60 + (a->departMin);

	int timeB = (b->departHr)*60 + (b->departMin);

	return (timeA - timeB);
}

int compareInts(void *p1, void *p2)
{
	int i1 = *(int*)p1;
	int i2 = *(int*)p2;

	return i1 - i2;
}

int compareDoubles(void *p1, void *p2)
{
	double d1 = *(double*)p1;
	double d2 = *(double*)p2;

	return (d1 < d2) ? -1 : ((d1 > d2) ? 1 : 0);
}

int compareStrings(void *p1, void *p2)
{
	char *s1 = p1;
	char *s2 = p2;

	return strcmp(s1, s2);
}

//Destructor functions
void destroyBasicTypeAlloc(void *p){
//	//For pointers to basic data types (int*,char*,double*,...)
//		//Use for allocated memory (malloc,calloc,etc.)
	free(p);
}
//
void destroyBasicTypeNoAlloc(void *p) {
//	//For pointers to basic data types (int*,char*,double*,...)
//					//Use for memory that has not been allocated (e.g., "int x = 5;SLInsert(mylist,&x);SLRemove(mylist,&x);")
	return;
}
//
void testWithInts() {
	SortedListPtr SL;
	SortedListIteratorPtr SLIter;

	int n = 0;

	int a = 10+2*n++;
	int b = 10+2*n++;
	int c = 10+2*n++;
	int d = 10+2*n++;
	int e = 10+2*n++;
	int f = 10+2*n++;
	int g = 10+2*n++;
	int h = 10+2*n++;
	int i = 10+2*n++;
	int j = 10+2*n++;
	int k = 10+2*n++;
	int l = 10+2*n++;

	SL = SLCreate(compareInts,destroyBasicTypeNoAlloc);
	SLInsert(SL,&a);
	SLInsert(SL,&b);
	SLInsert(SL,&c);
	SLInsert(SL,&d);
	SLInsert(SL,&e);
	SLInsert(SL,&f);
	SLInsert(SL,&g);
	SLInsert(SL,&h);
	SLInsert(SL,&i);
	SLInsert(SL,&j);
	SLInsert(SL,&k);
	SLInsert(SL,&l);
	SLInsert(SL,&d);

	SLIter = SLCreateIterator(SL);

	printf("First node : %d\n",(SLGetItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));
	printf("Second node : %d\n",(SLNextItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));
	printf("Third node : %d\n",(SLNextItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));
	printf("Fourth node : %d\n",(SLNextItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));
	printf("Fifth node : %d\n",(SLNextItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));
	printf("Sixth node : %d\n",(SLNextItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));
	printf("Seventh node : %d\n",(SLNextItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));
	printf("Eighth node : %d\n",(SLNextItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));
	printf("Ninth node : %d\n",(SLNextItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));
	printf("Tenth node : %d\n",(SLNextItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));
	printf("Eleventh node : %d\n",(SLNextItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));
	printf("Twelfth node : %d\n",(SLNextItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));
	printf("Twelfth node : %d\n",(SLNextItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));
	printf("Thirteenth node : %d\n",(SLNextItem(SLIter) == NULL?0:*((int *)SLGetItem(SLIter))));

	SLDestroyIterator(SLIter);
	SLDestroy(SL);

}

//
void testWithStrings1() {
	SortedListPtr SL;
	SortedL