#include "stack.h"

int push(Stack* start, void* data){
	insert(start, start->length, data);
	return 1;
}

void pop(Stack* start){
	delete(start, start->length-1);
}
