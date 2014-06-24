#include <stdlib.h>
#include <assert.h>
#include "../header/Worksheet14.h"

/* Initializes the dynamic array and associated descriptors in struct DynArr */
void initDynArr(struct DynArr *v, int capacity){
	v->data = malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	
	v->size = 0;
	v->capacity = capacity;

}	

/* Frees memory from dynamic array and sets struct DynArr descriptors to NULL */
void freeDynArr(struct DynArr *v){
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Returns size of DynArr. 
 * NOTE: changed return type to int from void */
int sizeDynArr( struct DynArr *v){
	return v->size;
}

/* Doubles the capacity of the DynArr */
void _setCapacityDynArr(struct DynArr *v, int newCap){
   int i = 0;
   struct DynArr newArr;
   
   initDynArr(&newArr, newCap);
   
   /* Copy old DynArr to new DynArr */
   for(i = 0; i < v->capacity; i++){	
	newArr.data[i] = v->data[i];
	newArr.size++;
   }

   //Release old DynArr
   freeDynArr(v);
   
   //Point to new DynArr
   *v = newArr;
}

/* Adds value to the end of the DynArr and increments size desciptor */
void addDynArr(struct DynArr *v, TYPE val){
	/* Check to see if a resize is necessary */
	if(v->size >= v->capacity)
		_setCapacityDynArr(v, 2 * v->capacity);
	
	v->data[v->size] = val;
	v->size++;	
}

/* Returns data in DynArr at argument position
 * Includes index verification */
TYPE getDynArr (struct DynArr * da, int position) {
   assert((position < da->size) && (position >= 0));
   return da->data[position];
}

/* Overwrites data in DynArr at argument position with value
 * Includes index verification */
void putDynArr(struct DynArr * da, int position, TYPE value) {
   int i = 0;
   
   //Index check
   assert((position < da->size) && (position >= 0));
   
   //Insert new value
   da->data[position] = value;
}

/* Swaps data between two positions in DynArr
 * Includes index verification */
void swapDynArr (struct DynArr * da, int i, int j){
   TYPE tempValue;
   
   //Index checks
   assert((i < da->size) && (i >= 0));
   assert((j < da->size) && (j >= 0));
   
   tempValue = da->data[i];
   da->data[i] = da->data[j];
   da->data[j] = tempValue;
}

/* Removes elements at index position and shifts array accordingly
 * Includes index verification and size decrement. */
void removeAtDynArr (struct DynArr * da, int index){
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
