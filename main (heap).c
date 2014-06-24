#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
//#include "heap_dynamic_array.h"

void printArray(struct dyArray *v, int last){ //print up to last
    int i;
    for(i=0; i <= last; i++){
        printf("%d ", dyArrayGet(v, i));
    }
}

int main(int argc, char** argv){
    struct dyArray *v;
    int capacity, i;
    TYPE temp;
    printf("What size heap shall we build?\n");
    scanf("%d", &capacity);
    v = dyArrayCreate(capacity);
    //dyArrayInit(v, capacity);
    for (i = 0; i < capacity; i++){
        printf("Enter a value for element %d\n>", i);
        scanf("%d", &temp);
        heapAdd (v, temp);
        printf("current array: ");
        printArray(v, i);
        printf("\n");
    }
    
    printf("Printing current dyArray\n");
    printArray(v, capacity-1);
    printf("\n");
    
    printf("Popping elements in order\n");
    for(i=0; i< capacity-1; i++){
        printf("Popping %d\n", heapGetFirst(v));
        HeapRemoveFirst(v);
        printf("\tCurrent array after popping: ");
        printArray(v, capacity-2-i);
        printf("\n");
    }
    
    return 0;
}
