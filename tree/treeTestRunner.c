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

	testStarted("test_insert_root_node");
	setup();
		test_insert_root_node();
	tearDown();
	testEnded();
	testStarted("test_insert_node_under_root_node");
	setup();
		test_insert_node_under_root_node();
	tearDown();
	testEnded();
	testStarted("test_insert_under_child_node");
	setup();
		test_insert_under_child_node();
	tearDown();
	testEnded();
	testStarted("test_insert_under_second_child");
	setup();
		test_insert_under_second_child();
	tearDown();
	testEnded();
	testStarted("test_insert_nodes_from_different_level");
	setup();
		test_insert_nodes_from_different_level();
	tearDown();
	testEnded();
	testStarted("test_delete_node_under_root_node_from_tree");
	setup();
		test_delete_node_under_root_node_from_tree();
	tearDown();
	testEnded();
	testStarted("test_delete_root_node_from_tree");
	setup();
		test_delete_root_node_from_tree();
	tearDown();
	testEnded();
	testStarted("test_delete_nodes_from_different_level");
	setup();
		test_delete_nodes_from_different_level();
	tearDown();
	testEnded();
	testStarted("test_search_element_in_the_tree");
	setup();
		test_search_element_in_the_tree();
	tearDown();
	testEnded();
	testStarted("test_not_search_element_in_the_tree");
	setup();
		test_not_search_element_in_the_tree();
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
