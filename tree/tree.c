#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

TreeNode* getTreeNode(DoubleList list,void *dataToFind,compare cmp){
	Iterator it = getIterator(&list);
	TreeNode *tn;
	while(it.hasNext(&it)){
		tn = (TreeNode*)it.next(&it);
		if(!cmp(tn->data,dataToFind))
			return tn;
		if(tn->children.head)
			getTreeNode(tn->children, dataToFind, cmp);
	}
	return NULL;
}
TreeNode* createTreeNode(void *data,TreeNode *parent){
	TreeNode *treeNode = malloc(sizeof(TreeNode));
	treeNode->data = data;
	treeNode->parent = parent;
	treeNode->children = create();
	return treeNode;
}
Tree createTree(compare cmp){
	Tree tree = {cmp,NULL};
	return tree;
}
int insertToTree(Tree* tree, void* parentData, void* childData) {
	TreeNode *root = (TreeNode*)tree->root;
	TreeNode *nodeToInsert;
	if(NULL == tree->root){
		tree->root = createTreeNode(childData, NULL);
		return 1;
	}
	if(!tree->cmp(root->data,parentData)){
		nodeToInsert = createTreeNode(childData, parentData);
		insert(&root->children, 0, nodeToInsert);
		return 1;
	}
	return 1;
}
void* treeNext(Iterator *it){
	TreeNode *node;// = it->next(it);
	Iterator treeIterator = getIterator(it->list);
	// printf("%d\n", it->position);
	// it->next(it);
	treeIterator.position = it->position;
	it->position++;
	node = treeIterator.next(&treeIterator);
	return node->data;
}

Iterator getChildren(Tree* tree, void *parent) {
	TreeNode *temp,*root = (TreeNode*)tree->root;
	// DoubleList dataList = create();
	Iterator it = getIterator(&root->children);
	it.next = &treeNext;
	// while(it.hasNext(&it)){
		// temp = (TreeNode*)it.next(&it);
		// insert(&dataList, it.position - 1, temp->data);
	// }
	return it;//(&dataList);
}
// TreeNode* getTreeNode(Tree *tree,void *parentData){
// 	TreeNode* foundNode;
// 	foundNode = tree->root;
// 	if(foundNode->data == parentData){
// 		return foundNode;
// 	}

// 	return NULL;
// }
	// TreeNode* parentNode = search(tree, parent);
	// if (parentNode == NULL) {
	// 	return something;
	// };

// 	listIterator = iterator(parentNode->children);	
// 	iterator.nodes = listIterator;
// }

// void* nextItem(Iterator *it) {
// 	DoubleList* list = (DoubleList*)it->list;
// 	return next(it); 
// }

