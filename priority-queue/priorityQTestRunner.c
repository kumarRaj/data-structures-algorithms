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

	testStarted("test_adds_the_element_at_the_starting_of_queue");
	setup();
		test_adds_the_element_at_the_starting_of_queue();
	tearDown();
	testEnded();
	testStarted("test_adds_the_element_first_having_lower_priority");
	setup();
		test_adds_the_element_first_having_lower_priority();
	tearDown();
	testEnded();
	testStarted("test_adds_three_elements_in_priority_queue");
	setup();
		test_adds_three_elements_in_priority_queue();
	tearDown();
	testEnded();
	testStarted("test_remove_element_from_queue");
	setup();
		test_remove_element_from_queue();
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
