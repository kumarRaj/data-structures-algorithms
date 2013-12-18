typedef struct type{
	void *data;
	struct type *next,*previous;
} node;
typedef struct{
	int length;
	node *head,*tail;
} DoubleList;

DoubleList* create();
node* createNode(void* prevAddress,void *data,void* nextAddress);
int insert(DoubleList* dList,int index,void *element);
int delete(DoubleList* dList,int index);
int findIndex(DoubleList* dList,void *element);
void dispose(DoubleList* dList);