#ifndef LinkedListDeque
#define TYPE int 
#define EQ(a, b) (a == b) 
#endif

#include <assert.h>
#include <stdlib.h>
#include "../header/linkedListDeque.h"
 
 /* these functions are written for you */ 
void linkedListInit (struct linkedList *q) { 
 q->frontSentinel = malloc(sizeof(struct dlink)); 
 assert(q->frontSentinel != 0); 
 q->backSentinel = malloc(sizeof(struct dlink)); 
 assert(q->backSentinel); 
 q->frontSentinel->next = q->backSentinel; 
 q->backSentinel->prev = q->frontSentinel; 
 q->size = 0; 
} 
 
void linkedListFree (struct linkedList *q) { 
 while (q->size > 0) 
    linkedListRemoveFront(q); 
 
 free (q->frontSentinel); 
 free (q->backSentinel); 
 
 q->frontSentinel = q->backSentinel = 0; 
}

void linkedListAddFront (struct linkedList *q, TYPE e) 
 { _addBefore(q, q->frontSentinel->next, e); } 
 
void linkedListAddBack (struct linkedList *q, TYPE e) 
 { _addBefore(q, q->backSentinel, e); } 
 
int linkedListIsEmpty (struct linkedList *q) { 
 return q->size == 0; 
} 
void linkedListRemoveFront (struct linkedList *q) { 
 assert(! linkedListIsEmpty(q)); 
 _removeLink (q, q->frontSentinel->next); 
} 
 
void linkedListRemoveBack (struct linkedList *q) { 
 assert(! linkedListIsEmpty(q)); 
 _removeLink (q, q->backSentinel->prev); 
} 
 

 
/* write addLink and removeLink. Make sure they update the size field correctly */ 
 
/* _addBefore places a new link BEFORE the provide link, lnk */ 
void _addBefore (struct linkedList *q, struct dlink *lnk, TYPE e) {
    struct dlink *prevLink = lnk->prev;
    struct dlink *newLink = (struct dlink *) malloc(sizeof(struct dlink));
    
    assert(q);
    /*assign newLink attributes*/
    newLink->value = e;
    newLink->next = lnk;
    newLink->prev = prevLink;
    
    /*reassign lnk and previousLink attributes*/
    lnk->prev = newLink;
    prevLink->next = newLink;
    
    q->size++;
} 
 
void _removeLink (struct linkedList *q, struct dlink *lnk) { 
    struct dlink *prevLink = lnk->prev;
    struct dlink *nextLink = lnk->next;
    
    assert(q);
    
    prevLink->next = nextLink;
    nextLink->prev = prevLink;
    
    free(lnk);
    q->size--;
} 
 
TYPE linkedListFront (struct linkedList *q) { 
    assert(q->size > 0);
    return q->frontSentinel->next->value;
} 
 
TYPE linkedListBack (struct linkedList *q) { 
    assert(q->size > 0);
    return q->backSentinel->prev->value;
}
