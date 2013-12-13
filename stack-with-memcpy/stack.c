#include "stack.h"
#include <stdlib.h>
void* getElement(Stack *stack){
	return (stack->base + ((stack->top) * stack->elementSize));
}
Stack* create(int elementSize,int length){
	Stack *stack = calloc(sizeof(Stack),1);
	stack->base = calloc(length, elementSize);
	stack->length = length;
	stack->elementSize = elementSize;
	stack->top = -1;
	return stack;
};
bool push(Stack *stack,void* element){
	void *temp;
	if(isFull(stack)){
		temp = realloc(stack->base,(stack->length * stack->elementSize));
		if(!temp)
			return false;
		stack->base = temp;
		stack->length = stack->length * 2;
	} 
	stack->top++;
	memcpy(getElement(stack), element, stack->elementSize);
	return true;
}
void* pop(Stack *stack){
	void* topElement;
	if(isEmpty(stack)) return NULL;
	topElement = getElement(stack);
	stack->top--;
	return topElement;
}
void* peek(Stack *stack){
	if(isEmpty(stack)) return NULL;
	return getElement(stack);
}
bool isEmpty(Stack *stack){
	return (stack->top == -1);
}
bool isFull(Stack *stack){
	return (stack->length == (stack->top + 1));
}
