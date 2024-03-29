#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <stdlib.h>

struct Node
{
	int refcount;
	void *data;
	struct Node *next;
};

typedef struct Node Node;
typedef Node* NodePtr;


struct SortedList
{
	Node *head;
	int (*CompareFuncT) (void *, void *);
};

typedef struct SortedList SortedList;
typedef struct SortedList* SortedListPtr;

struct SortedListIterator
{
    Node *current;
};
typedef struct SortedListIterator SortedListIterator;
typedef struct SortedListIterator* SortedListIteratorPtr;
typedef int (*CompareFuncT)(void *, void *);

/*----------------------------------------------------------------------*/

NodePtr NodeCreate(void *newObj); // done
void NodeDestroy(NodePtr myNode); // done


SortedListPtr SLCreate(CompareFuncT cf); // done
void SLDestroy(SortedListPtr list); // done
int SLInsert(SortedListPtr list, void *newObj); //done
int SLRemove(SortedListPtr list, void *newObj); //done



SortedListIteratorPtr SLCreateIterator(SortedListPtr list);
void SLDestroyIterator(SortedListIteratorPtr iter);
void *SLNextItem(SortedListIteratorPtr iter);

#endif
