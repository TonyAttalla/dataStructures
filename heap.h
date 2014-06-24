#include "heap_dynamic_array.h"

#ifndef HEAP_H
#define HEAP_H

#ifndef TYPE
#define TYPE int 
#endif

#ifndef EQ
#define EQ(a, b) (a == b) 
#endif

#ifndef LT
#define LT(a, b) (a < b)
#endif

/* swap elements i j */
void swap (struct dyArray * v, int i, int j);

/* return index of smallest element */
int indexSmallest (struct dyArray * v, int i, int j);

TYPE heapGetFirst (struct dyArray *heap);
void HeapRemoveFirst(struct dyArray *heap);
void _adjustHeap (struct dyArray * heap, int max, int pos);
void heapAdd (struct dyArray * heap, TYPE newValue);

#endif //HEAP_H
