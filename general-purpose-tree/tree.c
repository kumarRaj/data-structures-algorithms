#include "tree.h"
#include "internalTree.h"
#include <stdlib.h>
#include <stdio.h>
int i = 0;
TreeNode* getTreeNode(DoubleList list,void *dataToFind,compare cmp){
	Iterator it = dList_getIterator(&list);
	TreeNode *tn;
	while(it.hasNext(&it)){
		tn = (TreeNode*)it.next(&it);
		if(0 == cmp(tn->data,dataToFind)){
			return tn;
		}
		if(tn->children.head)
			return getTreeNode(tn->children, dataToFind, cmp);
	}
	return NULL;
}
TreeNode* createTreeNode(void *data,TreeNode *parent){
	TreeNode *treeNode = malloc(sizeof(TreeNode));
	treeNode->data = data;
	treeNode->parent = parent;
	treeNode->children = dList_create();
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
	if(0 == tree->cmp(root->data,parentData)){
		parentNode = root;
		nodeToInsert = createTreeNode(childData, parentNode);
		dList_insert(&root->children, 0, nodeToInsert);
		return 1;
	}
	parentNode = getTreeNode(root->children, parentData, tree->cmp);
	nodeToInsert = createTreeNode(childData, parentNode);
	dList_insert(&parentNode->children, 0, nodeToInsert);
	return 1;
}
void* treeNext(Iterator *it){
	TreeNode *node;
	Iterator treeIterator = dList_getIterator(it->list);
	treeIterator.position = it->position;
	node = treeIterator.next(&treeIterator);
	it->position = treeIterator.position;
	return node->data;
}

Iterator getChildren(Tree* tree, void *parent) {
	TreeNode *temp,*root = (TreeNode*)tree->root;
	Iterator it;
	if(0 == tree->cmp(root->data,parent))
		temp = root;
	else 
		temp = getTreeNode(root->children, parent, tree->cmp);
	it = dList_getIterator(&temp->children);
	it.next = &treeNext;
	return it;
}
int deleteFromTree(Tree *tree, void *data){
	TreeNode *root = (TreeNode*)tree->root;
	TreeNode *tn,*parent;
	Iterator it;int deleteIndex = 0;
	tn = getTreeNode(root->children, data, tree->cmp);
	if(NULL == tn) return 0;
	if(0 == tn->children.length){
		parent = tn->parent;
		it = dList_getIterator(&parent->children);
		while(it.hasNext(&it)){
			deleteIndex++;
			if(tree->cmp(data,it.next(&it)))
				break;
		}
		if(deleteIndex == 0 || deleteIndex == *((DoubleList*)(it.list))->length)
		dList_delete(&parent->children, it.position - 1);
		return 1;
	}
	return 0;
}
int searchInTree(Tree* tree, void* searchElement){
    TreeNode* root = (TreeNode*)(tree->root);
    if(0 == tree->cmp(searchElement,root->data)){
    	return 1;
    }
    if(getTreeNode(root->children,searchElement,tree->cmp))
        return 1;
    return 0;
}