typedef struct type{
	void *data;
	struct type *next,*previous;
} Node;
typedef struct{
	int length;
	Node *head,*tail;
} DoubleList;

DoubleList* create();
int insert(DoubleList* dList,int index,void *element);
int delete(DoubleList* dList,int index);