#include "include/iterator.h"

#ifndef _ARRAYLIST_
#define _ARRAYLIST_
typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

ArrayList ArrayList_create(int capacity);
typedef int (*compare)(void* element1,void *element2);
typedef void ForEach(void* data);

int ArrayList_insert(ArrayList *list, int index, void* data);

int ArrayList_remove(ArrayList *list,int index);

int ArrayList_add(ArrayList *list,void *data);

void* ArrayList_get(ArrayList *list, int index);

int ArrayList_search(ArrayList *list, void *searchElement,compare cmpFun);

void ArrayList_iterate(ArrayList list, ForEach* forEach);

Iterator ArrayList_getIterator(ArrayList* list);

void ArrayList_dispose(ArrayList *list);
#endif