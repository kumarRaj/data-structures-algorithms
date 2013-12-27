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
	interns = ArrayList_create(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	ArrayList_dispose(internsPtr);	
}

void test_insert_element(){
	int result = ArrayList_insert(internsPtr, 0, &prateek);

	Intern *actual = (Intern*)ArrayList_get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_insert_multiple_elements() {
	ArrayList_insert(internsPtr, 0, &prateek);
	ArrayList_insert(internsPtr, 1, &ji);
	ASSERT(&prateek == ArrayList_get(internsPtr, 0));
	ASSERT(&ji == ArrayList_get(internsPtr, 1));
}

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = ArrayList_create(noOfElements);
	ArrayList *listPtr = &list;

	ArrayList_insert(listPtr, 0, &prateek);
	ArrayList_insert(listPtr, 1, &ji);

	ASSERT(&prateek == ArrayList_get(listPtr, 0));
	ASSERT(&ji == ArrayList_get(listPtr, 1));

	ArrayList_dispose(listPtr);		
}

void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = ArrayList_insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = ArrayList_insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	ArrayList_insert(internsPtr, 0, &prateek);
	ArrayList_insert(internsPtr, 1, &ji);
	ArrayList_insert(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == ArrayList_get(internsPtr, 0));
	ASSERT(&tanbirka == ArrayList_get(internsPtr, 1));
	ASSERT(&ji == ArrayList_get(internsPtr, 2));
}

void test_should_not_insert_when_list_is_null() {
	int result = ArrayList_insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}
int compareInterns(void *intern1,void *intern2){
	Intern in1 = *(Intern*)intern1;
	Intern in2 = *(Intern*)intern2;
	return (in1.id - in2.id);
}
void test_should_ArrayList_get_index_of_search_element() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	ArrayList_insert(internsPtr, 0, &prateek);
	ArrayList_insert(internsPtr, 1, &ji);
	ArrayList_insert(internsPtr, 2, &tanbirka);
	ASSERT(2 == ArrayList_search(internsPtr, &tanbirka, compareInterns));
}
void test_should_ArrayList_get_minus_1_if_element_not_found() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	ArrayList_insert(internsPtr, 0, &prateek);
	ArrayList_insert(internsPtr, 1, &ji);
	ASSERT(-1 == ArrayList_search(internsPtr, &tanbirka, compareInterns));
}
void test_iterator_hasNext_should_give_TRUE_when_element_is_present() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	Iterator it = ArrayList_getIterator(internsPtr);
	ArrayList_insert(internsPtr, 0, &prateek);
	ASSERT(1 == it.hasNext(&it));
}
void test_iterator_hasNext_should_give_FALSE_when_element_is_not_present() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	Iterator it = ArrayList_getIterator(internsPtr);
	ASSERT(0 == it.hasNext(&it));
}
void test_iterator_next_should_give_next_element() {
	Iterator it = ArrayList_getIterator(internsPtr);
	Intern *res;
	ArrayList_insert(internsPtr, 0, &prateek);
	res = (Intern*)it.next(&it);
	ASSERT(0 == compareInterns(&prateek, res));
}
void test_iterator_next_should_give_NULL_in_empty_ArrayList() {
	Iterator it = ArrayList_getIterator(internsPtr);
	Intern *res;
	res = (Intern*)it.next(&it);
	ASSERT(NULL == res);
}
void test_deletes_single_element_from_list(){
	Iterator it = ArrayList_getIterator(internsPtr);
	ArrayList_insert(internsPtr, 0, &prateek);
	ArrayList_remove(internsPtr, 0);
	ASSERT(0 == it.hasNext(&it));
}
void test_deletes_and_shifts_elements_left(){
	Intern tanbirka = {43343, "Tanbir Ka"};
    int result;
    Intern *res;
	Iterator it = ArrayList_getIterator(internsPtr);
    ArrayList_insert(internsPtr, 0, &prateek);
    ArrayList_insert(internsPtr, 1, &ji);
    ArrayList_insert(internsPtr, 2, &tanbirka);
    result = ArrayList_remove(internsPtr, 0);
    ASSERT(result == SUCCESS);  
	ASSERT(0 == compareInterns(&ji, ArrayList_get(internsPtr, 0)));
	ASSERT(0 == compareInterns(&tanbirka, ArrayList_get(internsPtr, 1)));
}
void test_add_adds_to_end_of_list(){
    int result = ArrayList_add(internsPtr, &prateek);
    ASSERT(result == SUCCESS);  
	ASSERT(0 == compareInterns(&prateek, ArrayList_get(internsPtr, 0)));
}
void test_add_adds_multiple_data_to_end_of_list(){
    int result = ArrayList_add(internsPtr, &prateek);
    ASSERT(result == SUCCESS);  
	result = ArrayList_add(internsPtr, &ji);
	ASSERT(0 == compareInterns(&prateek, ArrayList_get(internsPtr, 0)));
	ASSERT(0 == compareInterns(&ji, ArrayList_get(internsPtr, 1)));
}
void increaseAgeBy10(void* data){
    ((Intern*)data)->age += 10;
}

void test_iterate_visits_each_element_of_list(){
    Iterator b4it,a4it;
    b4it = ArrayList_getIterator(internsPtr);
    ArrayList_add(internsPtr, &prateek);
    ArrayList_add(internsPtr, &ji);
    ArrayList_iterate(interns, increaseAgeBy10);
    a4it = ArrayList_getIterator(internsPtr);
	ASSERT(28 == (*(Intern*)a4it.next(&a4it)).age);
 	ASSERT(27 == (*(Intern*)a4it.next(&a4it)).age);
}