#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef char String[256];
typedef struct{
        void **base;
        int length;
        int front;
        int rear;
} Queue;
Queue* create(int length);
bool enqueue(Queue *queue,void *element);
void** getElement(Queue *queue,int index);
void* dequeue(Queue *queue);
bool isEmpty(Queue *queue);
bool isFull(Queue *queue);
void dispose(Queue *queue);