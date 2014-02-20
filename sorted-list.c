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

		printf("The new object is: \n");
		printf("HELLO\n");

		printf("Adding node to empty list.\n");
		return 1;
	}
	else if(list->head != NULL)
	{

		printf("HELLO\n");
		NodePtr cur = list->head;
		NodePtr prev = NULL;


		/*Move the cur and prev pointers until cur points to the node where the newObj
			should be inserted and prev points to the node before that point. */



		if(list->CompareFuncT(newObj,cur->data) > 0)
		{

			
			NodePtr newNode = NodeCreate(newObj);
			
			newNode->next = cur;
			list->head = newNode;
			
			return 1;
		}
		else
		{
			while((cur != NULL) && (list->CompareFuncT(newObj,cur->data)) < 0)
			{
				prev = cur;
				cur = cur->next;
			}

	
			NodePtr newNode = NodeCreate(newObj);
			/*Insert*/
			prev->next = newNode;
			
			newNode->next = cur;
		
			printf("Adding node to non-empty list.\n");
			
			return 1;
		}
	}
	else
	{
		printf("Hello again\n");
		return 0;
	}
}




int SLRemove(SortedListPtr list, void *newObj){
   if(list->head==NULL){
       return 0;
   }
   else{
   
   NodePtr cur = list->head;
   NodePtr prev = NULL;
   
   while(list->CompareFuncT(cur->data,newObj) != 0)
{
prev = cur;
cur = cur->next;
}
   
       prev->next = cur->next;
       cur->next = NULL;
       NodeDestroy(cur);
   return 1;
   }
   
}


SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
    Node * start = list->head;
    
    SortedListIteratorPtr  init = (SortedListIteratorPtr ) malloc(sizeof(SortedListIteratorPtr));
    init->fir = start;
    return init;
    
}


void SLDestroyIterator(SortedListIteratorPtr iter){
    
    free(iter);
    return;}



void *SLNextItem(SortedListIteratorPtr iter){
    if (iter->fir==NULL) {
        return NULL;
    }
    void *temp = iter->fir->data;
  
    iter->fir = iter->fir->next;
    return temp;

}





