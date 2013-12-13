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

	testStarted("test_1_creation_of_stack");
	setup();
		test_1_creation_of_stack();
	tearDown();
	testEnded();
	testStarted("test_2creation_of_stack_for_String");
	setup();
		test_2creation_of_stack_for_String();
	tearDown();
	testEnded();
	testStarted("test_3push_on_empty_stack");
	setup();
		test_3push_on_empty_stack();
	tearDown();
	testEnded();
	testStarted("test_4push_on_full_stack_doubles_size_of_stack");
	setup();
		test_4push_on_full_stack_doubles_size_of_stack();
	tearDown();
	testEnded();
	testStarted("test_5push_string_on_empty_stack");
	setup();
		test_5push_string_on_empty_stack();
	tearDown();
	testEnded();
	testStarted("test_6pop_double_on_stack");
	setup();
		test_6pop_double_on_stack();
	tearDown();
	testEnded();
	testStarted("test_7pop_string_from_stack");
	setup();
		test_7pop_string_from_stack();
	tearDown();
	testEnded();
	testStarted("test_8pop_string_from_empty_stack_should_give_NULL");
	setup();
		test_8pop_string_from_empty_stack_should_give_NULL();
	tearDown();
	testEnded();
	testStarted("test_9peek_in_stack_should_give_last_element_without_changing_top");
	setup();
		test_9peek_in_stack_should_give_last_element_without_changing_top();
	tearDown();
	testEnded();
	testStarted("test_10peek_string_stack_when_empty_should_give_NULL");
	setup();
		test_10peek_string_stack_when_empty_should_give_NULL();
	tearDown();
	testEnded();
	testStarted("test_11stack_isEmpty_should_give_true_for_empty_stack");
	setup();
		test_11stack_isEmpty_should_give_true_for_empty_stack();
	tearDown();
	testEnded();
	testStarted("test_12stack_isEmpty_should_give_false_if_stack_is_not_empty");
	setup();
		test_12stack_isEmpty_should_give_false_if_stack_is_not_empty();
	tearDown();
	testEnded();
	testStarted("test_13stack_isFull_should_give_true_for_full_stack");
	setup();
		test_13stack_isFull_should_give_true_for_full_stack();
	tearDown();
	testEnded();
	testStarted("test_14stack_isFull_should_give_false_for_not_full_stack");
	setup();
		test_14stack_isFull_should_give_false_for_not_full_stack();
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
