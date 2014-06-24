# ifndef DYARRAYDICTH
# define DYARRAYDICTH
/*
dynamic array dictionary interface file
*/
# ifndef KEYTYPE
# define KEYTYPE char *
# endif

# ifndef VALUETYPE
# define VALUETYPE double
# endif

struct association {
    KEYTYPE key;
    VALUETYPE value;
};

# define TYPE struct association *

# include "dyArray.h"

/* dictionary */
VALUETYPE dyArrayDictionaryGet (struct dyArray * da, KEYTYPE key);
void dyArrayDictionaryPut (struct dyArray * da, KEYTYPE key, VALUETYPE val);
int dyArrayDictionaryContainsKey (struct dyArray * da, KEYTYPE key);
void dyArrayDictionaryRemoveKey (struct dyArray * da, KEYTYPE key);
# endif