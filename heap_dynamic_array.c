/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
|   Course:             CS 261 - 400, Ehsan
|   Assignment:         Worksheet 33
|   Date:               February 17, 2014
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

/*	dynamicArray.c: Dynamic Array implementation. */
#include <assert.h>
#include <stdlib.h>
#include "heap_dynamic_array.h"

struct dyArray{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity of the array */
};

/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/
void dyArrayInit(dyArray *v, int capacity)
{
	assert(capacity > 0);
	assert(v!= 0);
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;	
}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.		
*/
dyArray* dyArrayCreate(int cap)
{
	dyArray *r = (dyArray *)malloc(sizeof( dyArray));      //Variable decalaration must occur before asserting
	assert(cap > 0);
	assert(r != 0);
	dyArrayInit(r,cap);
	return r;
}

/* Deallocate data array in dynamic array. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void dyArrayFree(dyArray *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void dyArrayDelete(dyArray *v)
{
	dyArrayFree(v);
	free(v);
}

/* Resizes the underlying array to be the size cap 

	param: 	v		pointer to the dynamic array
	param:	cap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
*/
void _dynArrSetCapacity(dyArray *v, int newCap)
{	
	int i = 0;
   struct dyArray newArr;
   
   dyArrayInit(&newArr, newCap);
   
   /* Copy old dyArray to new dyArray */
   for(i = 0; i < v->capacity; i++){	
	newArr.data[i] = v->data[i];
	newArr.size++;
   }

   //Release old dyArray
   dyArrayFree(v);
   
   //Point to new dyArray
   *v = newArr;	
}

/* Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array
*/
int dyArraySize(dyArray *v)
{
	return v->size;
}

/* 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/
void dyArrayAdd(dyArray *v, TYPE val)
{
	/* Check to see if a resize is necessary */
	if(v->size >= v->capacity)
		_dynArrSetCapacity(v, 2 * v->capacity);
	
	v->data[v->size] = val;
	v->size++;	
}

/*	Get an element from the dynamic array from a specified position
	
	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/
TYPE dyArrayGet(dyArray *v, int pos)
{
   assert((pos < v->size) && (pos >= 0));
   return v->data[pos];
}

/*	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert 
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
*/
void dyArrayPut(dyArray *v, int pos, TYPE val){
   //Index check
   assert((pos < v->size) && (pos >= 0));
   
   //Insert new value
   v->data[pos] = val;
}

/*	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/
void dyArraySwap(dyArray *v, int i, int  j)
{
   TYPE tempValue;
   
   //Index checks
   assert((i < v->size) && (i >= 0));
   assert((j < v->size) && (j >= 0));
   
   tempValue = v->data[i];
   v->data[i] = v->data[j];
   v->data[j] = tempValue;
}

/*	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one
*/
void dyArrayRemoveAt(dyArray *v, int idx)
{
   int i = 0;
   
   //Index check
   assert((idx < v->size) && (idx >= 0));
   
   //Overwrite each element with value from successive element starting at index
   for(i = idx; i < v->size - 1; i++)     //Size - 1 is the index for the last data in array
      v->data[i] = v->data[i + 1];
   //Set last element data to NULL
   v->data[v->size - 1] = 0;    //Size - 1 is the index for the last data in array
   
   //Decrement size
   v->size--;
}