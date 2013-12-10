#include "testUtils.h"
#include "dList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
void view_list_details(DoubleList *dlist){
	node *temp;int i;
	printf("\n\n");
	temp = dlist->head;
	for (i = 0; i < dlist->length;i++){
		printf("%d--\t\n",*(int*)temp->data);
		temp = temp->next;
	}
}

void test_create_node(){
	node expected = {NULL,NULL,NULL};
	node *actual = createNode(NULL,NULL,NULL);
	ASSERT(expected.next == actual->next);
	ASSERT(expected.previous == actual->previous);
	ASSERT(expected.data == actual->data);
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
void test_add_data_in_beginning_of_list_with_values(){
	int number1 = 5,number2 = 9,number0 = 65;
	DoubleList* dlist = create();
	node *second,*third;
	insert(dlist, 0, &number1);
	insert(dlist, 1, &number2);
	insert(dlist, 0, &number0);
	ASSERT(65 == *(int*)dlist->head->data);
	ASSERT(5 == *(int*)dlist->head->next->data);

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
void test_delete_first_element_in_list_with_one_element(){
	DoubleList* dlist = create();
	int number1 = 5,number2 = 9,number3 = 65;
	node *second,*third;
	insert(dlist, 0, &number1);
	ASSERT(delete(dlist, 0));
	ASSERT(0 == dlist->length);
	ASSERT(NULL == dlist->head);
}
void test_delete_first_element(){
	DoubleList* dlist = create();
	int number1 = 5,number2 = 9,number3 = 65;
	node *second,*third;
	insert(dlist, 0, &number1);
	insert(dlist, 1, &number2);
	insert(dlist, 2, &number3);
	ASSERT(delete(dlist, 0));
	ASSERT(2 == dlist->length);
	ASSERT(9 == *(int*)dlist->head->data);
}
void test_delete_last_element(){
	DoubleList* dlist = create();
	int number1 = 5,number2 = 9,number3 = 65;
	node *second,*third;
	insert(dlist, 0, &number1);
	insert(dlist, 1, &number2);
	insert(dlist, 2, &number3);
	ASSERT(delete(dlist, 2));
	ASSERT(2 == dlist->length);
	ASSERT(NULL == dlist->head->next->next);
}
void test_delete_element_in_between(){
	DoubleList* dlist = create();
	int number1 = 5,number2 = 9,number3 = 65;
	node *second,*third;
	insert(dlist, 0, &number1);
	insert(dlist, 1, &number2);
	insert(dlist, 2, &number3);
	ASSERT(delete(dlist, 1));
	ASSERT(2 == dlist->length);
	ASSERT(65 == *(int*)dlist->head->next->data);
}
void test_find_index_gives_index_of_element(){
	DoubleList* dlist = create();
	int number1 = 5,number2 = 9,number3 = 65,number4 = 45,number5 = 90;
	node *second,*third;
	insert(dlist, 0, &number1);
	insert(dlist, 1, &number2);
	insert(dlist, 2, &number3);
	insert(dlist, 2, &number4);
	insert(dlist, 2, &number5);
	ASSERT(2 == findIndex(dlist, &number5));
	// view_list_details(dlist);
}
typedef struct{
	int accno;
	int balance;
} Account;
int cmpAccount(Account expected,Account actual){
	return (expected.accno == actual.accno 
				&& expected.balance == actual.balance);
}
void test_insert_struct_in_list_starting(){
	DoubleList* dlist = create();
	Account acc1 = {5,4000};
	insert(dlist, 0, &acc1);
	ASSERT(&acc1 == dlist->head->data);
	ASSERT(cmpAccount(acc1, *(Account*)dlist->head->data));
	ASSERT(dlist->length == 1);	
}
void test_add_struct_in_between_list(){
	DoubleList* dlist = create();
	Account acc0 = {5,450},acc2 = {9,456},acc3 = {6,455},acc1 = {1,445};
	node *second,*third,*fourth;
	insert(dlist, 0, &acc0);
	insert(dlist, 1, &acc2);
	insert(dlist, 2, &acc3);
	insert(dlist, 1, &acc1);
	second = dlist->head->next;
	third = second->next;
	fourth = third->next;
	ASSERT(cmpAccount(acc0,*(Account*)dlist->head->data));
	ASSERT(cmpAccount(acc1,*(Account*)second->data));
	ASSERT(cmpAccount(acc2,*(Account*)third->data));
	ASSERT(cmpAccount(acc3,*(Account*)fourth->data));	
}
void test_delete_first_element_on_struct(){
	DoubleList* dlist = create();
	Account acc1 = {5,45},acc2 = {9,56},acc3 = {65,89};
	node *second,*third;
	insert(dlist, 0, &acc1);
	insert(dlist, 1, &acc2);
	insert(dlist, 2, &acc3);
	ASSERT(delete(dlist, 0));
	ASSERT(2 == dlist->length);
	ASSERT(cmpAccount(acc2,*(Account*)dlist->head->data));
}
void test_delete_last_element(){
	DoubleList* dlist = create();
	Account acc1 = 5,acc2 = 9,acc3 = 65;
	node *second,*third;
	insert(dlist, 0, &acc1);
	insert(dlist, 1, &acc2);
	insert(dlist, 2, &acc3);
	ASSERT(delete(dlist, 2));
	ASSERT(2 == dlist->length);
	ASSERT(NULL == dlist->head->next->next);
}
