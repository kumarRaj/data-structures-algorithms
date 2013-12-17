#include "list_isort.h"
#include <stdlib.h>
void sort(DoubleList* list, compare fun){
	node *temp,*nodeToCompare,*currentNode;
	void *data;
	int change = 0;
	if(list->head == NULL)
		return;
	for (nodeToCompare = list->head->next; nodeToCompare != NULL; nodeToCompare = nodeToCompare->next){
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
