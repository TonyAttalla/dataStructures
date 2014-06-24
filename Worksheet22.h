#ifndef LinkedListBag
#define LinkedListBag
#ifndef TYPE
#define TYPE int
#endif

typedef struct linkedList linkedList;

void linkedListAdd (struct linkedList * lst, TYPE e);
int linkedListContains (struct linkedList *lst, TYPE e);
void linkedListRemove (struct linkedList *lst, TYPE e);

#endif // LinkedListBag
