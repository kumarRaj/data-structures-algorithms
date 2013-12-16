#include "bsearch.h"
void* binarySearch(void *key,void *base,
 size_t numberOfElements, size_t size, compare cmpfunc){
	int mid = numberOfElements/2;
	int cmpResult = cmpfunc(key,base+(mid*size));
	if(0 == cmpResult)
		return (void*)(base + (mid*size));
	if(0 == mid)
		return NULL;
	if(cmpResult > 0)
		bsearch(key, (base + (mid*size)), numberOfElements/2, size, cmpfunc);
	if(cmpResult < 0)
		bsearch(key, base , mid, size, cmpfunc);
}
