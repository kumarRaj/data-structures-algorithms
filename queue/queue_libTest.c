#include "testUtils.h"
#include "queue_lib.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
bool areEqual(Queue expectedQueue,Queue actualQueue){
	bool res = expectedQueue.length == actualQueue.length
		&& expectedQueue.rear == actualQueue.rear;
	return res;
}

Queue *newQueue;

void tearDown(){
	dispose(newQueue);
}
void test_create_integer_queue(){
	void** arr = {NULL};
	Queue expected = {arr,1,-1};
	newQueue = create(1);
	ASSERT(areEqual(expected,*newQueue));
}
void test_enqueue_on_empty_queue(){
	int num = 10;
	bool status;
	newQueue = create(3);
	status = enqueue(newQueue, &num);
	ASSERT(10 == **(int**)getElement(newQueue,0));
	ASSERT(true == status);
	ASSERT(0 == newQueue->rear);
}
void test_enqueue_on_non_empty_queue(){
	int num[] = {23,43,532};
	newQueue = create(3);
	enqueue(newQueue, num);
	enqueue(newQueue, &num[1]);
	enqueue(newQueue, &num[2]);
	ASSERT(23 == **(int**)getElement(newQueue,0));
	ASSERT(43 == **(int**)getElement(newQueue,1));
	ASSERT(532 == **(int**)getElement(newQueue,2));
	ASSERT(2 == newQueue->rear);
}
typedef struct{
	int acno;
	double balance;
} Account;
int compareAccount(Account acc1,Account acc2){
	return acc1.acno == acc2.acno && acc2.balance == acc2.balance;
}
void test_enqueue_on_putting_struct_to_queue(){
	Account acc1 = {1,10};
	Account acc2 = {55,15};
	newQueue = create(3);
	enqueue(newQueue, &acc1);
	enqueue(newQueue, &acc2);
	ASSERT(compareAccount(acc1,**(Account**)getElement(newQueue,0)));
	ASSERT(compareAccount(acc2,**(Account**)getElement(newQueue,1)));
	ASSERT(1 == newQueue->rear);
}
void test_enqueue_on_full_queue_returns_false(){
	int num = 23;
	bool status;
	newQueue = create(3);
	enqueue(newQueue, &num);
	enqueue(newQueue, &num);
	status = enqueue(newQueue, &num);
	ASSERT(true == status);
	status = enqueue(newQueue, &num);
	ASSERT(false == status);
	ASSERT(2 == newQueue->rear);
}
void test_deque_on_queue_with_values(){
	int num[] = {23,43};
	int *result;
	newQueue = create(3);
	enqueue(newQueue, num);
	enqueue(newQueue, &num[1]);
	result = dequeue(newQueue);
	ASSERT(*result == 23);
	ASSERT(0 == newQueue->rear);
}
void test_deque_on_empty_queue(){
	void *result;
	newQueue = create(3);
	result = dequeue(newQueue);
	ASSERT(result == NULL);
	ASSERT(-1 == newQueue->rear);
}
void test_deque_with_struct(){
	Account acc1 = {1,10};
	Account acc2 = {55,15};
	Account acc3 = {45,15};
	newQueue = create(3);
	enqueue(newQueue, &acc1);
	enqueue(newQueue, &acc2);
	enqueue(newQueue, &acc3);
	ASSERT(compareAccount(acc1,*(Account*)dequeue(newQueue)));
	ASSERT(compareAccount(acc2,*(Account*)dequeue(newQueue)));
	ASSERT(compareAccount(acc3,*(Account*)dequeue(newQueue)));
	ASSERT(-1 == newQueue->rear);
}
void test_isEmpty_gives_true_for_empty_queue(){
	newQueue = create(3);
	ASSERT(true == isEmpty(newQueue));
}
void test_is_not_Empty_gives_false_for_full_queue(){
	int a = 5;
	newQueue = create(3);
	enqueue(newQueue, &a);
	ASSERT(false == isEmpty(newQueue));
}
void test_isFull_gives_true_for_full_queue(){
	int a = 5;
	newQueue = create(2);
	enqueue(newQueue, &a);
	enqueue(newQueue, &a);
	ASSERT(true == isFull(newQueue));
}
void test_dequeue_is_not_Full_gives_false_for_non_full_queue(){
	newQueue = create(3);
	ASSERT(false == isFull(newQueue));
}