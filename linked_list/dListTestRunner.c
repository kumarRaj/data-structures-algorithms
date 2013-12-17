#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_create_node");
	setup();
		test_create_node();
	tearDown();
	testEnded();
	testStarted("test_add_data_to_empty_list");
	setup();
		test_add_data_to_empty_list();
	tearDown();
	testEnded();
	testStarted("test_add_data_to_list_where_index_more_than_length");
	setup();
		test_add_data_to_list_where_index_more_than_length();
	tearDown();
	testEnded();
	testStarted("test_add_multiple_data_to_end_of_list");
	setup();
		test_add_multiple_data_to_end_of_list();
	tearDown();
	testEnded();
	testStarted("test_add_multiple_data_to_start_of_list");
	setup();
		test_add_multiple_data_to_start_of_list();
	tearDown();
	testEnded();
	testStarted("test_add_data_in_beginning_of_list_with_values");
	setup();
		test_add_data_in_beginning_of_list_with_values();
	tearDown();
	testEnded();
	testStarted("test_add_data_in_between_list");
	setup();
		test_add_data_in_between_list();
	tearDown();
	testEnded();
	testStarted("test_delete_first_element_in_list_with_one_element");
	setup();
		test_delete_first_element_in_list_with_one_element();
	tearDown();
	testEnded();
	testStarted("test_delete_first_element");
	setup();
		test_delete_first_element();
	tearDown();
	testEnded();
	testStarted("test_delete_last_element");
	setup();
		test_delete_last_element();
	tearDown();
	testEnded();
	testStarted("test_delete_element_in_between");
	setup();
		test_delete_element_in_between();
	tearDown();
	testEnded();
	testStarted("test_find_index_gives_index_of_element");
	setup();
		test_find_index_gives_index_of_element();
	tearDown();
	testEnded();
	testStarted("test_insert_struct_in_list_starting");
	setup();
		test_insert_struct_in_list_starting();
	tearDown();
	testEnded();
	testStarted("test_add_struct_in_between_list");
	setup();
		test_add_struct_in_between_list();
	tearDown();
	testEnded();
	testStarted("test_delete_first_element_on_struct");
	setup();
		test_delete_first_element_on_struct();
	tearDown();
	testEnded();
	testStarted("test_delete_last_element_on_struct");
	setup();
		test_delete_last_element_on_struct();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
