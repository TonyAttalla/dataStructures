/*  int containsKey (KEYTYPE key)       O(n)
    VALUETYPE get (KEYTYPE key)         O(n)
    put (KEYTYPE key, VALUETYPE value)  O(n)
    void remove (KEYTYPE key)           O(n)
*/

#include <assert.h>
#include <string.h>
# include "dyArrayDictionary.h"
//# include "dyArrayDictionary.c"       //Not sure why we'd include the file we're coding

/*finds and places the value associated with key in valptr */
VALUETYPE dyArrayDictionaryGet (struct dynArr *da, KEYTYPE key) {
    int i;

    for(i = 0; i < da->size; i++)
        if(strcmp(key, da->data[i]->key))      //Assuming dynArr has struct association called 'data'
            return da->data[i]->val;

    return 0;
}

void dyArrayDictionaryPut (struct dynArr *da, KEYTYPE key, VALUETYPE val) {
    struct association * ap;
    
    if (dyArrayDictionaryContainsKey(da, key))
        dyArrayDictionaryRemove(da, key);

    ap = (struct association *) malloc(sizeof(struct association));
    assert(ap != 0);
    ap->key = key;
    ap->value = val;
    dyArrayAdd(da, ap);
}

int dyArrayDictionaryContainsKey (struct dynArr *da, KEYTYPE key) {
    int i;

    for(i = 0; i < da->size; i++)
        if(strcmp(key, da->data[i]->key))      //Assuming dynArr has struct association called 'data'
            return 1;
    
    return 0;
}

void dyArrayDictionaryRemove (struct dynArr *da, KEYTYPE key) {
    int i;
    struct association * ap;

    for(i = 0; i < da->size; i++){
        if(strcmp(key, da->data[i]->key)){      //Assuming dynArr has struct association called 'data'
            ap = da->data[i];
            removeDynArr(da, i);
            free(ap);
        }
    }
}