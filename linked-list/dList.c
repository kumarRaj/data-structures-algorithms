#include "dList.h"
#include <stdlib.h>
#include "include/iterator.h"
node* dList_createNode(void *prevAddress,void *data, void *nextAddress){
	node *element = malloc(sizeof(node));
	element->previous = prevAddress;
	element->data = data;
	element->next = nextAddress;
	return element;
}
DoubleList dList_create(){
	DoubleList dList = {0,NULL,NULL};
	return dList;
}
int dlist_insertAtFirst(DoubleList *dList,void *element){
	node *newNode = dList_createNode(NULL, element, dList->head);
    dList->head = newNode;
	if(dList->length != 0)	dList->head->previous = newNode;
    dList->length++;
	return 1;
}
int dList_insert(DoubleList *dList, int index, void *element){
    int i;
    node *temp,*newNode;
    if(index > dList->length)	return 0;
    if(index == 0) 	return dlist_insertAtFirst(dList,element);
    temp = dList->head;
    for (i = 0; i < index ; ++i)
        if(temp->next != NULL)	temp = temp->next;
    if(i == dList->length){
        newNode = dList_createNode(temp,element,NULL);
        temp->next = newNode;
    }
    else{
	    newNode = dList_createNode(temp->previous,element, temp);
	    temp->previous->next = newNode;
    }
    dList->length++;
    return 1;
}
void dList_deleteAtStart(DoubleList *dList,node *temp){
	if(dList->length != 1)
		dList->head = temp->next;
	else dList->head = NULL;
}
void dList_deleteInBetween(DoubleList *dList,node *temp,int position){
	if(position == dList->length - 1)
		temp->previous->next = NULL;
	else{
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
	}
}
int dList_delete(DoubleList *dList, int index){
	int position;
	node *temp;
	if(index > dList->length)
		return 0;
	temp = dList->head;
	for(position = 0; position < index; ++position){
		temp = temp->next;
	}
	if(index == 0){
		dList_deleteAtStart(dList,temp);
	}
	else dList_deleteInBetween(dList,temp,position);
	free(temp);
	dList->length--;
	return 1;
}

void dList_sort(DoubleList list, compare fun){
	node *temp,*nodeToCompare,*currentNode;
	void *data;
	int change = 0;
	if(list.head == NULL)
		return;
	for (nodeToCompare = list.head->next; nodeToCompare != NULL; nodeToCompare = nodeToCompare->next){
		data = nodeToCompare->data;
		change = 0;
		for(temp = nodeToCompare->previous;temp != NULL;temp = temp->previous){
			currentNode = temp;
			if(fun(data,temp->data) < 0){
				change++;
				temp->next->data = temp->data;
			}
			else break;
		}
		if(change)
			currentNode->data = data;
	}
}
int dList_hasNextForList(Iterator *it){
	DoubleList *dList;
	dList = (DoubleList*)it->list;
	if(NULL == it->position)
		return 0;
	return 1;
}
void* dList_nextForList(Iterator *it){
	DoubleList *dList;
	node *temp;void *result;
	if(0 == dList_hasNextForList(it)) return NULL;
	temp = it->position;
	result = temp->data;
	it->position = temp->next;
	return result;
}
Iterator dList_getIterator(DoubleList *dList){
	Iterator listIterator;
	listIterator.position = dList->head;
	listIterator.list = dList;
	listIterator.hasNext = &dList_hasNextForList;
	listIterator.next = &dList_nextForList;
	return listIterator;
}

void* dList_getData(DoubleList dList, void *searchElement, compare cmp){
	node *nodeToCompare;
	if(dList.head == NULL)
		return NULL;
	for (nodeToCompare = dList.head;nodeToCompare != NULL;nodeToCompare = nodeToCompare->next){
		if(cmp(searchElement,nodeToCompare->data))
			return nodeToCompare->data;
	}
	return NULL;
}
void dList_dispose(DoubleList dList){
	node *temp;
	if(dList.head == NULL)
		return;
	temp = dList.head;
	dList.head = temp->next;
	free(temp);
	dList_dispose(dList);
}