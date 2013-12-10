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

	testStarted("test_1isOpenBracket_returns_corresponding_simple_close_bracket");
	setup();
		test_1isOpenBracket_returns_corresponding_simple_close_bracket();
	tearDown();
	testEnded();
	testStarted("test_2isOpenBracket_returns_corresponding_curly_close_bracket");
	setup();
		test_2isOpenBracket_returns_corresponding_curly_close_bracket();
	tearDown();
	testEnded();
	testStarted("test_3gives_true_for_valid_open_and_closing_curly_braces");
	setup();
		test_3gives_true_for_valid_open_and_closing_curly_braces();
	tearDown();
	testEnded();
	testStarted("test_4gives_false_for_extra_opening_braces");
	setup();
		test_4gives_false_for_extra_opening_braces();
	tearDown();
	testEnded();
	testStarted("test_5gives_true_for_valid_open_and_closing_braces");
	setup();
		test_5gives_true_for_valid_open_and_closing_braces();
	tearDown();
	testEnded();
	testStarted("test_7gives_false_for_extra_closing_braces");
	setup();
		test_7gives_false_for_extra_closing_braces();
	tearDown();
	testEnded();
	testStarted("test_8gives_true_for_closing_brace");
	setup();
		test_8gives_true_for_closing_brace();
	tearDown();
	testEnded();
	testStarted("test_9gives_false_for_only_closing_braces");
	setup();
		test_9gives_false_for_only_closing_braces();
	tearDown();
	testEnded();
	testStarted("test_10gives_true_for_no_braces");
	setup();
		test_10gives_true_for_no_braces();
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
