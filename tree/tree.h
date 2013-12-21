#include "tree_iterator.h"

typedef int (*compare)(void* firstElement, void* secondElement);

typedef struct {
	compare cmp;
} Tree;

Tree create(compare cmp);

int insert(Tree* tree, void* parentData, void* data);

TreeIterator* getChildren(Tree* tree, void* parent);