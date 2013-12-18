#include "testUtils.h"
#include "queue_lib.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int areEqual(Queue expectedQueue,Queue actualQueue){
    int res = expectedQueue.length == actualQueue.length
            && expectedQueue.rear == actualQueue.rear
            && expectedQueue.front == actualQueue.front;
    return res;
}
void** getAddressOfIndex(Queue *queue,int index){
    return queue->base+(index);
}
Queue circularQueue;

void tearDown(){
    dispose(circularQueue);
}
void test_create_integer_queue(){
    void** arr = {NULL};
    Queue expected = {arr,5,-1,-1};
    circularQueue = create(5);
    ASSERT(areEqual(expected,circularQueue));
    dispose(circularQueue);
}
void test_enqueue_on_empty_queue(){
    int num = 10;
    int status;
    Queue expectedQueue = {NULL,3,-1,0};
    circularQueue = create(3);
    status = enqueue(&circularQueue, &num);
    ASSERT(10 == **(int**)getAddressOfIndex(&circularQueue,0));
    // ASSERT(areEqual(expectedQueue, *circularQueue));
    ASSERT(0 == circularQueue.rear);
    ASSERT(-1 == circularQueue.front);
    ASSERT(1 == status);
    dispose(circularQueue);
}
void test_enqueue_on_queue_which_reached_end_of_queue(){
    int num[] = {10,2,5,8};
    int status;
    circularQueue = create(3);
    circularQueue.front = -1;
    circularQueue.rear = 2;
    enqueue(&circularQueue, &num[0]);
    enqueue(&circularQueue, &num[1]);
    enqueue(&circularQueue, &num[2]);
    enqueue(&circularQueue, &num[3]);
    ASSERT(8 == **(int**)getAddressOfIndex(&circularQueue,0));
    ASSERT(2 == **(int**)getAddressOfIndex(&circularQueue,1));
    ASSERT(5 == **(int**)getAddressOfIndex(&circularQueue,2));
    ASSERT(0 == circularQueue.rear);
    ASSERT(-1 == circularQueue.front);
    dispose(circularQueue);
}
void test_enqueue_on_queue_which_reached_front_of_queue(){
    int num[] = {10,2,5,8};
    int status;
    circularQueue = create(3);
    circularQueue.front = 1;
    circularQueue.rear = 0;
        status = enqueue(&circularQueue, &num[3]);
    ASSERT(0 == circularQueue.rear);
    ASSERT(1 == circularQueue.front);
    ASSERT(0 == status);
    dispose(circularQueue);
}
void test_deque_on_queue_with_values_returns_front_element(){
    int num[] = {23,43};
    int *result;
    circularQueue = create(3);
    enqueue(&circularQueue, num);
    enqueue(&circularQueue, &num[1]);
    result = dequeue(&circularQueue);
    result = dequeue(&circularQueue);
    ASSERT(*result == 43);
    // ASSERT(0 == circularQueue.front);
    dispose(circularQueue);
}
void test_deque_on_empty_queue_without_any_values_returns_null(){
    void *result;
    circularQueue = create(3);
    result = dequeue(&circularQueue);
    ASSERT(result == NULL);
    ASSERT(-1 == circularQueue.rear);
    ASSERT(-1 == circularQueue.front);
    dispose(circularQueue);
}
void test_dequeue_where_queue_reached_end_of_queue(){
    int num = 10;
    int *result;
    int status;
    circularQueue = create(3);
    circularQueue.front = 2;
    enqueue(&circularQueue, &num);
    result = dequeue(&circularQueue);
    ASSERT(10 == *result);    
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
    circularQueue = create(3);
    enqueue(&circularQueue, &acc1);
    enqueue(&circularQueue, &acc2);
    ASSERT(compareAccount(acc1,**(Account**)getAddressOfIndex(&circularQueue,0)));
    ASSERT(compareAccount(acc2,**(Account**)getAddressOfIndex(&circularQueue,1)));
    ASSERT(1 == circularQueue.rear);
    dispose(circularQueue);
}