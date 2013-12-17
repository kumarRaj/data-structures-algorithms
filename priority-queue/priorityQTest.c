#include "testUtils.h"
#include "priorityQ.h"

PQueue *queue;
void view_priority_queue_details(DoubleList *dlist){
    node *temp;int i;
    Queue_element *element;
    temp = dlist->head;
    for (i = 0; i < dlist->length;i++){
        element = temp->data;
        printf("-%d-\t",*(int*)element->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int comparePriority(void *element1,void *element2){
    Queue_element el1 = *(Queue_element*)element1;
    Queue_element el2 = *(Queue_element*)element2;
    // printf("here\n");
    return el1.priority - el2.priority;
}
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
void test_adds_the_element_at_the_starting_of_queue(){
    int num = 10;
    Queue_element element = {&num,5};
    queue = create_queue();
    ASSERT(enqueue(queue, &element,comparePriority));
}

void test_adds_the_element_first_having_lower_priority(){
    int numbers[] = {25,34};
    Queue_element element1 = {&numbers[0],5};
    Queue_element element2 = {&numbers[1],2};
    Queue_element first,second;
    queue = create_queue();
    ASSERT(enqueue(queue, &element1,comparePriority));
    ASSERT(enqueue(queue, &element2,comparePriority));
    first = *(Queue_element*)queue->head->data; 
    second = *(Queue_element*)queue->head->next->data; 
    ASSERT(34 == *(int*)first.data);
    ASSERT(25 == *(int*)second.data);
}
void test_adds_three_elements_in_priority_queue(){
    int numbers[] = {25,34,56};
    Queue_element element1 = {&numbers[0],5};
    Queue_element element2 = {&numbers[1],2};
    Queue_element element3 = {&numbers[2],4};
    Queue_element first,second,third;
    queue = create_queue();
    ASSERT(enqueue(queue, &element1,comparePriority));
    ASSERT(enqueue(queue, &element2,comparePriority));
    ASSERT(enqueue(queue, &element3,comparePriority));
    first = *(Queue_element*)queue->head->data; 
    second = *(Queue_element*)queue->head->next->data; 
    third = *(Queue_element*)queue->head->next->next->data; 
    ASSERT(34 == *(int*)first.data);
    ASSERT(56 == *(int*)second.data);
    ASSERT(25 == *(int*)third.data);
}
void test_remove_element_from_queue(){
    int numbers[] = {25,34,56};
    Queue_element element1 = {&numbers[0],5};
    Queue_element element2 = {&numbers[1],2};
    Queue_element element3 = {&numbers[2],4};
    Queue_element first,second,third;
    queue = create_queue();
    ASSERT(enqueue(queue, &element1,comparePriority));
    ASSERT(enqueue(queue, &element2,comparePriority));
    ASSERT(enqueue(queue, &element3,comparePriority));
    dequeue(queue);
    first = *(Queue_element*)queue->head->data; 
    second = *(Queue_element*)queue->head->next->data; 
    ASSERT(56 == *(int*)first.data);
    ASSERT(25 == *(int*)second.data);
}