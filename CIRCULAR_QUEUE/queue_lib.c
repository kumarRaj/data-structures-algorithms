#include "queue_lib.h"
void** getElement(Queue *queue,int index){
	return queue->base+(index);
}
Queue* create(int length){
	Queue *queue = malloc(sizeof(Queue));
	queue->base = malloc(sizeof(void *) * length);
	queue->length = length;
	queue->rear = -1;
	queue->front = -1;
	return queue;
}
void dispose(Queue *queue){
	free(queue->base);
	free(queue);
}
bool enqueue(Queue *queue, void *elementAddress){
    void **address;
    int rear;
    rear = (queue->rear + 1)%queue->length;
    if(rear == queue->front)
    	return false;
    queue->rear = rear;
    address = getElement(queue,queue->rear);
    *address = elementAddress;
    return true;
}
void* dequeue(Queue *queue){
    int i;
    if(queue->front == queue->rear)
    	return NULL;
    queue->front = (queue->front + 1) % queue->length;
    return *getElement(queue,queue->front);
}