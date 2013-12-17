#include "priorityQ.h"
PQueue* create_queue(){
	return create();
}
int enqueue(PQueue *queue, Queue_element *element, compare fun){
	insert(queue, 0, element);
	sort(queue, fun);
	return 1;
}

int dequeue(PQueue *queue){
	return delete(queue, 0);
}