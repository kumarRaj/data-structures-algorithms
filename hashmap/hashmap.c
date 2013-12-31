#include "hashmap.h"
#include "include/dList.h"
#include "include/ArrayList.h"
#include "internalHashMap.h"
#include <stdlib.h>
#include <stdio.h>
void createListForEachBucket(void *bucket){
	DoubleList list;
	list  = dList_create();
	*(DoubleList*)bucket = list;
}
HashMap HashMap_createMap(hash hashFunc, compare compareKey,int capacity){
	HashMap map;
	int i;
	ArrayList buckets = ArrayList_create(capacity);
	map.buckets = malloc(sizeof(ArrayList));
	*(ArrayList*)map.buckets = buckets;
	map.cmp = compareKey;
	map.hashFunc = hashFunc;
	map.capacity = capacity;
	for(i = 0;i < capacity;i++)
		ArrayList_add(map.buckets, malloc(sizeof(DoubleList)));
	ArrayList_iterate(*(ArrayList*)map.buckets, createListForEachBucket);
	return map;
}
HashNode* HashMap_createHashNode(void *key, void *value){
	HashNode *hash_node = malloc(sizeof(HashNode));
	hash_node->key = key;
	hash_node->value = value;
	return hash_node;
}
int j =0;
void rehash(HashMap* map){
    void *key,*value;
    int i,resizeLength = map->capacity * 2;
    Iterator Keys = HashMap_keys(map);
    // printf("here %d\n",j++);
    for(i = map->capacity;i < resizeLength;i++){
        ArrayList_add(map->buckets, malloc(sizeof(DoubleList)));
        ArrayList_iterate(*(ArrayList*)map->buckets, createListForEachBucket);
    }
    map->capacity = resizeLength;    
    while(Keys.hasNext(&Keys)){
        key = Keys.next(&Keys);
        value = HashMap_get(map, key);
        HashMap_remove(map , key);
        HashMap_put(map, key, value);
    }
}

int HashMap_put(HashMap *map, void *key, void *value){
	DoubleList *list;
	HashNode *hash_node;
	int bucketNumber;
	bucketNumber = (map->hashFunc(key)) % map->capacity;
	hash_node = HashMap_createHashNode(key, value);
	list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
	if(HashMap_get(map, key))
		HashMap_remove(map, key);
	if(list->length == 2) rehash(map);
	dList_insert(list, list->length, hash_node);
	return 1;
}
void* HashMap_get(HashMap *map, void *key){
	int bucketNumber;
	DoubleList *list;
	Iterator it;
	HashNode *hash_node;
	bucketNumber = (map->hashFunc(key)) % map->capacity;
	list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
	it = dList_getIterator(list);
	while(it.hasNext(&it)){
		hash_node = it.next(&it);
		if(0 == map->cmp(key,hash_node->key))
			return hash_node->value;
	}	
	return NULL;
}
int HashMap_remove(HashMap* map, void* key){
	int bucketNumber,index = 0;
	DoubleList *list;Iterator it;
	HashNode *hash_node;
	bucketNumber = (map->hashFunc(key)) % map->capacity;
	list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
	it = dList_getIterator(list);
	while(it.hasNext(&it)){
		hash_node = it.next(&it);
		if(0 == map->cmp(hash_node->key,key))
		 	break;	
		index++;
	}
	if(index == list->length)
		return 0;
	return dList_delete(list, index);
}

Iterator HashMap_keys(HashMap *map){
	Iterator Arrayiterator = ArrayList_getIterator(map->buckets);
	Iterator listIterator;
	HashNode hash_node;
	DoubleList *dList = malloc(sizeof(DoubleList));
	while(Arrayiterator.hasNext(&Arrayiterator)){
		listIterator = dList_getIterator(Arrayiterator.next(&Arrayiterator));
		while(listIterator.hasNext(&listIterator)){
			hash_node = *(HashNode*)listIterator.next(&listIterator);
			dList_insert(dList, dList->length, hash_node.key);
		}
	}
	return dList_getIterator(dList);
}
