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
	newPtr->refcount = 0;

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
		list->head->refcount += 1;
		printf("Leaving SLInsert\n");
			

		return 1;
	}
	else if(list->head != NULL)
	{


		NodePtr cur = list->head;
		NodePtr prev = NULL;


		/*Move the cur and prev pointers until cur points to the node where the newObj
			should be inserted and prev points to the node before that point. */



		if(list->CompareFuncT(newObj,cur->data) > 0)
		{

			
			NodePtr newNode = NodeCreate(newObj);
			
			newNode->next = cur;

			list->head = newNode;	
			newNode->refcount += 1;
			printf("Leaving SLInsert\n");
			

			
			return 1;
		}
		else
		{

			while((cur != NULL) && (list->CompareFuncT(newObj,cur->data)) <= 0)
			{
				if(newObj == cur->data)
				{
					printf("Duplicates are not stored in this list\n");
					return 0;
				}
				prev = cur;
				cur = cur->next;
			}

	
			NodePtr newNode = NodeCreate(newObj);
			/*Insert*/


			prev->next = newNode;

			newNode->refcount += 1;
			
			newNode->next = cur;
		
			printf("Leaving SLInsert\n");
			
			return 1;
		}
	}
	else
	{
		printf("Hello again\n");
		return 0;
	}
}




int SLRemove(SortedListPtr list, void *newObj)
{
	printf("Entering SLRemove\n");

	if(list->head==NULL)
	{
		printf("Leaving SLRemove\n");
		return 0; // remove failed
	}
	else if(list->head != NULL)
	{
   
		NodePtr cur = list->head;
		NodePtr prev = NULL;
   
		while(list->CompareFuncT(cur->data,newObj) != 0)
		{
			prev = cur;
			cur = cur->next;
		}

		if(cur->refcount==1)
		{
			if(cur == list->head) // special case of deleting the head of the list
			{
				list->head = list->head->next; // move the head pointer forward
				cur->next = NULL;
				NodeDestroy(cur);
				printf("Leaving SLRemove\n");
				return 1;
			}
			else
			{
				prev->next = cur->next;
				cur->next = NULL;
				NodeDestroy(cur);
				printf("Leaving SLRemove\n");
				return 1;
			}
		}
		else if(cur->refcount>1)
		{	
			printf("Special case\n");
			prev->next = cur->next;
			printf("Leaving SLRemove\n");
			return 1;
		}
	}
	else
	{
		printf("Leaving SLRemove\n");
		return 0;
	}
   
   
}


SortedListIteratorPtr SLCreateIterator(SortedListPtr list)
{
	printf("Enter SLCreateIterator\n");

	SortedListIteratorPtr  init = (SortedListIteratorPtr) malloc(sizeof(SortedListIterator));

	init->current = list->head;

	if(init->current != NULL)
		init->current->refcount += 1;

	printf("Leaving SLCreateIterator\n");
	
	return init;
}


void SLDestroyIterator(SortedListIteratorPtr iter)
{
	printf("Enter SLDestroyIterator\n");
	iter->current->refcount -= 1;
	iter->current = NULL; 
	free(iter);
	printf("Leaving SLDestroyIterator\n");
	return;
}



void *SLNextItem(SortedListIteratorPtr iter)
{
	printf("Enter SLNextItem\n");
	if (iter->current->next==NULL)
    	{
		void *temp = iter->current->data;
		iter->current = iter->current->next;	
		printf("Here?\n");	
	
		return temp;
   	} 
	void *temp = iter->current->data;

	iter->current->refcount -= 1;

	if(iter->current->refcount==0)
	{
		printf("sup\n");
		NodePtr tomp = iter->current;

		iter->current = iter->current->next;
		iter->current->refcount += 1;
		tomp->next = NULL;
		NodeDestroy(tomp);
		printf("Leaving SLNextItem\n");
		return temp;
	} 

	else if(iter->current->refcount >= 1)
	{
		printf("sup2\n");

		iter->current = iter->current->next; // Move to the next node
		iter->current->refcount += 1;
		
		printf("Leaving SLNextItem\n");
		return temp;
	}

}




















































