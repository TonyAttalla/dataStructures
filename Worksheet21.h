# ifndef TYPE
# define TYPE int
# define EQ(a, b) (a == b)
#endif

#ifndef WORKSHEET21_H
#define WORKSHEET21_H

#include "Worksheet14.h"

/* Remove the value stored at position in the dynamic array */
void _dynArrayRemoveAt (struct DynArr * da, int index);

/* Removes first instance discovered of target value "test" */
void removeDynArr (struct DynArr * da, TYPE test);

/* Returns index position of first instance of target value e */
int containsDynArr (struct DynArr * da, TYPE e);
#endif // WORKSHEET21_H