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
	testStarted("test_create_double_list");
	setup();
		test_create_double_list();
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

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
