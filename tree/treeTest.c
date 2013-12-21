#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_insert_root_node(){
	Tree tree = create();
	int data = 2;
	int result = insert(&tree, NULL, &data);
	const int INSERT_SUCCESSFUL = 1;
	ASSERT(INSERT_SUCCESSFUL == result);

	Iterator* it = getChildren(&tree, NULL);

	next(Iterator *it)
}
