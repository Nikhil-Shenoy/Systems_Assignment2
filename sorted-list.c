#include <stdlib.h>
#include "sorted-list.h"

SortedListPtr SLCreate(CompareFuncT cf)
{
    SortedListPtr newPtr = (struct SortedListPtr*) malloc(sizeof(struct SortedList));
    
    newPtr->head = NULL;
    newPtr->CompareFunct = cf;
/*    newPtr->SortedListIteratorPtr = SLCreateIterator() */
}
        
    
void SLDestroy(SortedListPtr list)
{
    Node *cur = list->head;
    
    while(cur != NULL)
    {
        list->head = list->head->next;     
        free(cur->data);
        cur->next = NULL;
        free(cur->next);
        free(cur);
    }
    free(list);
    return;
}
    
int SLInsert((SortedListPtr list, void *newObj)
