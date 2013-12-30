#include <stddef.h>

#ifndef _MERGESORT_
#define _MERGESORT_

#ifndef _COMPARE_
#define _COMPARE_
typedef int (*compare)(void* first, void* second);
#endif
void msort(void **base, size_t length, compare cmpFun);
void sort(void **base, size_t startIndex,size_t endIndex);
void merge(void **leftArray,void **rightArray,int length,compare cmpFun,void **resultArray);
#endif
