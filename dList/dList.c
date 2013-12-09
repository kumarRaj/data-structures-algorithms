#include <stdlib.h>
#include "dList.h"

node* createNode(void *prevAddress, void *nextAddress){
	node *element = malloc(sizeof(node));
	element->previous = prevAddress;
	element->next = nextAddress;
	element->data = (int*)5;
	return element;
}
DoubleList* create(){
	DoubleList *dList = malloc(sizeof(DoubleList));
	dList->length = 0;
	dList->head = createNode(NULL, NULL);
	return dList;
}
int add(DoubleList *dList, int index, void *element){
	int i;
	node *temp,*nodeToAdd;
	if(index > dList->length)
		return 0;
	temp = dList->head;
	nodeToAdd = temp;
	for (i = 0; i <= index && temp->next != NULL; ++i,temp = temp->next){
		nodeToAdd = temp->next;
	}
	nodeToAdd->data = element;
	nodeToAdd->next = createNode(nodeToAdd, NULL);
	dList->length++;
	return 1;
}
