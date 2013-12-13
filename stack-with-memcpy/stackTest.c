#include "testUtils.h"
#include "stack.h"
#include <string.h>
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

bool areStackEqual(Stack expected,Stack actual){
	expected.length = actual.length;
	expected.top = actual.top;
	memcmp(expected.base, actual.base, 20);
	return true;
}
void test_1_creation_of_stack(){
	Stack *stack = create(sizeof(int),5);
	int elements[5] = {0,0,0,0,0};
	Stack expected = {elements,sizeof(int),5,-1};
	ASSERT(areStackEqual(expected, *stack));
	free(stack->base);
	free(stack);
}
void test_2creation_of_stack_for_String(){
	Stack *stack = create(sizeof(String),3);
	String elements[3] = {"\0","\0","\0"};
	Stack expected = {elements,sizeof(int),3,-1};
	ASSERT(areStackEqual(expected, *stack));
	free(stack->base);
	free(stack);
}
void test_3push_on_empty_stack(){
	Stack *stack = create(sizeof(int),5);
	int _5 = 5;
	bool result = push(stack, &_5);
	ASSERT(result == true);
	ASSERT(stack->top == 0);
	ASSERT(5 == *(int*)(stack->base));
	free(stack->base);
	free(stack);
}
void test_4push_on_full_stack_doubles_size_of_stack(){
	int element = 51;
	int _9 = 9;
	Stack *stack = create(sizeof(int),4);
	bool result;
	push(stack, &element);
	push(stack, &element);
	push(stack, &element);
	push(stack, &element);
	result = push(stack, &_9);
	ASSERT(8 == stack->length);
	ASSERT(4 == stack->top);
	ASSERT(true == result);
	free(stack->base);
	free(stack);
}
void test_5push_string_on_empty_stack(){
	Stack *stack = create(6,3);
	String dubey = "dubey";
	bool result = push(stack, dubey);
	ASSERT(result == true);
	ASSERT(stack->top == 0);
	ASSERT(0 == strcmp(dubey,*(String*)(stack->base)));
	free(stack->base);
	free(stack);
}
void test_6pop_double_on_stack(){
	double elements[4] = {5,6,7,8};
	Stack stack = {elements,sizeof(double),4,3};
	double num = *(double*)pop(&stack);
	ASSERT(2 == stack.top);
	ASSERT(8 == num);
}
void test_7pop_string_from_stack(){
	String elements[4] = {"Ram","Shyam","Kaam"};
	Stack stack = {elements,sizeof(String),4,2};
	String result;
	strcpy(result,pop(&stack));
	ASSERT(1 == stack.top);
	ASSERT(0 == strcmp("Kaam",result));
}
void test_8pop_string_from_empty_stack_should_give_NULL(){
	String elements[4] = {};
	Stack stack = {elements,sizeof(String),4,-1};
	ASSERT(NULL == pop(&stack));
}
void test_9peek_in_stack_should_give_last_element_without_changing_top(){
	int elements[4] = {5,6,7,8};
	Stack stack = {elements,sizeof(int),4,3};
	int num = *(int*)peek(&stack);
	ASSERT(3 == stack.top);
	ASSERT(8 == num);	
}
void test_10peek_string_stack_when_empty_should_give_NULL(){
	String elements[4] = {};
	Stack stack = {elements,sizeof(String),4,-1};
	ASSERT(NULL == peek(&stack));
}
void test_11stack_isEmpty_should_give_true_for_empty_stack(){
	String elements[4] = {};
	Stack stack = {elements,sizeof(String),4,-1};
	ASSERT(isEmpty(&stack));	
}
void test_12stack_isEmpty_should_give_false_if_stack_is_not_empty(){
	String elements[4] = {2,4};
	Stack stack = {elements,sizeof(String),4,1};
	ASSERT(false == isEmpty(&stack));
}
void test_13stack_isFull_should_give_true_for_full_stack(){
	String elements[4] = {2,4,5,6};
	Stack stack = {elements,sizeof(String),4,3};
	ASSERT(isFull(&stack));	
}
void test_14stack_isFull_should_give_false_for_not_full_stack(){
	String elements[4] = {2,4};
	Stack stack = {elements,sizeof(String),4,1};
	ASSERT(false == isFull(&stack));	
}
