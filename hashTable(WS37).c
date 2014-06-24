#include <assert.h>
#include <cstdlib>

struct openHashTable {
    TYPE ** table;
    int tablesize;
    int count;
};

void initOpenHashTable (struct openHashTable * ht, int size) {
    int i;
    
    assert (size > 0);
    
    ht->table = (TYPE **) malloc(size * sizeof(TYPE *));
    
    assert(ht->table != 0);
    
    for (i = 0; i < size; i++)
        ht->table[i] = 0; /* initialize empty */
    ht->tablesize = size;
    ht->count = 0;
}

int openHashTableSize (struct openHashTable *ht) { 
    return ht->count; 
}

void openHashTableAdd (struct openHashTable * ht, TYPE *newValue) {
    int idx;

    /* Make sure we have space and under the load factor threshold*/
    if ((ht->count / (double) ht->tablesize) > 0.75)
        _resizeOpenHashTable(ht);
    
    ht->count++;
    idx = HASH(newValue) % ht->tablesize;
    
    /* To be safe, use only positive arithmetic. % may behave very differently on diff
    implementations or diff languages . However, you can do the following to deal with a
    negative result from HASH */
    if (idx < 0) 
        idx += ht->tablesize;

    while(idx >= 0){   //Call to resizeOpenHashTable prevents this from being an infinite loop.
        if(idx == ht->tablesize)
            idx = 0;

        if(ht->table[idx] == 0){
            ht->table[idx] = newValue;
            idx = -1;   //Set loop driver to break condition
        }
        else
            idx++;
    }

int openHashTableBagContains (struct openHashTable *ht, TYPE newValue) {
    int idx;

    idx = HASH(newValue) % ht->tablesize;
    if (idx < 0) 
        idx += ht->tablesize;

    while(ht->table[idx] != 0){
        if(compare(ht->table[idx], newValue) == 0)
            return 1;   //Found newValue in ht!
        else{
            idx++;
            
            if(idx == ht->tableSize)
                idx = 0;    //When end of array is reached, reset to 0th element
        }
    }

    return 0;   //newValue is not in ht
}

void _resizeOpenHashTable (struct openHashTable *ht) {
    int i = 0;
    struct openHashTable * newHT;

    initOpenHashTable(newHT, ht->tableSize * 2);

    while(i < ht->tableSize)
        openHashTableAdd(newHT, ht->table[i]);
}