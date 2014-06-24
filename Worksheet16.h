# ifndef TYPE
# define TYPE int
# define EQ(a, b) (a == b)


struct DynArr{
	TYPE *data;	// pointer to the data array 
	int size;		// Number of elements in the array 
	int capacity;	// capacity of the array 
};
#endif

//Worksheet16.c

/* Adds value e to end of DynArr */
void pushDynArr(struct DynArr * v, TYPE e);

/* Removes last value in DynArr */
void popDynArr(struct DynArr * v);

/* Reads the last value in DynArr */
TYPE topDynArr(struct DynArr * v);

/* Boolean return determining if DynArr is empty
 * TRUE:    DynArr is empty
 * FALSE:   DynArr is not empty */
int isEmptyDynArr(struct DynArr * v);