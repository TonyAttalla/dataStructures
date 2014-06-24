#ifndef ListQueue
#define TYPE int 
#define EQ(a, b) (a == b) 
#endif                        //Added conditional definition 1/21/14 - RK

#include <assert.h>
#include <stdlib.h>

struct link { 
    TYPE value; 
    struct link * next; 
}; 
 
struct listQueue { 
    struct link *firstLink; 
    struct link *lastLink; 
}; 

void listQueueInit (struct listQueue *q);
 
void listQueueAddBack (struct listQueue *q, TYPE e);
 
TYPE listQueueFront (struct listQueue *q);

void listQueueRemoveFront (struct listQueue *q);
 
int listQueueIsEmpty (struct listQueue *q);