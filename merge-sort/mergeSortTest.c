#include "testUtils.h"
#include "mergeSort.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compareArray(void **ar1,void **ar2,int length){
	int i;
	for(i = 0;i < length;i++){
		printf("%d\t%d\t\n", *(int*)ar1[i],*(int*)ar2[i]);
		// if(ar1[i] != ar2[i])
		// 	return 0;
	}
	return 1;
}
int areValuesEqual(void* value1,void* value2){
	return *(int*)value1 - *(int*)value2;
}
void test_join_2_arrays_in_sorted_order(){
	int a[] = {3,7};
	int b[] = {2,5};
	void *addressA[] = {&a[0],&a[1]};
	void *addressB[] = {&b[0],&b[1]};
	void *addressExpectedresult[] = {&b[0],&a[0],&b[1],&a[1]};
	void **result = malloc(sizeof(void*)*4);
	merge(addressA,addressB,2,areValuesEqual,result);
	ASSERT(1 == compareArray(addressExpectedresult, result, 1));
}
void test_sort_array(){
	int a[] = {3,7,12,2,5,8,6,9};
	void *addressExpectedresult[] = {&a[3],&a[0],&a[4],&a[6],&a[1],&a[5],&a[7],&a[2]};
	void *addressA[8];int i;
	for(i = 0;i < 8;i++)
		addressA[i] = &a[i];
	msort(addressA, 8, areValuesEqual);
	ASSERT(1 == compareArray(addressExpectedresult, addressA, 8));
}
