#include <stddef.h>



#ifndef _COMPARE_
#define _COMPARE_
typedef int (*compare)(void* first, void* second);
#endif
void isort(void* base, size_t numberOfElements, size_t elementSize,compare comp);