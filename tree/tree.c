#include "tree.h"
#include "../linked-list/dList.h"

Tree create(compare cmp){
	Tree tree = {cmp};
	return tree;
} 

typedef struct treeNode
{
	void* data;
	struct treeNode* parent;
	DoubleList* children;
} TreeNode;

int insert(Tree* tree, void* parentData, void* data) {

	return 1;
}

TreeIterator* getChildren(Tree* tree, void *parent) {
	ListIterator* listIterator;
	TreeIterator iterator;

	TreeNode* parentNode = search(tree, parent);
	if (parentNode == NULL) {
		return something;
	};

	listIterator = iterator(parentNode->children);	
	iterator.nodes = listIterator;
}

void* nextItem(Iterator *it) {
	DoubleList* list = (DoubleList*)it->list;
	return next(it); 
}

