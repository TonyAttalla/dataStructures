#ifndef Deque
#define TYPE int 
#define EQ(a, b) (a == b) 
#endif

#include <assert.h>
#include <stdlib.h>
#include "Deque.h"

void _dequeSetCapacity (struct deque *v, int newCap) { 
 int i, j = v->beg; 
 
 /* Create a new underlying array*/ 
 TYPE *newData = (TYPE*)malloc(sizeof(TYPE)*newCap); 
 assert(newData != 0); 
 
 /* copy elements to it */ 
 for(i = 0; i < v->size; i++){ 
    newData[i] = v->data[j]; 
    j = j + 1; 
    if(j >= v->capacity) 
        j = 0; 
 } 
 
 /* Delete the oldunderlying array*/ 
 free(v->data); 
 /* update capacity and size and data*/ 
 v->data = newData; 
 v->capacity = newCap; 
 v->beg = 0; 
} 
 
void dequeFree (struct deque *d) { 
 free(d->data); d->size = 0; d->capacity = 0; d->beg = 0;
}
 
void dequeInit (struct deque *d, int initCapacity) { 
 d->size = d->beg = 0; 
 d->capacity = initCapacity; 
 assert(initCapacity > 0); 
 d->data = (TYPE *) malloc(initCapacity * sizeof(TYPE)); 
 assert(d->data != 0); 
} 
 
int dequeSize (struct deque *d) { return d->size; } 
 
void _dequeDoubleCapacity (struct deque *d){
    _dequeSetCapacity(d, d->capacity * 2);          //I added this implementation - RK 01/22/14
}

void dequeAddFront (struct deque *d, TYPE newValue) { 
 if(d->size >= d->capacity) 
     _dequeDoubleCapacity(d);   //Made use of existing function - RK 01/22/14
    
 if(d->beg){ //data begins at a place other than 0, we can add data to d->beg-1
     d->beg--; //data begins one space earlier  
     d->size++;
     d->data[d->beg] = newValue;
 }
 else{ //data begins at 0, add new value to last position in array
     d->beg = d->capacity-1; //data now begins at end of array
     d->size++;
     d->data[d->beg] = newValue;
 }
} 
 
void dequeAddBack (struct deque *d, TYPE newValue) { 
 if (d->size >= d->capacity) 
     _dequeDoubleCapacity(d); 
 
 if(d->beg + d->size > d->capacity){ //need to wrap
     d->data[d->beg + d->size - d->capacity] = newValue;
     d->size++;
 } 
 else{ //no need to wrap
     d->data[d->beg + d->size] = newValue; //add data after range
     d->size++;
 }
}

TYPE dequeFront (struct deque *d) { 
 assert(d->size);
 return d->data[d->beg];
} 
 
TYPE dequeBack (struct deque *d) { 
    assert(d->size);
    if (d->beg + d->size > d->capacity){
        //need to wrap
        return d->data[d->beg + (d->size - 1) - d->capacity];
    }
    else
        return d->data[d->beg + d->size -1];
} 
 
 
 
void dequeRemoveFront (struct deque *d) { 
    if(d->beg == d->capacity -1) {
        //need to wrap
        d->beg = 0;
        d->size--;
    }
    
    else{
        //don't need to wrap
        d->beg++;
        d->size--;
    }
} 
 
void dequeRemoveBack (struct deque *d) { 
    d->size--;        
} 
