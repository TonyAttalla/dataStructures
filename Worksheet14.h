# ifndef TYPE
# define TYPE int
# define EQ(a, b) (a == b)
#endif

#ifndef WORKSHEET14_H
#define WORKSHEET14_H

//Worksheet14.c
struct DynArr{
	TYPE *data;	// pointer to the data array 
	int size;		// Number of elements in the array 
	int capacity;	// capacity of the array 
};

/* Initializes the dynamic array and associated descriptors in struct DynArr */
void initDynArr(struct DynArr *v, int capacity);

/* Frees memory from dynamic array and sets struct DynArr descriptors to NULL */
void freeDynArr(struct DynArr *v);

/* Returns size of DynArr. 
 * NOTE: changed return type to int from void */
int sizeDynArr( struct DynArr *v);

/* Doubles the capacity of the DynArr */
void _setCapacityDynArr(struct DynArr *v, int newCap);

/* Adds value to the end of the DynArr and increments size desciptor */
void addDynArr(struct DynArr *v, TYPE val);

/* Returns data in DynArr at argument position
 * Includes index verification */
TYPE getDynArr (struct DynArr * da, int position);

/* Overwrites data in DynArr at argument position with value
 * Includes index verification */
void putDynArr(struct DynArr * da, int position, TYPE value);

/* Swaps data between two positions in DynArr
 * Includes index verification */
void swapDynArr (struct DynArr * da, int i, int j);

/* Removes elements at index position and shifts array accordingly
 * Includes index verification and size decrement. */
void removeAtDynArr (struct DynArr * da, int index);

#endif //WORKSHEET14_H