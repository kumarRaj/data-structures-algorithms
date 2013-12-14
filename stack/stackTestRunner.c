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

	testStarted("test_creates_a_stack_of_given_length");
	setup();
		test_creates_a_stack_of_given_length();
	tearDown();
	testEnded();
	testStarted("test_adds_the_given_integerto_stack");
	setup();
		test_adds_the_given_integerto_stack();
	tearDown();
	testEnded();
	testStarted("test_adds_the_doubles_to_stack");
	setup();
		test_adds_the_doubles_to_stack();
	tearDown();
	testEnded();
	testStarted("test_adds_Strings_to_stack");
	setup();
		test_adds_Strings_to_stack();
	tearDown();
	testEnded();
	testStarted("test_adds_structures_to_stacks");
	setup();
		test_adds_structures_to_stacks();
	tearDown();
	testEnded();
	testStarted("test_doubles_the_length_of_stack_on_stack_full");
	setup();
		test_doubles_the_length_of_stack_on_stack_full();
	tearDown();
	testEnded();
	testStarted("test_removes_the_top_element_from_the_stack_integers");
	setup();
		test_removes_the_top_element_from_the_stack_integers();
	tearDown();
	testEnded();
	testStarted("test_removes_the_top_element_from_the_stack_Strings");
	setup();
		test_removes_the_top_element_from_the_stack_Strings();
	tearDown();
	testEnded();
	testStarted("test_removes_structures_on_the_top_of_stacks");
	setup();
		test_removes_structures_on_the_top_of_stacks();
	tearDown();
	testEnded();
	testStarted("test_remove_on_empty_stack");
	setup();
		test_remove_on_empty_stack();
	tearDown();
	testEnded();
	testStarted("test_gives_top_element_integers");
	setup();
		test_gives_top_element_integers();
	tearDown();
	testEnded();
	testStarted("test_gives_the_top_stack_character");
	setup();
		test_gives_the_top_stack_character();
	tearDown();
	testEnded();
	testStarted("test_tells_the_stack_is_empty");
	setup();
		test_tells_the_stack_is_empty();
	tearDown();
	testEnded();
	testStarted("test_tells_the_stack_is_not_empty");
	setup();
		test_tells_the_stack_is_not_empty();
	tearDown();
	testEnded();
	testStarted("test_tells_the_stack_is_full");
	setup();
		test_tells_the_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_tells_the_stack_is_not_full");
	setup();
		test_tells_the_stack_is_not_full();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
