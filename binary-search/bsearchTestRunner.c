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

	testStarted("test_to_search_in_integer_array_element_less_than_mid");
	setup();
		test_to_search_in_integer_array_element_less_than_mid();
	tearDown();
	testEnded();
	testStarted("test_to_search_integer_array_element_on_mid");
	setup();
		test_to_search_integer_array_element_on_mid();
	tearDown();
	testEnded();
	testStarted("test_to_search_integer_array_element_greater_than_mid");
	setup();
		test_to_search_integer_array_element_greater_than_mid();
	tearDown();
	testEnded();
	testStarted("test_to_search_double_in_array");
	setup();
		test_to_search_double_in_array();
	tearDown();
	testEnded();
	testStarted("test_to_search_element_which_is_not_present_in_double_array_");
	setup();
		test_to_search_element_which_is_not_present_in_double_array_();
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
