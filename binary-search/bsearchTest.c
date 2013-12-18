#include "testUtils.h"
#include "bsearch.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compareInt(const void* key,const void* element){
    return ( *(int*)key -  *(int*)element );
}
void test_to_search_in_integer_array_element_less_than_mid(){
    int arr[4]={12,22,34,35};
    int key = 12;
    int result = *(int*)bsearch(&key, arr, 4,sizeof(int), compareInt);
    ASSERT(12 == result);
}
void test_to_search_integer_array_element_on_mid(){
    int arr[3]={12,22,34};
    int key = 12;
    int result = *(int*)bsearch(&key, arr, 3,sizeof(int), compareInt);
    ASSERT(12 == result);
}
void test_to_search_integer_array_element_greater_than_mid(){
    int arr[]={12,132,134,345,678};
    int key = 345;
    int result = *(int*)bsearch(&key, arr, 5,sizeof(int), compareInt);
    ASSERT(345 == result);
}
int compareDouble(const void* key,const void* element){
    return ( *(double*)key -  *(double*)element );
}
void test_to_search_double_in_array(){
    double arr[]={1,2,3,4,5};
    double key = 5;
    double result = *(double*)bsearch(&key, arr, 5, sizeof(double), compareDouble);
    ASSERT(5 == result);
}
void test_to_search_element_which_is_not_present_in_double_array_(){
    double arr[] = {1.2,2.2,3.2,4.2,5.2};
    double key = 6.2;
    ASSERT(NULL == (double*)bsearch(&key, arr, 5, sizeof(double), compareDouble));
}