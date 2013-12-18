typedef struct{
        void **base;
        int length;
        int front;
        int rear;
} Queue;
Queue create(int length);
int enqueue(Queue *queue,void *element);
void* dequeue(Queue *queue);
void dispose(Queue queue);