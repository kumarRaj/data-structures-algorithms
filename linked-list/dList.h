#include "include/iterator.h"

#ifndef _DOUBLELIST_
#define _DOUBLELIST_

typedef struct type{
	void *data;
	struct type *next,*previous;
} node;


typedef struct{
	int length;
	node *head,*tail;
} DoubleList;


typedef int (*compare)(void *elementToCompare,void *element);

DoubleList dList_create();
int dList_insert(DoubleList* dList,int index,void *element);
int dList_delete(DoubleList* dList,int index);
void dList_dispose(DoubleList dList);
void* dList_getData(DoubleList dList,void *searchElement,compare cmp);
void dList_sort(DoubleList dList, compare cmpFunc);
Iterator dList_getIterator(DoubleList *dList);
#endif