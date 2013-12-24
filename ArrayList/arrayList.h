typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

ArrayList create(int capacity);
typedef int (*compare)(void* element1,void *element2);

int insert(ArrayList *list, int index, void* data);

void* get(ArrayList *list, int index);

int search(ArrayList *list, void *searchElement,compare cmpFun);

void dispose(ArrayList *list);