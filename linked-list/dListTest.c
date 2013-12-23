#include "testUtils.h"
#include "dList.h"
#include <stdlib.h>
#include <stdio.h>
#include "../Iterator/iterator.h"
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
void view_list_details(DoubleList dlist){
	node *temp;int i;
	printf("\n\n");
	temp = dlist.head;
	for (i = 0; i < dlist.length;i++){
		printf("%d--\t\n",*(int*)temp->data);
		temp = temp->next;
	}
}

void test_add_data_to_empty_list(){
	DoubleList dlist = create();
	int number = 5;
	insert(&dlist, 0, &number);
	ASSERT(5 == *(int*)dlist.head->data);
	ASSERT(dlist.length == 1);
}
void test_add_data_to_list_where_index_more_than_length(){
	DoubleList dlist = create();
	int number = 5;
	insert(&dlist, 0, &number);
	ASSERT(0 == insert(&dlist, 5, &number));
	ASSERT(5 == *(int*)dlist.head->data);
	ASSERT(dlist.length == 1);
}
void test_add_multiple_data_to_end_of_list(){
	DoubleList dlist = create();
	int number1 = 5,number2 = 9,number3 = 65;
	node *second,*third;
	insert(&dlist, 0, &number1);
	insert(&dlist, 1, &number2);
	insert(&dlist, 2, &number3);
	second = dlist.head->next;
	third = second->next;
	ASSERT(5 == *(int*)dlist.head->data);
	ASSERT(9 == *(int*)second->data);
	ASSERT(65 == *(int*)third->data);
	ASSERT(dlist.length == 3);
	ASSERT(dlist.head == second->previous);
}
void test_add_data_in_beginning_of_list_with_values(){
	int number1 = 5,number2 = 9,number0 = 65;
	DoubleList dlist = create();
	node *second,*third;
	insert(&dlist, 0, &number1);
	insert(&dlist, 1, &number2);
	insert(&dlist, 0, &number0);
	ASSERT(65 == *(int*)dlist.head->data);
	ASSERT(5 == *(int*)dlist.head->next->data);

}
void test_add_data_in_between_list(){
	DoubleList dlist = create();
	int number0 = 5,number2 = 9,number3 = 65,number1 = 17,i;
	node *second,*third,*fourth;
	insert(&dlist, 0, &number0);
	insert(&dlist, 1, &number2);
	insert(&dlist, 2, &number3);
	insert(&dlist, 1, &number1);
	second = dlist.head->next;
	third = second->next;
	fourth = third->next;
	ASSERT(5 == *(int*)dlist.head->data);
	ASSERT(17 == *(int*)second->data);
	ASSERT(9 == *(int*)third->data);
	ASSERT(65 == *(int*)fourth->data);
}
void test_delete_first_element_in_list_with_one_element(){
	DoubleList dlist = create();
	int number1 = 5,number2 = 9,number3 = 65;
	node *second,*third;
	insert(&dlist, 0, &number1);
	ASSERT(delete(&dlist, 0));
	ASSERT(0 == dlist.length);
	ASSERT(NULL == dlist.head);
}
void test_delete_first_element(){
	DoubleList dlist = create();
	int number1 = 5,number2 = 9,number3 = 65;
	node *second,*third;
	insert(&dlist, 0, &number1);
	insert(&dlist, 1, &number2);
	insert(&dlist, 2, &number3);
	ASSERT(delete(&dlist, 0));
	ASSERT(2 == dlist.length);
	ASSERT(9 == *(int*)dlist.head->data);
}
void test_delete_last_element(){
	DoubleList dlist = create();
	int number1 = 5,number2 = 9,number3 = 65;
	node *second,*third;
	insert(&dlist, 0, &number1);
	insert(&dlist, 1, &number2);
	insert(&dlist, 2, &number3);
	ASSERT(delete(&dlist, 2));
	ASSERT(2 == dlist.length);
	ASSERT(NULL == dlist.head->next->next);
}
void test_delete_element_in_between(){
	DoubleList dlist = create();
	int number1 = 5,number2 = 9,number3 = 65;
	node *second,*third;
	insert(&dlist, 0, &number1);
	insert(&dlist, 1, &number2);
	insert(&dlist, 2, &number3);
	ASSERT(delete(&dlist, 1));
	ASSERT(2 == dlist.length);
	ASSERT(65 == *(int*)dlist.head->next->data);
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
	DoubleList dlist = create();
	Account acc1 = {5,4000};
	insert(&dlist, 0, &acc1);
	ASSERT(&acc1 == dlist.head->data);
	ASSERT(cmpAccount(acc1, *(Account*)dlist.head->data));
	ASSERT(dlist.length == 1);	
}
void test_add_struct_in_between_list(){
	DoubleList dlist = create();
	Account acc0 = {5,450},acc2 = {9,456},acc3 = {6,455},acc1 = {1,445};
	node *second,*third,*fourth;
	insert(&dlist, 0, &acc0);
	insert(&dlist, 1, &acc2);
	insert(&dlist, 2, &acc3);
	insert(&dlist, 1, &acc1);
	second = dlist.head->next;
	third = second->next;
	fourth = third->next;
	ASSERT(cmpAccount(acc0,*(Account*)dlist.head->data));
	ASSERT(cmpAccount(acc1,*(Account*)second->data));
	ASSERT(cmpAccount(acc2,*(Account*)third->data));
	ASSERT(cmpAccount(acc3,*(Account*)fourth->data));	
}
void test_delete_first_element_on_struct(){
	DoubleList dlist = create();
	Account acc1 = {5,45},acc2 = {9,56},acc3 = {65,89};
	node *second,*third;
	insert(&dlist, 0, &acc1);
	insert(&dlist, 1, &acc2);
	insert(&dlist, 2, &acc3);
	ASSERT(delete(&dlist, 0));
	ASSERT(2 == dlist.length);
	ASSERT(cmpAccount(acc2,*(Account*)dlist.head->data));
}
void test_delete_last_element_on_struct(){
	DoubleList dlist = create();
	Account acc1 = {5,45},acc2 = {9,56},acc3 = {65,89};
	node *second,*third;
	insert(&dlist, 0, &acc1);
	insert(&dlist, 1, &acc2);
	insert(&dlist, 2, &acc3);
	ASSERT(delete(&dlist, 2));
	ASSERT(2 == dlist.length);
	ASSERT(NULL == dlist.head->next->next);
}
int compare_lists(DoubleList expected,DoubleList actual,compare comp){
	node *temp1,*temp2;int i;
	temp1 = expected.head;
	temp2 = expected.head;
	for (i = 0; i < expected.length;i++){
		if(comp(temp1->data,temp2->data) != 0)
			return 0;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return 1;
}
int compareInt(void *element1,void *element2){
	return *(int*)element1 - *(int*)element2;
}
void test_sort_on_dList_should_sort_list(){
	DoubleList dList = create();
	DoubleList expected = create();
	int nums[3] = {65,55,45};
	insert(&dList, 0, nums);
	insert(&dList, 1, &nums[1]);
	insert(&dList, 2, &nums[2]);
	insert(&expected, 0, &nums[2]);
	insert(&expected, 1, &nums[1]);
	insert(&expected, 2, nums);
	sort(dList, compareInt);
	compare_lists(expected, dList, compareInt);
}
int cmp(void *elementToCompare,void *element){
	Account accToCompare = *(Account*)elementToCompare;
	Account account = *(Account*)element;
	return accToCompare.accno == account.accno;
}
void test_search_data_in_list_should_give_found_element(){
	DoubleList dList = create();
	Account acc1 = {5,45},acc2 = {9,56},acc3 = {65,89},expected;
	insert(&dList, 0, &acc1);
	insert(&dList, 1, &acc2);
	insert(&dList, 2, &acc3);
	expected = *(Account*)getData(dList, &acc2, cmp);
	ASSERT(acc2.accno == expected.accno);
	ASSERT(acc2.balance == expected.balance);
}
void test_search_data_should_give_NULL_if_data_not_found(){
	DoubleList dList = create();
	Account acc1 = {5,45},acc2 = {9,56},acc3 = {65,89};
	Account searchElement = {0,0};
	void *expected = NULL;
	insert(&dList, 0, &acc1);
	insert(&dList, 1, &acc2);
	insert(&dList, 2, &acc3);
	expected = getData(dList, &searchElement, cmp);
	ASSERT(NULL == expected);
}
void test_hasnext_of_getiterator_gives_true_if_list_not_empty(){
	DoubleList dList = create();
	Iterator it;
	int number1 = 5,number2 = 9,number3 = 65;
	insert(&dList, 0, &number1);
	it = getIterator(&dList);
	ASSERT(1 == it.hasNext(&it));
}
void test_hasnext_of_getiterator_gives_false_if_list_not_empty(){
	DoubleList dList = create();
	Iterator it;
	it = getIterator(&dList);
	ASSERT(0 == it.hasNext(&it));
}
void test_next_of_getiterator_gives_next_data(){
	DoubleList dList = create();
	Iterator it;
	int number1 = 5;
	insert(&dList, 0, &number1);
	it = getIterator(&dList);
	if(it.hasNext(&it))
	ASSERT(5 == *(int*)it.next(&it));
}
void test_should_give_all_values_using_iterator(){
	DoubleList dList = create();
	Iterator it;int i = 0;
	int numbers[] = {5,10,15,20};
	insert(&dList, 0, numbers);
	insert(&dList, 1, &numbers[1]);
	insert(&dList, 2, &numbers[2]);
	insert(&dList, 3, &numbers[3]);
	it = getIterator(&dList);
	while(it.hasNext(&it)){		
		ASSERT(numbers[i] == *(int*)it.next(&it));
		i++;
	}
}