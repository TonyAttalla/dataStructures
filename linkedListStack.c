# ifndef LinkedListStack
# define LinkedListStack 
# define TYPE int 
# define EQ(a, b) (a == b) 
struct link { 
  TYPE value; 
  struct link * next; 
}; 

struct linkedListStack { 
  struct link *firstLink; 
}; 
# endif                             //Move endif to include TYPE, EQ, and struct definitions

#include <assert.h>
#include "linkedListStack.h"

void linkedListStackInit (struct linkedListStack * s) 
{ s->firstLink = 0; } 

void linkedListStackFree (struct linkedListStack *s) 
{ while (! linkedListStackIsEmpty(s)) linkedListStackPop(s); } 

void linkedListStackPush (struct linkedListStack *s, TYPE d) { 
  struct link * newLink = (struct link *) malloc(sizeof(struct link)); 
  assert (newLink != 0); 
  newLink->value = d;                //Added this line 01/20/14 - RK
  if ( EQ(0, s->firstLink)){
    s->firstLink = newLink;
    newLink->next = 0;            //Added this line 01/21/14 - RK
  }
  else {
    newLink->next = s->firstLink;
    s->firstLink = newLink;
  }
} 

TYPE linkedListStackTop (struct linkedListStack *s) { 
   assert(! EQ(s->firstLink , 0));
    return s->firstLink->value;
} 

void linkedListStackPop (struct linkedListStack *s) { 
  struct link* popped = s->firstLink;
  s->firstLink = popped->next;
  free(popped);
} 

int linkedListStackIsEmpty (struct linkedListStack *s) { 
  if ( !(s->firstLink))
    return 1;
  else
    return 0;
}
