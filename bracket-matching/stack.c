#include "./include/stack.h"
#include <stdlib.h>
void* getElement(Stack *stack){
	return (stack->base + ((stack->top) * stack->elementSize));
}
Stack* create(int elementSize,int length){
	Stack *stack;
	stack = malloc(sizeof(Stack));
	stack->base = calloc(length, elementSize);
	stack->length = length;
	stack->elementSize = elementSize;
	stack->top = -1;
	return stack;
};
bool push(Stack *stack,void* element){
	if(isFull(stack)) return false;
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
void dispose(Stack *stack){
	free(stack->base);
	free(stack);
}