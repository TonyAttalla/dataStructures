#include <stdlib.h>
#include <stdio.h>
#include "ArrayBagStack.h"

void initArray (struct arrayBagStack * b){
   int i = 0;

   for(i = 0; i < 100; i++)
       b->data[i] = 0;
   b->count = 0;
}

/* Bag Interface Functions */

void addArray (struct arrayBagStack * b, TYPE v) {
   b->data[b->count] = v;
   b->count++;
}

int containsArray (struct arrayBagStack * b, TYPE v){
   int i = 0;
   for(i = 0; i < b->count; i++)
      if(EQ(v, b->data[i]))
         return i + 1;
   
   return 0;
}


void removeArray (struct arrayBagStack * b, TYPE v) {
   int i = 0, j = 0;
   for(i = 0; i < b->count; i++)
      if(EQ(v, b->data[i])){
        for(j = i; j < b->count; j++)
            if(j < 99)
                b->data[j] = b->data[j + 1];
            else
                b->data[j] = 0;
         b->count--;
         return;   //Remove this line if you want to remove all instances of v instead of first instance
      }
}

int sizeArray (struct arrayBagStack * b) {
   return b->count;
}

/* Stack Interface  Functions */

void pushArray (struct arrayBagStack * b, TYPE v) {
   b->data[b->count] = v;
   b->count++;
}

TYPE topArray (struct arrayBagStack * b) {
   return b->data[b->count - 1];
}

void popArray (struct arrayBagStack * b) {
   if(b->count > 0)
      b->count--;
}

int isEmptyArray (struct arrayBagStack * b) {
   return (!(b->count));
}

//A Better Solution…

//This solution has one problem.  The arrayBagStack structure is in the .h file and therefore exposed to the users of the data structure.   
//How can we get around this problem?  Think about it…we’ll return to this question soon.

//Instead of declaring the struct in the header file, we can add a new function that includes builds the struct in the implementation file.