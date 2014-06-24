#ifndef LinkedListDeque
#define TYPE int 
#define EQ(a, b) (a == b) 
#endif

#include <assert.h>

struct dlink { 
 TYPE value; 
 struct dlink * next; 
 struct dlink * prev; 
}; 
 
struct linkedList { 
 int size; 
 struct dlink * frontSentinel; 
 struct dlink * backSentinel; 
}; 
 
 /* these functions are written for you */ 
void linkedListInit (struct linkedList *q); 
void linkedListFree (struct linkedList *q);
void linkedListAddFront (struct linkedList *q, TYPE e); 
void linkedListAddBack (struct linkedList *q, TYPE e); 
int linkedListIsEmpty (struct linkedList *q);
void linkedListRemoveFront (struct linkedList *q); 
void linkedListRemoveBack (struct linkedList *q); 
 
/* write addLink and removeLink. Make sure they update the size field correctly */ 
 
/* _addBefore places a new link BEFORE the provide link, lnk */ 
void _addBefore (struct linkedList *q, struct dlink *lnk, TYPE e); 
void _removeLink (struct linkedList *q, struct dlink *lnk); 
TYPE linkedListFront (struct linkedList *q); 
TYPE linkedListBack (struct linkedList *q);