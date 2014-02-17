#include <stdio.h>
#include <stdlib.h>
#include "sl.h"

SortedListPtr SLCreate(CompareFuncT cf)
{
    SortedListPtr newPtr;
	newPtr = (SortedListPtr) malloc(sizeof(struct SortedList));
    
    newPtr->head = NULL;
    newPtr->CompareFuncT = cf;
/*    newPtr->SortedListIteratorPtr = NULL;*/

	printf("Finished making the sorted list.\n");

	return newPtr;
}
        
    
void SLDestroy(SortedListPtr list)
{
    Node *cur = list->head;
    
    while(cur != NULL)
    {
	list->head = list->head->next; /*Move the head forward*/
	cur->next = NULL; /*Disconnect cur*/
	NodeDestroy(cur); /*Destroy the disconnected node*/
	cur = list->head; /*point cur to the new head*/ 
    }
    free(list);

	printf("Destroying myList\n");
    return;
}

NodePtr NodeCreate(void *newObj)
{
	NodePtr newPtr = (NodePtr) malloc(sizeof(Node));

	newPtr->data = newObj;
	newPtr->next = NULL;

	printf("Finished making the node.\n");

	return newPtr;
}

void NodeDestroy(NodePtr myNode)
{
	free(myNode);
	printf("Destroying myNode\n");

	return;
}




/* Inserts given object into the list while maintaining sorted order. Success returns 1,
	failure returns 0 */
    
int SLInsert(SortedListPtr list, void *newObj)
{
	if(list->head == NULL)
	{
		NodePtr newNode = NodeCreate(newObj);
		list->head = newNode;

		printf("Adding node to empty list.\n");
		return 1;
	}
	else if(list->head != NULL)
	{
		NodePtr cur = list->head;
		NodePtr prev = NULL;


		/*Move the cur and prev pointers until cur points to the node where the newObj
			should be inserted and prev points to the node before that point. */

		while(list->CompareFuncT(cur->data,newObj) < 0) 
		{
			prev = cur;
			cur = cur->next;
		}
	
		NodePtr newNode = NodeCreate(newObj);

		/*Insert*/
		prev->next = newNode;
		newNode = cur;
	
		printf("Adding node to non-empty list.\n");
		
		return 1;
	}
	else
		return 0;
}



































	
