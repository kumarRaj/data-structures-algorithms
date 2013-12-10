typedef struct type{
	void *data;
	struct type *next,*previous;
} node;
typedef struct{
	int length;
	node *head;
} DoubleList;

DoubleList* create();
node* createNode(void* prevAddress,void* nextAddress);
int insert(DoubleList* dList,int index,void *element);
int delete(DoubleList* dList,int index);
int findIndex(DoubleList* dList,void *element);