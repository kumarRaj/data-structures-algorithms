#include "testUtils.h"
#include "bubbleSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt (void* first, void* second){
        return (*(int*)first - *(int*)second);
}

int compareChar(void* first, void* second){
        return (*(char*)first - *(char*)second);
}
int areArrayEqual(void** a,void** b, int length){
    int i;
    for(i = 0;i<length;i++){
        if(a[i] != b[i])
            return 0;
    }
    return 1;
}
void test_sorts_integers(){
    int nums[5] = {15,110,120,249,259};
    void* ptrs[5] = {&nums[4],&nums[3],&nums[2],&nums[1],&nums[0]};
    void* expected[5] = {&nums[0],&nums[1],&nums[2],&nums[3],&nums[4]};
    bubbleSort(ptrs, 5, compareInt);
    ASSERT(areArrayEqual(ptrs, expected, 5));
}
void test_sorts_characters(){
    char chars[] = {'a','b','d','v','x'};
    void* ptrs[] = {&(chars[3]),&(chars[1]),&(chars[4]),&(chars[2]),&(chars)};
    void* expected[] = {&(chars[0]),&(chars[1]),&(chars[2]),&(chars[3]),&(chars[4])};
    bubbleSort(ptrs, 5, compareChar);
    ASSERT(areArrayEqual(ptrs, expected, 5));
}