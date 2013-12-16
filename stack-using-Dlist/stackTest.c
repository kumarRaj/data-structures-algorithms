#include "testUtils.h"
#include "stack.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Stack *start;
void setup(){
	start = create();
}

// void tearDown(){
// 	dispose(start);
// }

void test_to_create_Stack(){
	ASSERT(NULL == start->head);
	ASSERT(0 == start->length);
}

void test_1_to_push_element_into_stack(){
	int data1 = 1;
	int data2 = 2;
	push(start, &data1);
	ASSERT(1 == start->length);
	ASSERT(data1 == *(int*)(start->head->data));
	push(start, &data2);
	ASSERT(data2 == *(int*)(start->head->next->data));
}

void test_2_to_pop_element_into_stack(){
    int data1 = 1;
    int data2 = 2;
    push(start, &data1);
    push(start, &data2);
    ASSERT(data1 == *(int*)(start->head->data));
    ASSERT(data2 == *(int*)(start->head->next->data));
    pop(start);
    ASSERT(NULL == start->head->next);
    ASSERT(start->length == 1);
    pop(start);
    ASSERT(start->length == 0);
    ASSERT(NULL == start->head);
}

typedef struct{
	int accno,balance;
} Account;

void test_push_struct_into_stack(){
	Account data[2] = {{1,67},{2,45}};
    push(start, data);
    push(start, &data[1]);
    pop(start);
    ASSERT(NULL == start->head->next);
    ASSERT(1 == start->length);
    pop(start);
    ASSERT(0 == start->length);
    ASSERT(NULL == start->head);
}


// void test_3_to_know_whether_the_stack_is_Empty(){
// 	ASSERT(isEmpty(start));
// }
