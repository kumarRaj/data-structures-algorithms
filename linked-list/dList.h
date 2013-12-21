#include "../Iterator/iterator.h"
typedef struct type{
	void *data;
	struct type *next,*previous;
} node;


typedef struct{
	int length;
	node *head,*tail;
} DoubleList;


typedef int (*compare)(void *elementToCompare,void *element);

DoubleList create();
int insert(DoubleList* dList,int index,void *element);
int delete(DoubleList* dList,int index);
void dispose(DoubleList dList);
void* getData(DoubleList dList,void *searchElement,compare cmp);
void sort(DoubleList dList, compare cmpFunc);
Iterator getIterator(DoubleList *dList);