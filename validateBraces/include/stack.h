#include <stdbool.h>
#include <string.h>
typedef	struct{
	void *base;
	int elementSize;
	int length;
	int top;
} Stack;

typedef char String[256]; 

Stack* create(int elementSize,int length);
bool push(Stack *stack,void* element);
void* pop(Stack *stack);
void* peek(Stack *stack);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
void dispose(Stack *stack);