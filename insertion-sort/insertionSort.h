#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef char string[20];

typedef struct {
	string name;
	int accountNumber;
	float balance;
} Account;

typedef int (*compare)(void* first, void* second);
void isort(void* base, size_t numberOfElements, size_t elementSize,compare comp);