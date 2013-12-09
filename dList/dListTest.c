#include "testUtils.h"
#include "dList.h"
#include <stdlib.h>
// #include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
void view_list_details(DoubleList *dlist){
	node *temp;
	
	for (temp = dlist->head; temp->next != NULL;temp = temp->next){
		// printf("prev%p--\tdata%d--\tnext%p\n",temp->previous,*(int*)temp->data,temp->next );
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
	ASSERT(dlist->head->previous == NULL);
}
void test_add_data_to_empty_list(){
	DoubleList* dlist = create();
	int number = 5;
	add(dlist, 0, &number);
	ASSERT(5 == *(int*)dlist->head->data);
	ASSERT(dlist->length == 1);
}
void test_add_data_to_list_where_index_more_than_length(){
	DoubleList* dlist = create();
	int number = 5;
	add(dlist, 0, &number);
	ASSERT(0 == add(dlist, 5, &number));
	ASSERT(5 == *(int*)dlist->head->data);
	ASSERT(dlist->length == 1);
}
void test_add_multiple_data_to_end_of_list(){
	DoubleList* dlist = create();
	int number1 = 5,number2 = 9,number3 = 65;
	node *second,*third;
	add(dlist, 0, &number1);
	add(dlist, 1, &number2);
	add(dlist, 2, &number3);
	second = dlist->head->next;
	third = second->next;
	ASSERT(5 == *(int*)dlist->head->data);
	ASSERT(9 == *(int*)second->data);
	ASSERT(65 == *(int*)third->data);
	ASSERT(dlist->length == 3);
	ASSERT(dlist->head == second->previous);
}
// void test_add_data_in_between_list(){
// 	DoubleList* dlist = create();
// 	int number0 = 5,number2 = 9,number3 = 65,number1 = 17,i;
// 	node *temp,*second,*third;
// 	add(dlist, 0, &number0);
// 	add(dlist, 1, &number2);
// 	add(dlist, 2, &number3);
// 	add(dlist, 1, &number1);
// 	temp = dlist->head;
// 	while(i <= 1 && temp->next != NULL){
// 		temp = temp->next;
// 	}
// 	second = temp->next;
// 	third = second->next;
// 	ASSERT(17 == *(int*)temp->data);
// 	ASSERT(9 == *(int*)second->data);
// 	ASSERT(65 == *(int*)third->data);
// }
