#include "../header/Worksheet16.h"
#include "../header/Worksheet14.h"
#include <stdlib.h>
#include <assert.h>

/* Adds value e to end of DynArr */
void pushDynArr(struct DynArr * v, TYPE e){
   addDynArr(v, e);
}

/* Removes last value in DynArr */
void popDynArr(struct DynArr * v){
   removeAtDynArr(v, v->size - 1);  //Size - 1 is last element in array
}

/* Reads the last value in DynArr */
TYPE topDynArr(struct DynArr * v){
   TYPE temp;
   
   temp = v->data[v->size - 1];    //Size - 1 is last element in array
      
   return temp;
}

/* Boolean return determining if DynArr is empty
 * TRUE:    DynArr is empty
 * FALSE:   DynArr is not empty */
int isEmptyDynArr(struct DynArr * v){
   if(v->size == 0)
      return 1;
   else
      return 0;
}
