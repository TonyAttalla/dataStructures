
//main.c for testing worksheet 20 

#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main(int argc, char** argv)
{
    int i,j;
    struct deque *d = (struct deque *) malloc(sizeof(struct deque));
    
    //create deque
    printf("Creating deque, initial capacity 3\n");
    dequeInit(d,3);
    
    //add to front
    printf("Adding to front of deque:\n");
    for (i = 0; i < 5; i++){
        printf("\tAdding %d to front\n", i);
        dequeAddFront(d,i);
    }
    
    printf("\nDeck size\t= %d\tCapacity\t= %d\nBeginning\t= %d\tFront\t\t= %d\nBack\t\t= %d\n\n", d->size, 
                                                                                         d->capacity, 
                                                                                         d->beg, 
                                                                                         dequeFront(d), 
                                                                                         dequeBack(d));
    
    //add to back
    printf("Adding to back\n");
    j = i + 5;
        for (i; i < j; i++){
        printf("\tAdding %d to back\n", i);
        dequeAddBack(d,i);
    }
    printf("\nDeck size\t= %d\tCapacity\t= %d\nBeginning\t= %d\tFront\t\t= %d\nBack\t\t= %d\n\n", d->size, 
                                                                                         d->capacity, 
                                                                                         d->beg, 
                                                                                         dequeFront(d), 
                                                                                         dequeBack(d));
    
    //remove from front
    printf("Removing value from front\n");
    dequeRemoveFront(d);
    
    //remove from back
    printf("Removing value from back\n");
    dequeRemoveBack(d);

    printf("\nDeck size\t= %d\tCapacity\t= %d\nBeginning\t= %d\tFront\t\t= %d\nBack\t\t= %d\n\n", d->size, 
                                                                                         d->capacity, 
                                                                                         d->beg, 
                                                                                         dequeFront(d), 
                                                                                         dequeBack(d));
    
    printf("Freeing deck...");
    dequeFree(d);
    printf("COMPLETE!\n\n");
    
    printf("Deck size\t= %d\n\n", d->size);

    printf("Goodbye!\n\n");

    return 0;
} 
