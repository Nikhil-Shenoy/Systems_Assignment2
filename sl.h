#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <stdlib.h>

struct Node
{
	void *data;
	struct Node *next;
};

typedef struct Node Node;

struct SortedList
{
	struct Node *head;
	/*SortedListIteratorPtr;*/
	int (*CompareFuncT) (void *, void *);
};

typedef struct SortedList SortedList;
typedef struct SortedList* SortedListPtr;

struct SortedListIterator
{
};
typedef struct SortedListIterator* SortedListIteratorPtr;
typedef int (*CompareFuncT)(void *, void *);

/*----------------------------------------------------------------------*/

typedef Node* NodePtr;

NodePtr NodeCreate(void *newObj);
void NodeDestroy(NodePtr myNode);


SortedListPtr SLCreate(CompareFuncT cf); // done
void SLDestroy(SortedListPtr list); // done
int SLInsert(SortedListPtr list, void *newObj);
int SLRemove(SortedListPtr list, void *newObj);
SortedListIteratorPtr SLCreateIterator(SortedListPtr list);
void SLDestroyIterator(SortedListIteratorPtr iter);
void *SLNextItem(SortedListIteratorPtr iter);

#endif
