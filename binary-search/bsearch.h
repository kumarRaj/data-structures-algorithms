#include <stdlib.h>

typedef int (*compare)(const void*,const void*);

void* binarySearch (void* key,void* base,
               size_t numberOfElements, size_t size,compare cmpfunc
               );