#include <assert.h>
#include <stdlib.h>
#include "../header/linkedListDeque.h"
#include "../header/Worksheet22.h"

void linkedListAdd (struct linkedList * list, TYPE e) {
    //_addBefore(list, list->frontSentinel->next, e);   //See next comment.
    
    //It may be easier to simply call linkedListAddFront(list, e) since we've already implemented the function.
    linkedListAddFront(list, e);
}

int linkedListContains (struct linkedList *list, TYPE e) {
    struct dlink *link = list->frontSentinel->next;
    
    if(linkedListIsEmpty(list)) {
        return 0;
    } 
    else {
        //struct dlink *link = list->frontSentinel->next;  //This won't compile on FLIP.  Variable declarations must be at the top of the function
        while(link!= list->backSentinel) {
            if(link->value == e) 
                return 1;
            link = link->next;
        }
        
        return 0;
    }
}

void linkedListRemove (struct linkedList *list, TYPE e) {
    struct dlink *link = list->frontSentinel->next;
    
    if(!linkedListIsEmpty(list)) {
        //struct dlink *link = list->frontSentinel->next;  //This won't compile on FLIP.  Variable declarations must be at the top of the function
        while(link!= list->backSentinel) {
            if(link->value == e) {
                _removeLink(list, link);
                break;
            }
            link = link->next;
        }
    }
    
    return ;
}
