#include <stdlib.h>
#include "dList.h"

node* createNode(void *prevAddress,void *data, void *nextAddress){
	node *element = malloc(sizeof(node));
	element->previous = prevAddress;
	element->data = data;
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
		newNode = createNode(NULL,element, NULL);
		dList->head = newNode;
		dList->length++;
		return 1;
	}
	if(index == 0){
		newNode = createNode(NULL, element, dList->head);
		dList->head->previous = newNode;
		dList->head = newNode;
		dList->length++;
		return 1;
	}
	if(i == dList->length){
		newNode = createNode(temp,element,NULL);
		temp->next = newNode;
		dList->length++;
		return 1;
	}
	newNode = createNode(temp->previous,element, temp);
	temp->previous->next = newNode;
	dList->length++;
	return 1;
}
int delete(DoubleList *dList, int index){
	int i;
	node *temp,*previousNode,*nextnode,*newNode;
	if(index > dList->length)
		return 0;
	temp = dList->head;
	for (i = 0; i < index && i < dList->length ; ++i){
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
int findIndex(DoubleList *dList, void *element){
	int i,index = 0; node *temp = dList->head;
	for (i = 0; temp->next != NULL ; ++i){
		if(temp->data == element)
			break;
		temp = temp->next;
	}
	if(i != dList->length)
		return i;
	return -1;
}