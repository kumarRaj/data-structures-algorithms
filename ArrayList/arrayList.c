#include "arrayList.h"
#include <stdlib.h>
#include "include/iterator.h"
ArrayList ArrayList_create(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
}

void ArrayList_shiftElementsRightIfNeeded(ArrayList *list, int index) {
	int i;
	for (i = list->length - 1; i >= index; i--) {
		list->base[i+1] = list->base[i];
	}
}

int ArrayList_isFull(ArrayList *list) {
	return list->length == list->capacity;
}

void ArrayList_increaseCapacity(ArrayList *list) {
	int targetCapacity;
	if (ArrayList_isFull(list)) {
		targetCapacity = list->capacity * 2;
		list->base = realloc(list->base, targetCapacity * sizeof(void*));
		list->capacity = targetCapacity;
	}	
}

int ArrayList_insert(ArrayList *list, int index, void* data) {
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;

	ArrayList_increaseCapacity(list);
	ArrayList_shiftElementsRightIfNeeded(list, index);

	list->base[index] = data;
	list->length++;

	return 1;
}
int ArrayList_add(ArrayList *list,void *data){
	return ArrayList_insert(list, list->length, data);
}
void ArrayList_shiftElementsLeftIfNeeded(ArrayList *list, int index) {
	int i;
	for(i = index;i < list->length-1;i++){
        list->base[i] = list->base[i+1];
    }
}

int ArrayList_remove(ArrayList *list,int index){
	int i;
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;
    ArrayList_shiftElementsLeftIfNeeded(list, index);
    list->length--;
    return 1;        
}
void* ArrayList_get(ArrayList *list, int index) {
	if (index < 0 || index >= list->length) return NULL;
	return list->base[index];
}
int ArrayList_search(ArrayList *list, void *searchElement, compare cmpFun){
	int i;
	for(i = 0;i < list->length;i++){
		if(0 == cmpFun(searchElement,list->base[i]))
			return i;
	}
	return -1;
}
int ArrayList_hasNextForArrayList(Iterator* it){
    ArrayList *list = it->list;
    if(list->length <= it->position) return 0;
    return 1;
}
void* ArrayList_getNextDataForArrayList(Iterator* it){
	ArrayList* list = it->list;
    if(!ArrayList_hasNextForArrayList(it)) return NULL;
    return list->base[it->position++];
}
Iterator ArrayList_getIterator(ArrayList* list){
    Iterator it;
    it.list = list;
    it.position = 0;
    it.hasNext = &ArrayList_hasNextForArrayList;
    it.next = &ArrayList_getNextDataForArrayList;
    return it;
}
void ArrayList_iterate(ArrayList list, ForEach* forEach){
    int index;
    for(index = 0;index < list.length ;index++){
        forEach(list.base[index]);
    }
}

void ArrayList_dispose(ArrayList *list) {
	free(list->base);
}