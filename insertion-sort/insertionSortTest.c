#include "testUtils.h"
#include "insertionSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int compareAccounts(void* first, void* second) {
	Account* firstAccount = (Account*)first;
	Account* secondAccount = (Account*)second;
	return firstAccount->accountNumber - secondAccount->accountNumber;
}

int compareInt (void* first, void* second){
        return (*(int*)first - *(int*)second);
}

int compareDouble(void* first, void* second){
        return (*(double*)first - *(double*)second);
}

int compareChar(void* first, void* second){
        return (*(char*)first - *(char*)second);
}


void test_should_sort_data_(){
	Account account[] = {{"ram",500,1},{"sham",200,3}};;
	isort(account, 2, sizeof(Account), compareAccounts);
	ASSERT(account[0].accountNumber == 200);
	ASSERT(account[1].accountNumber == 500);			
}
 
void test_should_sort_int_data(){
	int data[5] = {25,24,23,22,21};
    int expected[5] = {21,22,23,24,25};
    isort(data, 5, sizeof(int), compareInt);
    ASSERT(data[0] == 21);
    ASSERT(data[4] == 25);
}

void test_should_sort_double_data(){
	double data[5] = {15,14,13,12,11};
    double expected[5] = {11,12,13,14,15};
    isort(data, 5, sizeof(double), compareDouble);
    ASSERT(data[0] == 11);
    ASSERT(data[4] == 15);
}

void test_should_sort_char_data(){
	char data[5] = {'z','v','c','o','a'};
    isort(data, 5, sizeof(char), compareChar);
    ASSERT(data[0]=='a');
    ASSERT(data[4]=='z');
}
