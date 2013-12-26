#include "include/iterator.h"
typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

ArrayList create(int capacity);
typedef int (*compare)(void* element1,void *element2);
typedef void ForEach(void* data);

int insert(ArrayList *list, int index, void* data);

int remove(ArrayList *list,int index);

int add(ArrayList *list,void *data);

void* get(ArrayList *list, int index);

int search(ArrayList *list, void *searchElement,compare cmpFun);

void iterate(ArrayList list, ForEach* forEach);

Iterator getIterator(ArrayList* list);

void dispose(ArrayList *list);