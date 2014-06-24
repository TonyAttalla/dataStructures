#include <assert.h>
#include <cstdlib>

# ifndef TYPE
# define TYPE      int
# endif

struct hlink {
    TYPE value;
    struct hlink *next;
};

struct hashTable {
    struct hlink ** table;
    int tablesize;
    int count;
};

void initHashTable (struct hashTable * ht, int size) {
    int i;
    
    assert (size > 0);
    
    ht->table = (struct hlink **) malloc(size * sizeof(struct hlink *));
    
    
    assert(ht->table != 0);
    
    for (i = 0; i < size; i++){
        ht->table[i]->value = 0;
        ht->table[i]->next = 0;
    }
    
    ht->tablesize = size;
    ht->count = 0;
}

int hashTableSize (struct hashTable * ht) { 
    return ht->count; 
}

void hashTableAdd (struct hashTable *ht, TYPE newValue) {
    // compute hash value to find the correct bucket
    int hashIndex = HASH(newValue) % ht->tablesize;
    struct hlink * newLink = (struct hlink *) malloc(sizeof(struct hlink));

    if (hashIndex < 0) 
        hashIndex += ht->tablesize;
    
    assert(newLink);
    
    newLink->value = newValue; 
    newLink->next = ht->table[hashIndex];
    ht->table[hashIndex] = newLink; /* add to bucket */
    
    ht->count++;
    if ((ht->count / (double) ht->tablesize) > 8.0) 
        _resizeHashTable(ht);
}

int hashTableContains (struct hashTable * ht, TYPE testElement) {
    int idx;
    struct hlink * currLink;

    idx = HASH(testElement) % ht->tablesize;
    if (idx < 0) 
        idx += ht->tablesize;

    currLink = ht->table[idx];
    while(currLink != 0){
        if(compare(currLink->value, testElement) == 0)
            return 1;   //Found testValue in ht!
        else
            currLink = currLink->next;
    }

    return 0;   //testElement is not in ht
}

void hashTableRemove (struct hashTable * ht, TYPE testElement) {
    int idx;
    struct hlink * currLink, * deleteLink;

    assert(hashTableContains(ht, testElement));

    idx = HASH(testElement) % ht->tablesize;
    if (idx < 0) 
        idx += ht->tablesize;

    currLink = ht->table[idx];
    
    while((compare(currLink->value, testElement) == 0) || (currLink == 0))
        currLink = currLink->next;
    
    if(currLink != 0){
        deleteLink = currLink;
        currLink = currLink->next;
        ht->count--;
        free(deleteLink);
    }
}

void _resizeHashTable (struct hashTable *ht) {
    int i = 0;
    struct hashTable * newHT;
    struct hlink * currLink;

    initHashTable(newHT, ht->tablesize * 2);

    while(i < ht->tablesize){
        currLink = ht->table[i];
        while(currLink != 0){
            hashTableAdd(newHT, currLink->value);
            currLink = currLink->next;
        }

        i++;
    }
}