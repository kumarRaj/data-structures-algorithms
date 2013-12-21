#include "dList.h"

typedef struct {
	node* current;
	DoubleList* list;
} Iterator;

void* next(Iterator* it);

int hasNext(Iterator* it);