#include "queue_lib.h"
#include <string.h>
#include <stdlib.h>

void** getAddress(Queue *queue,int index){
        return queue->base+(index);
}
Queue create(int length){
    Queue queue = {malloc(sizeof(void *) * length),length,-1,-1};// = malloc(sizeof(Queue));
    return queue;
}
void dispose(Queue queue){
    free(queue.base);
}
int enqueue(Queue *queue, void *elementAddress){
    void **address;
    int rear;
    rear = (queue->rear + 1)%queue->length;
    if(rear == queue->front)
            return 0;
    queue->rear = rear;
    address = getAddress(queue,queue->rear);
    *address = elementAddress;
    return 1;
}
void* dequeue(Queue *queue){
    int i;
    if(queue->front == queue->rear)
            return NULL;
    queue->front = (queue->front + 1) % queue->length;
    return *getAddress(queue,queue->front);
}