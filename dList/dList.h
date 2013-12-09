typedef struct{
	void *data;
	void *next,*previous;
} node;
typedef struct{
	int length;
	node *head;
} DoubleList;

DoubleList* create();
node* createNode(void* prevAddress,void* nextAddress);
int add(DoubleList* dList,int index,void *element);
int remove(DoubleList* dList,int index);
int findIndex(DoubleList* dList,void *element);