#include "hashmap.h"
#include "internalHashMap.h"

HashMap createMap(hash hashFunc, compare compareKey){
	HashMap map;
	return map;
}
int put(HashMap *map, const void *key, const void *value){
	return 1;
}
void* get(HashMap *map, const void *key){
	void *data = (char*)"Raj";
	printf("%s\n", (char*)data);
	return &data;
}