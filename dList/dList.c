#include <stdlib.h>
#include "dList.h"

node* createNode(void *prevAddress, void *nextAddress){
	node *element = malloc(sizeof(node));
	element->previous = prevAddress;
	element->next = nextAddress;
	return element;
}
DoubleList* create(){
	DoubleList *dList = malloc(sizeof(DoubleList));
	dList->head = NULL;
	dList->length = 0;
	return dList;
}
int insert(DoubleList *dList, int index, void *element){
	int i;
	node *temp,*previousNode,*nextnode,*newNode;
	if(index > dList->length)
		return 0;
	temp = dList->head;
	for (i = 0; i < index ; ++i){
		if(temp->next != NULL)
			temp = temp->next;
	}
	if(i == 0 && dList->length == 0){
		newNode = createNode(NULL, NULL);
		dList->head = newNode;
		newNode->data = element;
		dList->length++;
		return 1;
	}
	if(i == 0){
		newNode = createNode(NULL, dList->head);
		newNode->data = element;
		dList->head->previous = newNode;
		dList->head = newNode;
		return 1;
	}
	if(i == dList->length){
		newNode = createNode(temp, NULL);
		temp->next = newNode;
		newNode->data = element;
		dList->length++;
		return 1;
	}
	newNode = createNode(temp->previous, temp);
	temp->previous->next = newNode;
	newNode->data = element;
	dList->length++;
	return 1;
}
int delete(DoubleList *dList, int index){
	int i;
	node *temp,*previousNode,*nextnode,*newNode;
	if(index > dList->length)
		return 0;
	temp = dList->head;
	for (i = 0; i < index ; ++i){
		if(temp->next != NULL)
			temp = temp->next;
	}
	if(i == 0 && dList->length == 1){
		dList->head = NULL;
		free(temp);
		dList->length--;
		return 1;
	}
	if(i == 0){
		dList->head = temp->next;
		free(temp);
		dList->length--;
		return 1;
	}
	if(i == dList->length - 1){
		temp->previous->next = NULL;
		free(temp);
		dList->length--;
		return 1;
	}
	temp->previous->next = temp->next;
	temp->next->previous = temp->previous;
	free(temp);
	dList->length--;
	return 1;
}