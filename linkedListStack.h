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
# endif                             //Move endif to include TYPE and EQ definitions

#include <assert.h>

void linkedListStackInit (struct linkedListStack * s);

void linkedListStackFree (struct linkedListStack *s);
void linkedListStackPush (struct linkedListStack *s, TYPE d);

TYPE linkedListStackTop (struct linkedListStack *s);

void linkedListStackPop (struct linkedListStack *s);

int linkedListStackIsEmpty (struct linkedListStack *s);
