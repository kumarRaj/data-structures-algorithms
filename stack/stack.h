typedef struct {
        void** elements;
        int top;
        int length;
} Stack;

typedef char String_256[256];
Stack *create(int length);
int push(Stack *stack,void *element);
void** getElement(Stack *stack,int top);
void *pop(Stack *stack);
void *peek(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);