#include <memory.h>
#include <stdlib.h>
#include "stack.h"
#include "testUtils.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Stack* stack;

void tearDown(){
    free(stack->elements);
    free(stack);
}

typedef struct {
    int accNo;
    int balance;
} Account;

int areAccountsEqual(Account expected,Account actual){
    return expected.accNo == actual.accNo && expected.balance == actual.balance;
}


void test_creates_a_stack_of_given_length (){
    stack = create(3);
    ASSERT(3 == stack->length);
    ASSERT(0 == stack->top);
};

void test_adds_the_given_integerto_stack(){
        int* num = malloc(sizeof(int));
        *num = 2;
        stack = create(1);
        push(stack, num);
        ASSERT(2 == **(int**)stack->elements);
        ASSERT(1 == stack->top);
        ASSERT(1 == stack->length);
}

void test_adds_the_doubles_to_stack(){
        double *nums = malloc(sizeof(double)*2);
        nums[0] = 34.0;nums[1] = 11.5;
        stack = create(2);
        push(stack, &nums[0]);
        push(stack, &nums[1]);
        ASSERT(34.0 == **(double**)getElement(stack, 0));
        ASSERT(11.5 == **(double**)getElement(stack, 1));
        ASSERT(2 == stack->top && 2 == stack->length);
}

void test_adds_Strings_to_stack(){
        String_256* names = malloc(sizeof(String_256)*2);
        strcpy(names[0], "ram");
        strcpy(names[1], "sham");
        stack = create(2);
        push(stack, &names[0]);
        push(stack, &names[1]);
        ASSERT(0 == strcmp(names[0], *(char**)getElement(stack, 0)));
        ASSERT(0 == strcmp(names[1], *(char**)getElement(stack, 1)));
}

void test_adds_structures_to_stacks(){
        Account account = {100,1000};
        stack = create(3);
        push(stack, &account);
        ASSERT(&account == *getElement(stack, 0));
        ASSERT(1 == stack->top && 3 == stack->length);
}

void test_doubles_the_length_of_stack_on_stack_full(){
    int nums[3];
    int result;
    nums[0] = 10;nums[1] = 2;nums[2] = 1;
    stack = create(3);
    push(stack, &nums[0]);
    push(stack, &nums[2]);
    push(stack, &nums[1]);
    ASSERT(3 == stack->length);
    ASSERT(push(stack, &nums[0]));
    ASSERT(6 == stack->length);
    ASSERT(4 == stack->top);
    ASSERT(10 == **(int**)getElement(stack, 3));
}


void test_removes_the_top_element_from_the_stack_integers(){
    int nums[4];
    int* result;
    nums[0] = 10;nums[1] = 42;nums[2] = 15;nums[3] = 25;
    stack = create(3);
    push(stack, &nums[0]);
    push(stack, &nums[2]);
    push(stack, &nums[1]);
    push(stack, &nums[3]);
    result = pop(stack);
    ASSERT(25 == *result);
    ASSERT(3 == stack->top);
};

void test_removes_the_top_element_from_the_stack_Strings(){
    String_256 nums[2];
    char* result;
    strcpy(nums[0], "raman");
    strcpy(nums[1], "sinu");
    stack = create(2);
    push(stack, &nums[0]);
    push(stack, &nums[1]);
    result = pop(stack);
    ASSERT(0 == strcmp("sinu", result));
    ASSERT(1 == stack->top);
};

void test_removes_structures_on_the_top_of_stacks(){
    Account account = {100,1000};
    Account* result;
    stack = create(3);
    push(stack, &account);
    ASSERT(&account == *getElement(stack, 0));
    result = pop(stack);
    ASSERT(areAccountsEqual(*result, account));
    ASSERT(0 == stack->top && 3 == stack->length);
}

void test_remove_on_empty_stack(){
        void* result;
        stack = create(5);
        result = pop(stack);
        ASSERT(NULL == result);
}

void test_gives_top_element_integers(){
        int num[4] = {10,15,20,25};
        int* result;
        stack = create(3);
        push(stack, &num[0]);
        push(stack, &num[2]);
        push(stack, &num[1]);
        push(stack, &num[3]);
        result = peek(stack);
        ASSERT(25 == *result);
        ASSERT(4 == stack->top);
};

void test_gives_the_top_stack_character(){
    char chars[4];
    char* result;
    chars[0] = 'a';chars[1] = 'b';chars[2] = 'c';chars[3] = 'd';
    stack = create(3);
    push(stack, &chars[0]);
    push(stack, &chars[2]);
    push(stack, &chars[1]);
    push(stack, &chars[3]);
    result = peek(stack);
    ASSERT('d' == *result);
    ASSERT(4 == stack->top);
};

void test_tells_the_stack_is_empty(){
    int result;
    stack = create(5);
    result = isEmpty(stack);
    ASSERT(1==result);
}

void test_tells_the_stack_is_not_empty(){
        int result;
        int num = 15;
        stack = create(5);
        push(stack, &num);
        result = isEmpty(stack);
        ASSERT(0==result);
}

void test_tells_the_stack_is_full(){
        int result;
        int num = 15;
        stack = create(1);
        push(stack, &num);
        result = isFull(stack);
        ASSERT(1==result);
}

void test_tells_the_stack_is_not_full(){
        int result;
        stack = create(4);
        result = isFull(stack);
        ASSERT(0==result);
}