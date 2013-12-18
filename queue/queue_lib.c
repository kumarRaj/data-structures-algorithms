#include "queue_lib.h"
#include <stdlib.h>
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
int enqueue(Queue *queue, void *elementAddress){
	void **address;
	if(isFull(queue))
		return 0;
	address = getElement(queue,++queue->rear);
	*address = elementAddress;
	return 1;
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
int isEmpty(Queue *queue){
	return (queue->rear == -1);
}
int isFull(Queue *queue){
	return (queue->rear == queue->length - 1);
}