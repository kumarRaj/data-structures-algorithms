#include "mergeSort.h"
#include <stdlib.h>
void merge(void **leftArray,void **rightArray,int leftLength,int rightLength,compare cmpFun,void **resultArray){
	int cmpResult,i = 0,j = 0,k = 0;
	while(i < leftLength && j < rightLength){
		cmpResult = cmpFun(leftArray[i],rightArray[j]);
		if(cmpResult < 0)
			resultArray[k++] = leftArray[i++];
		else resultArray[k++] = rightArray[j++];
	}
	while(i < leftLength)
		resultArray[k++] = leftArray[i++];
	while(j < rightLength)
		resultArray[k++] = rightArray[j++];
}
void msort(void **base, size_t length, compare cmpFun){
	void **leftArray,**rightArray;
	int leftLength,rightLength,i,mid;;
	if(length < 2)	return;
	mid = (length + 1)/2;
	leftLength = mid;
	rightLength = length - mid;
	leftArray = malloc(sizeof(void*) * mid);
	rightArray = malloc(sizeof(void*) * (length-mid));
	for(i = 0;i < mid; i++)
		leftArray[i] = base[i];
	for(i = mid ; i < length; i++)
		rightArray[i-mid] = base[i];
	msort(leftArray, mid, cmpFun);
	msort(rightArray, length - mid, cmpFun);
	merge(leftArray, rightArray, leftLength, rightLength, cmpFun, base);
	
	free(leftArray);
	free(rightArray);
}