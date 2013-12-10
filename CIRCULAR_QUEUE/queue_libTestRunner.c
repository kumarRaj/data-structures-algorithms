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

	testStarted("test_create_integer_queue");
	setup();
		test_create_integer_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_on_empty_queue");
	setup();
		test_enqueue_on_empty_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_on_queue_which_reached_end_of_queue");
	setup();
		test_enqueue_on_queue_which_reached_end_of_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_on_queue_which_reached_front_of_queue");
	setup();
		test_enqueue_on_queue_which_reached_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_deque_on_queue_with_values_returns_front_element");
	setup();
		test_deque_on_queue_with_values_returns_front_element();
	tearDown();
	testEnded();
	testStarted("test_deque_on_empty_queue_without_any_values_returns_null");
	setup();
		test_deque_on_empty_queue_without_any_values_returns_null();
	tearDown();
	testEnded();
	testStarted("test_dequeue_where_queue_reached_end_of_queue");
	setup();
		test_dequeue_where_queue_reached_end_of_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_on_putting_struct_to_queue");
	setup();
		test_enqueue_on_putting_struct_to_queue();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
