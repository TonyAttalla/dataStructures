#ifndef LinkedListIterator
#define LinkedListIterator
#ifndef TYPE
#define TYPE int
#endif

struct linkedListIterator {
  struct linkedList *lst;
  struct dlink * currentLink;
};

void linkedListIteratorInit(struct linkedList *lst, struct linkedListIterator *itr);
int linkedListIteratorHasNext(struct linkedListIterator *itr);
TYPE linkedListIteratorNext(struct linkedListIterator *itr);
void linkedListIteratorRemove(struct linkedListIterator *itr);

#endif //LinkedListIterator
