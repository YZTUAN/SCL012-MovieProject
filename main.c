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
	SortedListIteratorPtr SLIter;
	SortedListIteratorPtr SLIter1;


	char *a = "aello";
	char *b = "bello";
	char *c = "cello";
	char *d = "dello";
	char *e = "eello";
	char *f = "fello";
	char *g = "gello";
	char *h = "hello";
	char *i = "iello";
	char *j = "jello";
	char *k = "kello";
	char *l = "lello";


	SL = SLCreate(compareStrings,destroyBasicTypeNoAlloc);
	SLInsert(SL,a);
	SLInsert(SL,b);
	SLInsert(SL,c);
	SLInsert(SL,d);
	SLInsert(SL,e);
	SLInsert(SL,f);
	SLInsert(SL,g);
	SLInsert(SL,h);
	SLInsert(SL,i);
	SLInsert(SL,j);
	SLInsert(SL,k);
	SLInsert(SL,l);
	SLInsert(SL,d);

	SLIter = SLCreateIterator(SL);

	printf("First node : %s\n",((char *)SLGetItem(SLIter)));
	printf("Second node : %s\n",((char *)SLNextItem(SLIter)));
	printf("Third node : %s\n",((char *)SLNextItem(SLIter)));
	printf("Fourth node : %s\n",((char *)SLNextItem(SLIter)));
	printf("Fifth node : %s\n",((char *)SLNextItem(SLIter)));
	printf("Sixth node : %s\n",((char *)SLNextItem(SLIter)));
	printf("Seventh node : %s\n",((char *)SLNextItem(SLIter)));
	printf("Eighth node : %s\n",((char *)SLNextItem(SLIter)));
	printf("Ninth node : %s\n",((char *)SLNextItem(SLIter)));
	printf("Tenth node : %s\n",((char *)SLNextItem(SLIter)));
	SLRemove(SL, j);
	printf("Eleventh node : %s\n",((char *)SLNextItem(SLIter)));
	printf("Twelfth node : %s\n",((char *)SLNextItem(SLIter)));
	SLIter1 = SLCreateIterator(SL);
	printf("First node : %s\n",((char *)SLGetItem(SLIter1)));
	SLRemove(SL, d);
	printf("Second node : %s\n",((char *)SLNextItem(SLIter1)));
	printf("Third node : %s\n",((char *)SLNextItem(SLIter1)));
	printf("Fourth node : %s\n",((char *)SLNextItem(SLIter1)));
	printf("Fifth node : %s\n",((char *)SLNextItem(SLIter1)));
	printf("Sixth node : %s\n",((char *)SLNextItem(SLIter1)));
	printf("Seventh node : %s\n",((char *)SLNextItem(SLIter1)));
	printf("Eighth node : %s\n",((char *)SLNextItem(SLIter1)));
	printf("Ninth node : %s\n",((char *)SLNextItem(SLIter1)));
	printf("Tenth node : %s\n",((char *)S