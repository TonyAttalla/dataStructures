#ifndef Deque
#define TYPE int 
#define EQ(a, b) (a == b) 
#endif

#include <assert.h>

struct deque { 
 TYPE * data; 
 int capacity; 
 int size; 
 int beg; 
}; 

void _dequeSetCapacity (struct deque *v, int newCap); 
void dequeFree (struct deque *d); 
void dequeInit (struct deque *d, int initCapacity); 
int dequeSize (struct deque *d); 
void _dequeDoubleCapacity (struct deque *d);
void dequeAddFront (struct deque *d, TYPE newValue); 
void dequeAddBack (struct deque *d, TYPE newValue);
TYPE dequeFront (struct deque *d); 
TYPE dequeBack (struct deque *d);
void dequeRemoveFront (struct deque *d); 
void dequeRemoveBack (struct deque *d);