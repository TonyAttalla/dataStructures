/*******************************************************************************
 * File: Worksheet23.c
 * Authors: Group 15
 * Description:
 *
 * From Worksheet 23:
 *
 * An iterator for the dynamic array will work by maintaining an index into the array 
 * representing the current location. This value is initially zero, and must be incremented by 
 * either the function hasNext or the function next? Think about this for a moment. Which 
 * one makes more sense? Then think carefully about the third function, remove. You must 
 * ensure that when the loop continues after a remove the next value following the removed 
 * element is not skipped. You can assume you have access to the dynArrayRemoveAt 
 * function you wrote in Lesson 21. 
 *  
 *  void dynArrayRemoveAt (struct dynArray * dy, int index);
 ******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../header/Worksheet21.h"
#include "../header/Worksheet23.h"
#include "../header/Worksheet14.h"      //DynArr struct definition was buried via WS21->WS14.  This connects directly to WS14 and fixes the definition issue.

void dynArrayIteratorInit (struct DynArr *da, struct dynArrayIterator *itr) { 
    assert(da);                         //Ensure DynArr is properly initialized.
    
    /*  I think this function is meant to send an existing DynArr and an iterator 
        pointer in order to initialize the iterator.  I think we just need to 
        assign the pointer and set currentIndex to 0.
    itr = malloc(sizeof(struct dynArrayIterator));
    if(!da) //dynamic array doesn't already exist. Delete this? Assume already initialized?
        initDynArr(da, 32); //initDynArr included from Worksheet14.c
    assert(da);*/
    
    itr->da = da;
    itr->currentIndex = 0;
} 

/*  Asserts iterator pointer is valid, current index is greater then zero, and
    returns 0 if next index value is greater than size */
int dynArrayIteratorHasNext (struct dynArrayIterator *itr) { 
    assert(itr);                                //iterator is not null
    assert(itr->currentIndex >= 0);             //index is not negative
    
    //We don't need this because of the next conditional
    //assert(itr->currentIndex <= itr->da->size);  //index within size range
    
    if(itr->currentIndex < itr->da->size) //there is at least one more position in array
        return 1;
    else
        return 0;
} 

/*  Asserts iterator pointer is valid, current index is greater than zero, less
    than the size of the dynamic array and returns the value stored at the 
    current location in the array and increments currentIndex to the next value.
    */
TYPE dynArrayIteratorNext (struct dynArrayIterator *itr) { 
    assert(itr);                                //iterator is not null
    assert(itr->currentIndex >= 0);             //index is not negative
    assert(itr->currentIndex < itr->da->size);  //index within size range
    
    return itr->da->data[itr->currentIndex++];
} 

/*  Asserts iterator pointer is valid, current index is greater than zero, less
    than the size of the dynamic array, removes the element at the currentIndex
    location and moves the currentIndex pointer back so it points to the new
    current index, relative to the new state of the dynamic array. */
void dynArrayIteratorRemove (struct dynArrayIterator *itr) { 
    assert(itr);                                //iterator is not null
    assert(itr->currentIndex >= 0);             //index is not negative
    assert(itr->currentIndex < itr->da->size);  //index within size range
    
    _dynArrayRemoveAt(itr->da, itr->currentIndex);
    itr->currentIndex--;    //Decrement the index to prevent jumping elements in the shifted array
} 
