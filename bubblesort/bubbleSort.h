#include <stdlib.h>
#ifndef _COMPARE_
#define _COMPARE_
typedef int (*compare)(void* first, void* second);
#endif
void bubbleSort(void** base, size_t numberOfElements, compare comp);