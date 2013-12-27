#include "hashmap.h"
#include "include/dList.h"
#include "include/ArrayList.h"
#include "internalHashMap.h"
#include <stdlib.h>
#include <stdio.h>
HashMap HashMap_createMap(hash hashFunc, compare compareKey){
	ArrayList buckets = ArrayList_create(10);
	HashMap map;
	map.buckets = malloc(sizeof(ArrayList));
	*(ArrayList*)map.buckets = buckets;
	map.cmp = compareKey;
	map.hashFunc = hashFunc;
	return map;
}
HashNode* HashMap_getHashNode(void *key, void *value){
	HashNode *hash_node = malloc(sizeof(HashNode));
	hash_node->key = key;
	hash_node->value = value;
	return hash_node;
}
int HashMap_put(HashMap *map, void *key, void *value){
	DoubleList *list;
	DoubleList newList;
	HashNode *hash_node;
	int bucketNumber;
	bucketNumber = (map->hashFunc(key)) % 10;
	hash_node = HashMap_getHashNode(key, value);
	list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
	if(!list){
		newList = dList_create();
		dList_insert(&newList, newList.length, hash_node);
	}
	else dList_insert(&newList, newList.length, hash_node);
	return 1;
}
void* HashMap_get(HashMap *map, void *key){
	DoubleList newList;
	int bucketNumber;
	DoubleList *list;
	bucketNumber = (map->hashFunc(key)) % 10;
	list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
	if(!list)	return NULL;
	return dList_getData(*list, key, map->cmp);
}