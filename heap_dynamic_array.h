/* 	heap_dynamic_array.h : Dynamic Array implementation for use with heap on worksheet 33. */

#ifndef HEAP_DYNAMIC_ARRAY_H
#define HEAP_DYNAMIC_ARRAY_H

#ifndef TYPE
#define TYPE int
#endif

#ifndef EQ
#define EQ(a, b) (a ==b)
#endif

typedef struct dyArray dyArray;

/* function used to compare two TYPE values to each other, define this in your heap_compare.c file */
int compare(TYPE left, TYPE right);

/* Dynamic Array Functions */
struct dyArray *dyArrayCreate(int cap);
void dyArrayDelete(struct dyArray *v);

int dyArraySize(struct dyArray *v);

void dyArrayAdd(struct dyArray *v, TYPE val);
TYPE dyArrayGet(struct dyArray *v, int pos);
void dyArrayPut(struct dyArray *v, int pos, TYPE val);
void dyArraySwap(struct dyArray *v, int i, int  j);
void dyArrayRemoveAt(struct dyArray *v, int idx);

void printArray(struct dyArray *v, int last); //for debug


#endif //HEAP_DYNAMIC_ARRAY_H
