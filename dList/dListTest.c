#include "testUtils.h"
#include "dList.h"
#include <stdlib.h>
#include <stdio.h>
// #include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
void view_list_details(DoubleList *dlist){
	node *temp;
	printf("\n\n\n");
	for (temp = dlist->head; temp->next != NULL;temp = temp->next){
		printf("myself%p\n",temp );
		printf("prev%p--\tdata%d--\tnext%p\n",temp->previous,*(int*)temp->data,temp->next );
	}
}

void test_create_node(){
	node expected = {NULL,NULL,NULL};
	node *actual = createNode(NULL,NULL);
	ASSERT(expected.next == actual->next);
	ASSERT(expected.previous == actual->previous);
}
void test_create_double_list(){
	DoubleList* dlist = create();
	ASSERT(dlist->length == 0); 
	// ASSERT(dlist->head->previous == NULL);
}
void test_add_data_to_empty_list(){
	DoubleList* dlist = create();
	int number = 5;
	insert(dlist, 0, &number);
	ASSERT(5 == *(int*)dlist->head->data);
	ASSERT(dlist->length == 1);
}
void test_add_data_to_list_where_index_more_than_length(){
	DoubleList* dlist = create();
	int number = 5;
	insert(dlist, 0, &number);
	ASSERT(0 == insert(dlist, 5, &number));
	ASSERT(5 == *(int*)dlist->head->data);
	ASSERT(dlist->length == 1);
}
void test_add_multiple_data_to_end_of_list(){
	DoubleList* dlist = create();
	int number1 = 5,number2 = 9,number3 = 65;
	node *second,*third;
	insert(dlist, 0, &number1);
	insert(dlist, 1, &number2);
	insert(dlist, 2, &number3);
	second = dlist->head->next;
	third = second->next;
	ASSERT(5 == *(int*)dlist->head->data);
	ASSERT(9 == *(int*)second->data);
	ASSERT(65 == *(int*)third->data);
	ASSERT(dlist->length == 3);
	ASSERT(dlist->head == second->previous);
}
void test_add_data_in_between_list(){
	DoubleList* dlist = create();
	int number0 = 5,number2 = 9,number3 = 65,number1 = 17,i;
	node *second,*third,*fourth;
	insert(dlist, 0, &number0);
	insert(dlist, 1, &number2);
	insert(dlist, 2, &number3);
	insert(dlist, 1, &number1);
	second = dlist->head->next;
	third = second->next;
	fourth = third->next;
	ASSERT(5 == *(int*)dlist->head->data);
	ASSERT(17 == *(int*)second->data);
	ASSERT(9 == *(int*)third->data);
	ASSERT(65 == *(int*)fourth->data);
	
}
