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
	TreeNode *nodeToInsert, *parentNode;
	if(NULL == tree->root){
		tree->root = createTreeNode(childData, NULL);
		return 1;
	}
	if(!tree->cmp(root->data,parentData)){
		parentNode = root;
		nodeToInsert = createTreeNode(childData, parentNode);
		insert(&root->children, 0, nodeToInsert);
		return 1;
	}
	parentNode = getTreeNode(root->children, parentData, tree->cmp);
	nodeToInsert = createTreeNode(childData, parentNode);
	insert(&parentNode->children, 0, nodeToInsert);
	return 1;
}
void* treeNext(Iterator *it){
	TreeNode *node;
	Iterator treeIterator = getIterator(it->list);
	treeIterator.position = it->position;
	node = treeIterator.next(&treeIterator);
	it->position++;
	return node->data;
}

Iterator getChildren(Tree* tree, void *parent) {
	TreeNode *temp,*root = (TreeNode*)tree->root;
	Iterator it;
	if(!tree->cmp(root->data,parent))
		temp = root;
	else 
		temp = getTreeNode(root->children, parent, tree->cmp);
	it = getIterator(&temp->children);
	it.next = &treeNext;
	return it;
}



// int isData_RootNode(TreeNode node,void *dataToFind,compare cmp){
// 	if(!cmp(node.data,dataToFind)){
// 		return 1;
// 	}
// 	return 0;
// }
