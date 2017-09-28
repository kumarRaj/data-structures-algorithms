#include "bubbleSort.h"

void bubbleSort(void** base, size_t totalElements, compare comp) {
    void** temp = malloc(sizeof(void*));
    int i,j,result;
    for(i = 0;i<totalElements;i++){
        for(j = 0;j<totalElements-i-1;j++){
            result = comp(base[j],base[j+1]);
            if(result > 0){
                *temp = base[j];
                base[j] = base[j+1];
                base[j+1] = *temp;
            }
        }
    }
    free(temp);
}