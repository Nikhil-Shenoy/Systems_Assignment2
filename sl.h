#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <stdlib.h>

struct SortedList
{
	Node *head;
	SortedListIteratorPtr;
	*CompareFuncT temp;
};
typedef struct SortedList* SortedListPtr;

struct Node
{
	void *data;
	Node *next;
}

struct SortedListIterator
{
};
typedef struct SortedListIterator* SortedListIteratorPtr;
typedef int (*CompareFuncT)(void *, void *);
/*asdfadsfasdfasdfadsfasdfasddsaadsfasdfasdfasdfasdfasdfasdfasdfasd*/

SortedListPtr SLCreate(CompareFuncT cf);
void SLDestroy(SortedListPtr list);
int SLInsert(SortedListPtr list, void *newObj);
int SLRemove(SortedListPtr list, void *newObj);
SortedListIteratorPtr SLCreateIterator(SortedListPtr list);
void SLDestroyIterator(SortedListIteratorPtr iter);
void *SLNextItem(SortedListIteratorPtr iter);

#endif
