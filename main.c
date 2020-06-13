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

int compareSt