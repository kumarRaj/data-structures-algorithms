#include "mergeSort.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void merge(void **leftArray,void **rightArray,int length,compare cmpFun,void **resultArray){
	int cmpResult,i = 0,j = 0,k = 0;
	while(i < length && j < length){
		cmpResult = cmpFun(leftArray[i],rightArray[j]);
		if(cmpResult < 0)
			resultArray[k++] = leftArray[i++];
		else resultArray[k++] = rightArray[j++];
	}
	while(i < length)
		resultArray[k++] = leftArray[i++];
	while(j < length)
		resultArray[k++] = rightArray[j++];
}
int j = 0;
void msort(void **base, size_t length, compare cmpFun){
	int i;
	int mid;
	void **leftArray;
	void **rightArray;
	if(length < 2)
		return;
	mid = (length + 1)/2;
	leftArray = malloc(sizeof(void*) * mid);
	rightArray = malloc(sizeof(void*) * (mid));
	for(i = 0;i < mid; i++){
		leftArray[i] = base[i];
	}
	for(i = mid ; i < length ; i++){
		rightArray[i-mid] = base[i];
	}
	msort(leftArray, mid, cmpFun);
	msort(rightArray, length - mid, cmpFun);
	merge(leftArray, rightArray, mid, cmpFun, base);
	
	free(leftArray);
	free(rightArray);
}
