#include "tree_iterator.h"
#include "include/iterator.h"
#include "include/dList.h"


#ifndef _COMPARE_
#define _COMPARE_
typedef int (*compare)(void* firstElement, void* secondElement);
#endif
typedef struct {
	compare cmp;
	void *root;
} Tree;

typedef struct tn{
	void* data;
	struct tn* parent;
	DoubleList children;
} TreeNode;

Tree createTree(compare cmp);
TreeNode* getTreeNode(DoubleList list,void *dataToFind,compare cmp);
int insertToTree(Tree* tree, void* parentData, void* data);
Iterator getChildren(Tree* tree, void* parentData);