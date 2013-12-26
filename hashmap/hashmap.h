#include "./include/iterator.h"

#ifndef _COMPARE_
#define _COMPARE_
typedef int (*compare)(void* firstElement, void* secondElement);
typedef int (*hash)(void *key);
#endif	
typedef struct {
	void **bucket;
	hash hashFunc;
	compare cmp;
} HashMap;

HashMap createMap(hash hashFunc, compare compareKey);
int put(HashMap* map,const void* key,const void* value);
void* get(HashMap* map,const void* key);
int remove(HashMap* map, void* kay);
Iterator keys(HashMap* map);
