#include "./include/list_isort.h"

typedef struct {
        void* data;
        int priority;
} Queue_element;

typedef DoubleList PQueue;

PQueue* create_queue();
int enqueue(PQueue* queue, Queue_element* element,compare fun);
int dequeue(PQueue* queue);
void dispose_queue(PQueue* queue);