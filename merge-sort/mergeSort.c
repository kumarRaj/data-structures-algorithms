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
		resultArray[k++] = leftArray[i++];
}
int j = 0;
void msort(void **base, size_t length, compare cmpFun){
	int i;
	int mid = (length + 1)/2;
	void **leftArray = malloc(sizeof(void*) * mid);
	void **rightArray = malloc(sizeof(void*) * mid);
	for(i = 0;i < mid;++i){
		leftArray[i] = base[i];
		rightArray[i] = base[i + mid];
	}
	// printf("%d\n",length);
	// j++;
	// if(j == 8)
	// 	exit(1);
	if(length != 1){
		msort(leftArray, mid, cmpFun);
		msort(rightArray, length, cmpFun);
		merge(leftArray, rightArray, mid, cmpFun, base);
	}
	else return;
	free(leftArray);
	free(rightArray);
}

void mergeSort(void **base, size_t numberOfElements, compare cmpFun){
	// sort(base,0,numberOfElements);
}
