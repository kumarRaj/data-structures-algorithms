typedef struct {
	void* nodes;
} TreeIterator;

void* next(TreeIterator* it);

int hasNext(TreeIterator* it);