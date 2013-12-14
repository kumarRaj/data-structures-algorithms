#include "testUtils.h"
#include "bracesValidation.h"
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1isOpenBracket_returns_corresponding_simple_close_bracket(){
	ASSERT(')' == getClosingBracket('('));
}
void test_2isOpenBracket_returns_corresponding_curly_close_bracket(){
	ASSERT('}' == getClosingBracket('{'));
}
void test_3gives_true_for_valid_open_and_closing_curly_braces(){
	char* text = "{[}]";
	int result = validateBraces(text);
	ASSERT(0 == result);
}
void test_4gives_false_for_extra_opening_braces(){
	char* text = "{}ER[DF";
	int result = validateBraces(text);
	ASSERT(0 == result);
}
void test_5gives_true_for_valid_open_and_closing_braces(){
	char* text = "[((){cjkdjds}cdcds)cwce]";
	int result = validateBraces(text);
	ASSERT(1 == result);
}
void test_7gives_false_for_extra_closing_braces(){
	char* text = "(ias[yui]))";
	int result = validateBraces(text);
	ASSERT(0 == result);
}
void test_8gives_true_for_closing_brace(){
	ASSERT(isCloseBracket(')'));	
}
void test_9gives_false_for_only_closing_braces(){
	char* text = "})]]";	
	int result = validateBraces(text);
	ASSERT(0 == result);
}
void test_10gives_true_for_no_braces(){
	char* text = "abcd";	
	int result = validateBraces(text);
	ASSERT(1 == result);
}