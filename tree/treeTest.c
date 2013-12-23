#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
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
	Iterator result;//int result;
	insertToTree(&tree, NULL, &data[0]);
	insertToTree(&tree, &data[0], &data[1]);
	insertToTree(&tree, &data[0], &data[2]);
	result = getChildren(&tree, &data);
	ASSERT(5 == *(int*)result.next(&result));
	ASSERT(3 == *(int*)result.next(&result));
	// printf("%d\n", );
}
