#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
const int INSERT_SUCCESSFUL = 1;
int compareInts(void *a,void *b){
	return *(int*)a - *(int*)b;
}
void test_insert_root_node(){
	Tree tree = createTree(compareInts);
	int data = 2;
	int result = insertToTree(&tree, NULL, &data);
	ASSERT(INSERT_SUCCESSFUL == result);
}
void test_insert_node_under_root_node(){
	Tree tree = createTree(compareInts);
	int data[] = {2,3,5};
	Iterator result;
	insertToTree(&tree, NULL, &data[0]);
	insertToTree(&tree, &data[0], &data[1]);
	insertToTree(&tree, &data[0], &data[2]);
	result = getChildren(&tree, &data);
	// printf("%d\n", result.hasNext(&result));
	ASSERT(5 == *(int*)result.next(&result));
	ASSERT(3 == *(int*)result.next(&result));
}
void test_insert_under_child_node(){
	Tree tree = createTree(compareInts);
	int data[] = {2,3,5};
	Iterator result;
	insertToTree(&tree, NULL, &data[0]);
	insertToTree(&tree, &data[0], &data[1]);
	insertToTree(&tree, &data[1], &data[2]);
	result = getChildren(&tree, &data[1]);
	ASSERT(5 == *(int*)result.next(&result));
}
void test_insert_under_second_child(){
	Tree tree = createTree(compareInts);
	int data0 = 2;
	int data1[] = {3,5};
	int data2 = 9;
	Iterator result;
	insertToTree(&tree, NULL, &data0);
	insertToTree(&tree, &data0, &data1[0]);
	insertToTree(&tree, &data0, &data1[1]);
	insertToTree(&tree, &data1[1], &data2);
	result = getChildren(&tree, &data1[1]);
	ASSERT(9 == *(int*)result.next(&result));
}
void test_insert_nodes_from_different_level(){
	Tree tree = createTree(compareInts);
	Iterator it;
	int data[7] = {10,12,30,4,45,5,50};
	ASSERT(insertToTree(&tree, NULL, &data[0]));
	ASSERT(insertToTree(&tree, &data[0], &data[1]));
	ASSERT(insertToTree(&tree, &data[1], &data[2]));
	ASSERT(insertToTree(&tree, &data[2], &data[3]));
	ASSERT(insertToTree(&tree, &data[3], &data[4]));
	ASSERT(insertToTree(&tree, &data[4], &data[5]));
}
void test_delete_node_under_root_node_from_tree(){
	Tree tree = createTree(compareInts);
	Iterator result;
	int data[2] = {10,23};
	ASSERT(insertToTree(&tree, NULL, &data));
	ASSERT(insertToTree(&tree, &data, &data[1]));
	ASSERT(deleteFromTree(&tree,&data[1]));
	result = getChildren(&tree, &data);
	ASSERT(0 == result.hasNext(&result));
}
void test_delete_root_node_from_tree(){
	Tree tree = createTree(compareInts);
	Iterator result;
	int data[2] = {10,23};
	ASSERT(insertToTree(&tree, NULL, &data));
}
void test_delete_nodes_from_different_level(){
	Tree tree = createTree(compareInts);
	Iterator result;
	int data[7] = {10,12,30,4,45,5,50};
	ASSERT(insertToTree(&tree, NULL, &data[0]));
	ASSERT(insertToTree(&tree, &data[0], &data[1]));
	ASSERT(insertToTree(&tree, &data[1], &data[2]));
	ASSERT(insertToTree(&tree, &data[2], &data[3]));
	ASSERT(insertToTree(&tree, &data[3], &data[4]));
	ASSERT(insertToTree(&tree, &data[4], &data[5]));
	ASSERT(deleteFromTree(&tree, &data[5]));
	result = getChildren(&tree, &data[4]);
	ASSERT(0 == result.hasNext(&result));
}
void test_search_element_in_the_tree(){
	Tree tree = createTree(compareInts);
	Iterator result;
	int data[7] = {10,12,30,4,45,5,50};
	ASSERT(insertToTree(&tree, NULL, &data[0]));
	ASSERT(insertToTree(&tree, &data[0], &data[1]));
	ASSERT(insertToTree(&tree, &data[1], &data[2]));
	ASSERT(insertToTree(&tree, &data[2], &data[3]));
	ASSERT(insertToTree(&tree, &data[3], &data[4]));
	ASSERT(insertToTree(&tree, &data[4], &data[5]));
	ASSERT(searchInTree(&tree,&data[4]));
	ASSERT(searchInTree(&tree,&data[2]));
	ASSERT(searchInTree(&tree,&data[1]));
}
void test_not_search_element_in_the_tree(){
	Tree tree = createTree(compareInts);
	Iterator result;
	int data[7] = {10,12,30,4,45,5,50};
	ASSERT(insertToTree(&tree, NULL, &data[0]));
	ASSERT(insertToTree(&tree, &data[0], &data[1]));
	ASSERT(insertToTree(&tree, &data[1], &data[2]));
	ASSERT(insertToTree(&tree, &data[2], &data[3]));
	ASSERT(insertToTree(&tree, &data[3], &data[4]));
	ASSERT(insertToTree(&tree, &data[4], &data[5]));
	ASSERT(searchInTree(&tree,&data[4]));
	ASSERT(searchInTree(&tree,&data[2]));
	ASSERT(0 == searchInTree(&tree,&data[7]));
}