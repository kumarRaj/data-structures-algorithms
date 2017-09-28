#include "testUtils.h"
#include "mergeSort.h"
#include <stdlib.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compareArray(void **ar1,void **ar2,int length){
	int i;
	for(i = 0;i < length;i++)
		if(ar1[i] != ar2[i]) 	return 0;
	return 1;
}
int areValuesEqual(void* value1,void* value2){
	return *(int*)value1 - *(int*)value2;
}
typedef char string[20];

typedef struct {
    string name;
    int accountNumber;
    float balance;
} Account;

int compareAccounts(void* first, void* second) {
    Account* firstAccount = (Account*)first;
    Account* secondAccount = (Account*)second;
    return firstAccount->accountNumber - secondAccount->accountNumber;
}
int compareChar(void* first, void* second){
    return (*(char*)first - *(char*)second);
}

void test_sort_array_for_even_number_of_elements(){
	int a[] = {3,7,12,2,5,8,6,9};
	void *addressA[8];int i;
	void *addressExpectedresult[] = {&a[3],&a[0],&a[4],&a[6],&a[1],&a[5],&a[7],&a[2]};
	for(i = 0;i < 8;i++)
		addressA[i] = &a[i];
	msort(addressA, 8, areValuesEqual);
	ASSERT(1 == compareArray(addressExpectedresult, addressA, 8));
}
void test_sort_array_for_odd_number_of_elements(){
	int a[] = {3,11,2,5,4};
	void *addressExpectedresult[] = {&a[2],&a[0],&a[4],&a[3],&a[1]};
	void *addressA[5];int i;
	for(i = 0;i < 5;i++)
		addressA[i] = &a[i];
	msort(addressA, 5, areValuesEqual);
	ASSERT(1 == compareArray(addressExpectedresult, addressA, 5));
}
void test_should_sort_data_of_2_structs(){
    Account account[] = {{"ram",500,1},{"sham",200,3}};
    void *AccountPtrs[] = {&account[0],&account[1]};
    msort(AccountPtrs, 2, compareAccounts);
    ASSERT((*(Account*)AccountPtrs[0]).accountNumber == 200);
    ASSERT((*(Account*)AccountPtrs[1]).accountNumber == 500);
}
void test_sorts_characters(){
    char chars[] = {'a','b','d','v','x'};
    void* ptrs[] = {&(chars[3]),&(chars[1]),&(chars[4]),&(chars[2]),&(chars)};
    void* expected[] = {&(chars[0]),&(chars[1]),&(chars[2]),&(chars[3]),&(chars[4])};
    msort(ptrs, 5, compareChar);
    ASSERT(compareArray(ptrs, expected, 5));
}
