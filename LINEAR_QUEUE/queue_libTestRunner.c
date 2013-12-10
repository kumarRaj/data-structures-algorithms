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
	testStarted("test_enqueue_on_non_empty_queue");
	setup();
		test_enqueue_on_non_empty_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_on_putting_struct_to_queue");
	setup();
		test_enqueue_on_putting_struct_to_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_on_full_queue_returns_false");
	setup();
		test_enqueue_on_full_queue_returns_false();
	tearDown();
	testEnded();
	testStarted("test_deque_on_queue_with_values");
	setup();
		test_deque_on_queue_with_values();
	tearDown();
	testEnded();
	testStarted("test_deque_on_empty_queue");
	setup();
		test_deque_on_empty_queue();
	tearDown();
	testEnded();
	testStarted("test_deque_with_struct");
	setup();
		test_deque_with_struct();
	tearDown();
	testEnded();
	testStarted("test_dequeue_isEmpty");
	setup();
		test_dequeue_isEmpty();
	tearDown();
	testEnded();
	testStarted("test_dequeue_is_not_Empty");
	setup();
		test_dequeue_is_not_Empty();
	tearDown();
	testEnded();
	testStarted("test_dequeue_isFull");
	setup();
		test_dequeue_isFull();
	tearDown();
	testEnded();
	testStarted("test_dequeue_is_not_Full");
	setup();
		test_dequeue_is_not_Full();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
