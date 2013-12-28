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
	char value[50];
} Intern;
Intern prateek = {15386,"Prateek"};
Intern raj = {15388,"Raj"};
Intern sumit = {15432,"Sumit"};

void test_add_an_element_to_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual);
	ASSERT(HashMap_put(&map, &raj.key, &raj.value));
	printf("%s\n", (char*)HashMap_get(&map, &raj.key));
	// ASSERT(0 == strcmp();
}