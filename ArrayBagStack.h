//In this worksheet we will construct a simple BAG and STACK abstraction on top of an
//array. Assume we have the following interface file (arrayBagStack.h) :

# ifndef ArrayBagStack
# define ArrayBagStack
# define TYPE int
# define EQ(a, b) (a == b)

//WS0
struct arrayBagStack {
   TYPE data [100];
   int count;
};

# endif
//Worksheet0.c
void initArray(struct arrayBagStack * b);
void addArray (struct arrayBagStack * b, TYPE v);
int containsArray (struct arrayBagStack * b, TYPE v);
void removeArray (struct arrayBagStack * b, TYPE v);
int sizeArray (struct arrayBagStack * b);
void pushArray (struct arrayBagStack * b, TYPE v);
TYPE topArray (struct arrayBagStack * b);
void popArray (struct arrayBagStack * b);
int isEmptyArray (struct arrayBagStack * b);
