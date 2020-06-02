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

int compareInts(void *p1, v