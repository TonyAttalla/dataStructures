/*  Group 15
    Worksheet 29
    BSTTest.c - Definitions for binary search tree */

#include "BST.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    struct BinarySearchTree * BST = (struct BinarySearchTree *) malloc(sizeof(struct BinarySearchTree));
    struct BinarySearchTree * BST2 = (struct BinarySearchTree *) malloc(sizeof(struct BinarySearchTree));
    struct BinarySearchTree * BST3 = (struct BinarySearchTree *) malloc(sizeof(struct BinarySearchTree));

    int i = 0, numElements = 10;
    
    /* Initialize the three BST's */
    printf("Initializing BST...");
    initBST(BST);
    printf("COMPLETE!\n");
    
    printf("Initializing BST2...");
    initBST(BST2);
    printf("COMPLETE!\n");

    printf("Initializing BST3...");
    initBST(BST3);
    printf("COMPLETE!\n\n");

    /*  Add identical values to three BST's (BST 2 and 3 are for testing 
        equalsBST function) */
    printf("Adding 10 unordered elements into BST...");
    addBST(BST, 45);
    addBST(BST, 67);
    addBST(BST, 22);
    addBST(BST, 100);
    addBST(BST, 13);
    addBST(BST, 11);
    addBST(BST, 64);
    addBST(BST, 30);
    addBST(BST, 12);
    addBST(BST, 14);
    printf("COMPLETE!\n");
    
    printf("Adding 10 unordered elements into BST2...");
    addBST(BST2, 45);
    addBST(BST2, 67);
    addBST(BST2, 22);
    addBST(BST2, 100);
    addBST(BST2, 13);
    addBST(BST2, 11);
    addBST(BST2, 64);
    addBST(BST2, 30);
    addBST(BST2, 12);
    addBST(BST2, 14);
    printf("COMPLETE!\n");

    printf("Adding 10 unordered elements into BST3...");
    addBST(BST3, 45);
    addBST(BST3, 67);
    addBST(BST3, 22);
    addBST(BST3, 100);
    addBST(BST3, 13);
    addBST(BST3, 11);
    addBST(BST3, 64);
    addBST(BST3, 30);
    addBST(BST3, 12);
    addBST(BST3, 14);
    printf("COMPLETE!\n\n");
    
    /* Test sizing aspect of addBST function */
    printf("Confirming equivalency of BST size to number of elements added (10):\n");
    if(EQ(numElements, sizeBST(BST)))
        printf("Comparison confirms successful addBST and sizeBST functions. i.e., SUCCESS!\n\n");
    else
        printf("Error in sizing aspect of addBST! FAIL!!\n\n");

    /* Test getFirst and removeFirst functions */
    printf("The first element in the BST is: %d\n", getFirst(BST));
    printf("Removing the first element in BST...");
    removeFirst(BST);
    numElements--;        /*  Reduce numElements for next test of sizing aspect 
                            (post-removal tests). */
    printf("COMPLETE!\n");
    printf("The first element in the BST is now: %d\n\n", getFirst(BST));

    /* Test containsBST function by searching for known value */
    printf("Searching BST for known value \'13\'...");
    if(containsBST(BST, 13))
        printf("FOUND!\nSearch confirms success of containsBST function. i.e., SUCCESS!\n\n");
    else
        printf("Error in containsBST function! FAIL!!!\n\n");

    /*  Remove a known value from BST and use that value to pass negative case 
        through containsBST function. This is also a test of the removeBST 
        function.  */
    printf("Removing known value \'13\' in BST...");
    removeBST(BST, 13);
    numElements--;        /*  Reduce numElements for next test of sizing aspect 
                            (post-removal tests). */
    printf("COMPLETE!\n\n");

    printf("Searching BST for removed value \'13\'...");
    if(containsBST(BST, 13))
        printf("FOUND!\nError in removeBST function. FAIL!!!\n\n");
    else
        printf("NOT FOUND!\nremoveBST function successfully removed test value. i.e., SUCCESS!\n\n");

    /* Repeat sizing test to determine success of removeBST function */
    printf("Confirming removal resulted in proper resizing of BST...");
    if(EQ(numElements, sizeBST(BST)))
        printf("SUCCESS!\n\n");
    else
        printf("Error in BST resizing. FAILED!\n\n");
    
    /*  Test outputPriorityQueue function via execution (all values to display
        to user).
        NOTE: This is a destructive function and will remove all elements in 
        BST */
    printf("The elements in BST, in order, are:\n");
    outputPriorityQueue(BST);
    numElements = 0;        /* Reduce numElements to mirror anticipated count in BST */
    printf("Output complete.\n\n");    
    
    /*  Test positive case comparison of equalsBST function 
        NOTE: This is a destructive function and will remove all elements in 
        BST2 and BST3 */
    printf("Determining if BST2 == BST 3...");
    if(equalsBST(BST2, BST3))
        printf("EQUAL! SUCCESS!\n\n");
    else
        printf("NOT EQUAL! FAIL!!!\n\n");

    /*  Add trivial element to the empty BST and test negative case comparison
        of equalsBST function.
        NOTE: This is a destructive function and will remove all elements in 
        BST and BST2 
        Since there are no more sizing tests, numElements will not be 
        incremented to mirror the size of BST during this routine.  */
    printf("Adding element to empty BST to differentiate it from empty BST2...");
    addBST(BST, 23);
    printf("COMPLETE!!\n");

    printf("Determining if BST == BST 2...");
    if(equalsBST(BST, BST2))
        printf("EQUAL! FAIL!!!\n\n");
    else
        printf("NOT EQUAL! SUCCESS!\n\n");

    /*  Free memory allocation of BST, BST2, and BST3 Nodes and their 
        BinarySearchTree memory allocation */
    if(BST->root != 0)
        freeBST(BST);
    if(BST2->root != 0)
        freeBST(BST2);
    if(BST3->root != 0)
        freeBST(BST3);
    
    free(BST);
    free(BST2);
    free(BST3);
    
    return 0;
}