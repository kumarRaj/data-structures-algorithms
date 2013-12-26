#include "include/dList.h"

typedef struct tn{
	void* data;
	struct tn* parent;
	DoubleList children;
} TreeNode;
