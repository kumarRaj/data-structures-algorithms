#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
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