#include <stddef.h>

#ifndef _MERGESORT_
#define _MERGESORT_

#ifndef _COMPARE_
#define _COMPARE_
	typedef int (*compare)(void* first, void* second);
#endif
void msort(void **base, size_t length, compare cmpFun);
#endif
