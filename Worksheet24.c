#include "../header/linkedListDeque.h"
#include "../header/Worksheet24.h"

void linkedListIteratorInit(struct linkedList *lst, struct linkedListIterator *itr) {
    itr->lst = lst;
    itr->currentLink =  lst->frontSentinel;
}

int linkedListIteratorHasNext(struct linkedListIterator *itr) {
    if(itr->currentLink->next != itr->lst->backSentinel) {
        //itr->currentLink = itr->currentLink->next;    //linkedListIteratorNext moves to next value
        return 1;
    } else {
        return 0;
    }
}

TYPE linkedListIteratorNext(struct linkedListIterator *itr) {
    itr->currentLink = itr->currentLink->next;  //Moved link increment here - RK
    
    return itr->currentLink->value;
}

void linkedListIteratorRemove(struct linkedListIterator *itr) {
    struct dlink * current = itr->currentLink;
    
    itr->currentLink = itr->currentLink->prev;
    
    _removeLink(itr->lst, current);
}

