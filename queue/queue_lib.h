typedef char String[256];
typedef struct{
	void **base;
	int length;
	int rear;
} Queue;
Queue* create(int length);
int enqueue(Queue *queue,void *element);
void** getElement(Queue *queue,int index);
void* dequeue(Queue *queue);
int isEmpty(Queue *queue);
int isFull(Queue *queue);
void dispose(Queue *queue);