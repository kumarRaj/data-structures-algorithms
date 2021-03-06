#include "testUtils.h"
#include "hashmap.h"
#include <string.h>
#include <stdio.h>
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
Intern prateek = {15348,"Prateek"};
Intern raj = {15388,"Raj"};
Intern sumit = {15432,"Sumit"};
Intern cashis = {15428,"Kashish"};

void test_add_an_element_to_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,5);
	ASSERT(HashMap_put(&map, &raj.key, &raj.value));
	ASSERT(0 == strcmp(raj.value,(char*)HashMap_get(&map, &raj.key)));
}
void test_add_multiple_elements_to_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,5);
	ASSERT(HashMap_put(&map, &raj.key, &raj.value));
	ASSERT(HashMap_put(&map, &prateek.key, &prateek.value));
	ASSERT(HashMap_put(&map, &sumit.key, &sumit.value));
	ASSERT(0 == strcmp(raj.value,(char*)HashMap_get(&map, &raj.key)));
	ASSERT(0 == strcmp(prateek.value,(char*)HashMap_get(&map, &prateek.key)));
	ASSERT(0 == strcmp(sumit.value,(char*)HashMap_get(&map, &sumit.key)));
}
void test_get_not_found_data_in_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,5);
	ASSERT(HashMap_put(&map, &raj.key, &raj.value));
	ASSERT(NULL == HashMap_get(&map, &prateek.key));
}
void test_remove_data_from_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,5);
	ASSERT(HashMap_put(&map, &raj.key, &raj.value));
	ASSERT(1 == HashMap_remove(&map, &raj.key));
	ASSERT(NULL == HashMap_get(&map, &raj.key));
}
void test_remove_data_from_hashmap_when_data_not_present(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,5);
	ASSERT(HashMap_put(&map, &raj.key, &raj.value));
	ASSERT(0 == HashMap_remove(&map, &prateek.key));
}
void test_keys_of_hashmap_gives_all_keys_in_map(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,5);
	Iterator it;
	ASSERT(HashMap_put(&map, &raj.key, &raj.value));
	ASSERT(HashMap_put(&map, &prateek.key, &prateek.value));
	ASSERT(HashMap_put(&map, &sumit.key, &sumit.value));
	it = HashMap_keys(&map);
	ASSERT(15432 == *(int*)it.next(&it));
	ASSERT(15388 == *(int*)it.next(&it));
 	ASSERT(15348 == *(int*)it.next(&it));
}
void test_should_rehash_if_more_than_2_values_in_same_bucket(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,4);
	Iterator it;
	ASSERT(HashMap_put(&map, &raj.key, &raj.value));
	ASSERT(HashMap_put(&map, &prateek.key, &prateek.value));
	ASSERT(HashMap_put(&map, &sumit.key, &sumit.value));
	ASSERT(HashMap_put(&map, &cashis.key, &cashis.value));
	it = HashMap_keys(&map);
	ASSERT(15348 == *(int*)it.next(&it));
	ASSERT(15428 == *(int*)it.next(&it));
	ASSERT(15432 == *(int*)it.next(&it));
	ASSERT(15388 == *(int*)it.next(&it));
}