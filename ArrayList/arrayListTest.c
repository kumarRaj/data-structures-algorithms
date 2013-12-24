#include <stdlib.h>

#include "testUtils.h"
#include "arrayList.h"
#include "include/iterator.h"

const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int id;
	char* name;
	int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};	
ArrayList interns;
ArrayList *internsPtr;

void setup() {
	int noOfElements = 2;	
	interns = create(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	dispose(internsPtr);	
}

void test_insert_element(){
	int result = insert(internsPtr, 0, &prateek);

	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_insert_multiple_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
}

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;

	insert(listPtr, 0, &prateek);
	insert(listPtr, 1, &ji);

	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&ji == get(listPtr, 1));

	dispose(listPtr);		
}

void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&tanbirka == get(internsPtr, 1));
	ASSERT(&ji == get(internsPtr, 2));
}

void test_should_not_insert_when_list_is_null() {
	int result = insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}
int compareInterns(void *intern1,void *intern2){
	Intern in1 = *(Intern*)intern1;
	Intern in2 = *(Intern*)intern2;
	return (in1.id - in2.id);
}
void test_should_get_index_of_search_element() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 2, &tanbirka);
	ASSERT(2 == search(internsPtr, &tanbirka, compareInterns));
}
void test_should_get_minus_1_if_element_not_found() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(-1 == search(internsPtr, &tanbirka, compareInterns));
}
void test_iterator_hasNext_should_give_TRUE_when_element_is_present() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	Iterator it = getIterator(internsPtr);
	insert(internsPtr, 0, &prateek);
	ASSERT(1 == it.hasNext(&it));
}
void test_iterator_hasNext_should_give_FALSE_when_element_is_not_present() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	Iterator it = getIterator(internsPtr);
	ASSERT(0 == it.hasNext(&it));
}
void test_iterator_next_should_give_next_element() {
	Iterator it = getIterator(internsPtr);
	Intern *res;
	insert(internsPtr, 0, &prateek);
	res = (Intern*)it.next(&it);
	ASSERT(0 == compareInterns(&prateek, res));
}
void test_iterator_next_should_give_NULL_in_empty_ArrayList() {
	Iterator it = getIterator(internsPtr);
	Intern *res;
	res = (Intern*)it.next(&it);
	ASSERT(NULL == res);
}
void test_deletes_single_element_from_list(){
	Iterator it = getIterator(internsPtr);
	insert(internsPtr, 0, &prateek);
	remove(internsPtr, 0);
	ASSERT(0 == it.hasNext(&it));
}
void test_deletes_and_shifts_elements_left(){
	Intern tanbirka = {43343, "Tanbir Ka"};
    int result;
    Intern *res;
	Iterator it = getIterator(internsPtr);
    insert(internsPtr, 0, &prateek);
    insert(internsPtr, 1, &ji);
    insert(internsPtr, 2, &tanbirka);
    result = remove(internsPtr, 0);
    ASSERT(result == SUCCESS);  
	ASSERT(0 == compareInterns(&ji, get(internsPtr, 0)));
	ASSERT(0 == compareInterns(&tanbirka, get(internsPtr, 1)));
}
void test_add_adds_to_end_of_list(){
    int result = add(internsPtr, &prateek);
    ASSERT(result == SUCCESS);  
	ASSERT(0 == compareInterns(&prateek, get(internsPtr, 0)));
}
void test_add_adds_multiple_data_to_end_of_list(){
    int result = add(internsPtr, &prateek);
    ASSERT(result == SUCCESS);  
	result = add(internsPtr, &ji);
	ASSERT(0 == compareInterns(&prateek, get(internsPtr, 0)));
	ASSERT(0 == compareInterns(&ji, get(internsPtr, 1)));
}