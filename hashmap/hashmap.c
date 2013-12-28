#include "hashmap.h"
#include "include/dList.h"
#include "include/ArrayList.h"
#include "internalHashMap.h"
#include <stdlib.h>
#include <stdio.h>
HashMap HashMap_createMap(hash hashFunc, compare compareKey){
	ArrayList buckets = ArrayList_create(10);
	HashMap map;
	int i;
	DoubleList list;
	map.buckets = malloc(sizeof(ArrayList));
	*(ArrayList*)map.buckets = buckets;
	map.cmp = compareKey;
	(*(ArrayList*)map.buckets).length = 10;
	map.hashFunc = hashFunc;
	for(i=0;i<10;i++){
		((ArrayList*)map.buckets)->base[i] = malloc(sizeof(DoubleList));
		list = dList_create();
		*(DoubleList*)(((ArrayList*)map.buckets)->base[i]) = list;
	}
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
	HashNode *hash_node;
	int bucketNumber;
	bucketNumber = (map->hashFunc(key)) % 10;
	hash_node = HashMap_getHashNode(key, value);
	list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
	dList_insert(list, list->length, hash_node);
	return 1;
}
void* HashMap_get(HashMap *map, void *key){
	int bucketNumber;
	DoubleList *list;
	HashNode *hash_node;
	bucketNumber = (map->hashFunc(key)) % 10;
	list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
	hash_node = dList_getData(*list, key, map->cmp);
	return hash_node->value;
}