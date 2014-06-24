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

void listQueueInit (struct listQueue *q) { 
    struct link *lnk = (struct link *) malloc(sizeof(struct link)); 
    assert(lnk != 0); /* lnk is the sentinel */ 
    lnk->next = 0; 
    q->firstLink = q->lastLink = lnk; 
} 
 
void listQueueAddBack (struct listQueue *q, TYPE e) { 
    struct link *penult = q->lastLink; //original final link
    struct link *last = (struct link *) malloc(sizeof(struct link)); //create link to be added to back
    last->value = e;    
    last->next = 0;
    penult->next = last;    
    q->lastLink = last;
} 
 
TYPE listQueueFront (struct listQueue *q) { 
    return q->firstLink->next->value;
  }

void listQueueRemoveFront (struct listQueue *q) { 
    struct link *front = q->firstLink->next;
    assert(q->firstLink->next != 0);
    q->firstLink->next = front->next;
    if (EQ(q->firstLink->next, 0)){
        q->lastLink=q->firstLink;
    }
    free(front);
 } 
 
int listQueueIsEmpty (struct listQueue *q) { 
    if(EQ(q->firstLink, q->lastLink))                  
        return 1;
    else 
        return 0;
  }