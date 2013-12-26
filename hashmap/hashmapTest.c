#include "testUtils.h"
#include "hashmap.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areKeyEqual(void* key1 , void* key2 ){
	return *(int*)key1 - *(int*)key2;
}
int hashFun(void *key){
	return *(int*)key;
};
typedef struct{
	int key;
	char *value;
} Intern;
const Intern prateek = {15386,"Prateek"};
const Intern raj = {15388,"Raj"};
const Intern sumit = {15432,"Sumit"};
void test_add_an_element_to_hashmap(){
	HashMap map = createMap(hashFun, areKeyEqual);
	ASSERT(put(&map, &raj.key, &raj.value));
	ASSERT(strcmp(get(&map, &raj.key),raj.value));
}