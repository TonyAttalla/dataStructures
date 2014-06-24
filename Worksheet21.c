#include "../header/Worksheet21.h"
#include "../header/Worksheet16.h"
#include "../header/Worksheet14.h"
#include <assert.h>
#include <stdlib.h>

/* Remove the value stored at position in the dynamic array */
void _dynArrayRemoveAt (struct DynArr * da, int index){
   int i = 0;
   
   //Index check
   assert((index < da->size) && (index >= 0));
   
   //Overwrite each element with value from successive element starting at index
   for(i = index; i < da->size - 1; i++)     //Size - 1 is the index for the last data in array
      da->data[i] = da->data[i + 1];
   //Set last element data to NULL
   da->data[da->size - 1] = 0;    //Size - 1 is the index for the last data in array
   
   //Decrement size
   da->size--;
}

/* Removes first instance discovered of target value "test" */
void removeDynArr (struct DynArr * da, TYPE test) {
   int i;
   for (i = 0; i < da->size; i++) {
      if (EQ(test, da->data[i])) { /* found it */
         _dynArrayRemoveAt(da, i);
         return;
      }
   }
}

/* Returns index position of first instance of target value e */
int containsDynArr (struct DynArr * da, TYPE e) {
   int i = 0;
   
   for (i = 0; i < da->size; i++)
      if (EQ(e, da->data[i])) /* found it */
         return 1;
   
   return 0;
}
