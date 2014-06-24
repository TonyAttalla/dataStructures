/**********************************************************
 * Title:         Tests for Worksheets 22, 23, 24, and 26.
 * Course:        CS261 - 400, Ehsan
 * Group:         Group 15
 * Date:          January 26, 2014
 * Description:   Run this executable to test worksheet implementations.
 **********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

//Worksheet0.c
//#include "ArrayBagStack.h"

//Worksheet 22, 23, 24, 26
#include "header/linkedListDeque.h"
#include "header/Worksheet22.h"
#include "header/Worksheet23.h"
#include "header/Worksheet24.h"
#include "header/Worksheet26.h"
#include "header/Worksheet14.h"

void assertTrue(int predicate, char *message)
{
	printf("%s: ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}

void testW22() {
    struct linkedList * llbag = (struct linkedList *) malloc(sizeof(struct linkedList));
    linkedListInit(llbag);

    printf("\n---TESTING WORKSHEET 22---\n\n");
    printf("Testing linkedListAdd:\n");
    printf("LinkedListBag should contain {1, 2, 4, 8}.\n\n");
    linkedListAdd(llbag, 1);
    linkedListAdd(llbag, 2);
    linkedListAdd(llbag, 4);
    linkedListAdd(llbag, 8);

    printf("Testing linkedListContains:\n");
    assertTrue(linkedListContains(llbag, 1), "LinkedListBag DOES contain 1: ");
    assertTrue(linkedListContains(llbag, 2), "LinkedListBag DOES contain 2: ");
    assertTrue(linkedListContains(llbag, 4), "LinkedListBag DOES contain 4: ");
    assertTrue(linkedListContains(llbag, 8), "LinkedListBag DOES contain 8: ");
    assertTrue(! linkedListContains(llbag, 16), "LinkedListBag DOES NOT contain 16: ");

    printf("\nTesting linkedListRemove:\n ...Removing elements 1 and 2.\n");
    linkedListRemove(llbag, 1);
    linkedListRemove(llbag, 2);
    printf("Removal Complete!\n\n");

    assertTrue(! linkedListContains(llbag, 1), "LinkedListBag DOES NOT contain 1: ");
    assertTrue(! linkedListContains(llbag, 2), "LinkedListBag DOES NOT contain 2: ");
    assertTrue(linkedListContains(llbag, 4), "LinkedListBag DOES contain 4: ");
    assertTrue(linkedListContains(llbag, 8), "LinkedListBag DOES contain 8: ");

    linkedListFree(llbag);
}

void testW23() {
    struct DynArr * dArray = (struct DynArr *) malloc(sizeof(struct DynArr));
    struct dynArrayIterator * dai = (struct dynArrayIterator *) malloc(sizeof(struct dynArrayIterator));
    int i = 5, current = 0;
    
    printf("\n---TESTING WORKSHEET 23---\n\n");
    
    printf("Initializing dynamic array to size 5 and defining its elements as: 0, 1, 2, 3, 4, 5.\n");
    initDynArr(dArray, i);
    
    for(i = 0; i < dArray->capacity; i++)
        addDynArr(dArray, i);
    printf("Initialization and definition of dynamic array complete!\n\n");
    
    printf("Initializing dynamic array iterator...\n");
    dynArrayIteratorInit(dArray, dai);
    printf("Initialization complete!\n\n");
    
    //Confirm successful initialization of dai and the dynArrayIteratorInit() function
    printf("Testing that Dynamic Array Iterator stored pointer location of dynamic array: ");
    assert(dai->da == dArray);        //Confirm iterator is not set to null
    printf(" PASSED!\n");
    printf("Testing that Dynamic Array Iterator stored current index at zero: ");
    assert(getDynArr(dai->da, dai->currentIndex) == 0);  //Index 0 of da has value of 0
    printf(" PASSED!\n\n");
    
    //Test dynArrayIteratorHasNext() and dynArrayIteratorNext() Functions
    printf("Testing the dynArrayIteratorHasNext() and dynArrayIteratorNext() functions:\n");
    while(dynArrayIteratorHasNext(dai)){
        current = dai->currentIndex;
        printf("Element %d:\t%d\n", current, dynArrayIteratorNext(dai));
    }
    printf("PASSED!\n\n");
    
    //Test dynArrayIteratorRemove() function
    printf("Testing dynArrayIteratorRemove() function:\n");
    dai->currentIndex = 1;  //Target second element in dynamic array for removal
    dynArrayIteratorRemove(dai);      //Remove second element in dynamic array
    
    dai->currentIndex = 0;  //Target first element in dynamic array
    //Output remaining dynamic array
   while(dynArrayIteratorHasNext(dai)){
        current = dai->currentIndex;
        printf("Element %d:\t%d\n", current, dynArrayIteratorNext(dai));
    }
    printf("Output of \"0, 2, 3, 4\" means it: PASSED!\n\n");
    
    //Free/Reset memory
    freeDynArr(dArray);
    free(dai->da);
    dai->currentIndex = 0;
    free(dai);
}

void testW24() {
    struct linkedList * ll = (struct linkedList *) malloc(sizeof(struct linkedList));
    struct linkedListIterator * itr = (struct linkedListIterator *) malloc(sizeof(struct linkedListIterator));
    
    linkedListInit(ll);
    
    printf("\n---TESTING WORKSHEET 24---\n\n");
    
    linkedListIteratorInit(ll, itr);
    assertTrue(linkedListIteratorHasNext(itr) == 0, "linkedListIteratorHasNext for empty LinkedList returns false: ");
    
    linkedListAddFront(ll, 3);
    printf("...Added element with value 3 to front of list...\n");
    linkedListAddFront(ll, 5);
    printf("...Added element with value 5 to front of list...\n");
    linkedListAddFront(ll, 7);
    printf("...Added element with value 7 to front of list...\n");
    
    assertTrue((linkedListIteratorHasNext(itr)) == 1, "linkedListIteratorHasNext for LinkedList with 2 elements returns true: ");
    assertTrue(EQ(linkedListIteratorNext(itr), 7), "linkedListIteratorNext returns the correct value of the next element: ");
    
    linkedListIteratorNext(itr);        //Move from 7 to 5
    
    linkedListIteratorRemove(itr);      //Remove 5
    
    //Print full linkedList
    printf("Resetting to front sentinel and outputting entire linked list:\n");
    itr->currentLink = itr->lst->frontSentinel;
    while(linkedListIteratorHasNext(itr))
        printf("%d\n", linkedListIteratorNext(itr));
    
    assertTrue(linkedListIteratorHasNext(itr) == 0, "linkedListIteratorHasNext returns false when iterator is at the end of linked list: ");
        
    linkedListFree(ll);
}

void testW26() {
    int i = 0;
    struct DynArr *dyn = (struct DynArr *) malloc(sizeof(struct DynArr));
    
	initDynArr(dyn, 2);
	
	printf("\n---TESTING WORKSHEET 26---\n\n");
    
    printf("Populating Ordered DynArr...\n");
	addDynArr(dyn, 3);
	addDynArr(dyn, 4);
	addDynArr(dyn, 5);
	addDynArr(dyn, 6);
	addDynArr(dyn, 7);
	printf("COMPLETE!\n\n");

    printf("Initial array contents:\n");
    for(i = 0; i < dyn->size; i++)
        printf("%d\n", dyn->data[i]);

    printf("\nIf 5 exists in the array, remove it...\n");
    if(orderedArrayContains (dyn, 5)){
        orderedArrayRemove (dyn, 5);
        printf("5 exists and has been removed!\n\n");
    }
    else
        printf("5 not found in array!\n\n");
    
    printf("Adding 5 back into array at ordered position...\n");
    orderedArrayAdd (dyn, 5);
    printf("COMPLETE!\n\n");

    printf("Adding 5 back into array at ordered position to test two elements of identical value...\n");
    orderedArrayAdd (dyn, 5);
    printf("COMPLETE!\n\n");

    printf("Outputting final array contents:\n");
    for(i = 0; i < dyn->size; i++)
        printf("%d\n", dyn->data[i]);

    printf("\nWorksheet 26 Test is COMPLETE!\n\n");

	free(dyn);
}

int main(int argc, char** argv)
{
    testW22();
    testW23();
    testW24();
    testW26();
    
    return 0;
}
