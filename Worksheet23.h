
#ifndef TYPE
#define TYPE int
#endif

#ifndef WORKSHEET23_H
#define WORKSHEET23_H

struct dynArrayIterator { 
	struct DynArr * da; 
	int currentIndex; 
}; 


void dynArrayIteratorInit (struct DynArr *da, struct dynArrayIterator *itr); //DynArr defined in Worksheet14.h
int dynArrayIteratorHasNext (struct dynArrayIterator *itr);
TYPE dynArrayIteratorNext (struct dynArrayIterator *itr);
void dynArrayIteratorRemove (struct dynArrayIterator *itr); 

#endif // WORKSHEET23_H
