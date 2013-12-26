#include "include/dList.h"

typedef struct hashNode {
	void* key;
	void* value;
	DoubleList elements;
}HashNode;

