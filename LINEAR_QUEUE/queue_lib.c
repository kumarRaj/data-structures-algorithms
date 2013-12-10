#include "queue_lib.h"

void** getElement(Queue *queue,int index){
	return queue->base+(index);
}
Queue* create(int length){
	Queue *queue = malloc(sizeof(Queue));
	queue->base = malloc(sizeof(void *) * length);
	queue->length = length;
	queue->rear = -1;
	return queue;
}
void dispose(Queue *queue){
	free(queue->base);
	free(queue);
}
bool enqueue(Queue *queue, void *elementAddress){
	void **address;
	if(isFull(queue))
		return false;
	address = getElement(queue,++queue->rear);
	*address = elementAddress;
	return true;
}
void* dequeue(Queue *queue){
	int i;
	void *result;
	if(isEmpty(queue))
		return NULL;
	result = *getElement(queue,0);
	for(i = 1;i <= queue->rear;i++){
		*getElement(queue,(i - 1)) = *getElement(queue,i);	
	}
	queue->rear--;
	return result;
}
bool isEmpty(Queue *queue){
	return (queue->rear == -1);
}
bool isFull(Queue *queue){
	return (queue->rear == queue->length - 1);
}