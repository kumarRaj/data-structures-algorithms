#include "bracesValidation.h"
#include <stdio.h>
#include <stdlib.h>
char getClosingBracket(char letter){
	if (letter=='(') return ')';
	if (letter=='{') return '}';
	if (letter=='[') return ']';
	return 0;
}
char isCloseBracket(char letter){
	return (letter == ')' || letter == '}' || letter == ']');
}
int validateBraces(char *text){
	int i,result;
	char expected = '\0';
	Stack *stack = create(sizeof(char), strlen(text));
	for (i = 0; i < strlen(text); ++i){
		if(getClosingBracket(text[i])){
			push(stack, &text[i]);
			expected = getClosingBracket(text[i]);
			continue;
		}
		if(text[i] == expected){
			pop(stack);
			expected = '\0';
			if(isEmpty(stack)) continue;
			expected = getClosingBracket(*(char*)(peek(stack)));
			continue;
		}
		if(isCloseBracket(text[i])){
			push(stack,&text[i]);
			break;
		}
	}
	result = isEmpty(stack);
	dispose(stack);
	return result;
}