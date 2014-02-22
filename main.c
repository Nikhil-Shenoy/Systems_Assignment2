/*
 * sorted-list.c
 */

//test comment Abhishek
#include <stdio.h>
#include	<string.h>
#include	"sl.h"

int compareInts(void *p1, void *p2)
{
	int i1 = *(int*)p1;
	int i2 = *(int*)p2;

	return i1 - i2;
}

int compareDoubles(void *p1, void *p2)
{
	double d1 = *(double*)p1;
	double d2 = *(double*)p2;

	return (d1 < d2) ? -1 : ((d1 > d2) ? 1 : 0);
}

int compareStrings(void *p1, void *p2)
{
	char *s1 = p1;
	char *s2 = p2;
	return strcmp(s1, s2);
}


void printDoubles(SortedListIteratorPtr iter)
{
	NodePtr location = iter->current;

	while(iter->current != NULL)
	{
		double temp = *((double*)SLNextItem(iter));
		printf("%f\n",temp);
	}

	iter->current = location; // move iterator back to where it was 
}

void printStrings(SortedListIteratorPtr iter)
{
	NodePtr location = iter->current;

	while(iter->current != NULL)
	{
		char *temp = SLNextItem(iter);
		printf("%s\n",temp);
	}

	iter->current = location; // move iterator back to where it was 
}

void getRefCounts(SortedListIteratorPtr iter)
{
	NodePtr cur = iter->current;	
	
	while(cur != NULL)
	{
		int count = cur->refcount;
		printf("RefCount is: %u\n",count);

		cur = cur->next;
	}



	return;
}	

void printInts(SortedListIteratorPtr iter)
{
	NodePtr location = iter->current;

	while(iter->current != NULL)
	{
		getRefCounts(iter);
		int temp = *((int*)SLNextItem(iter));
		printf("The value is: %u\n",temp);
	}

	iter->current = location; // move iterator back to where it was 
}


int main()
{
	int success;

	SortedListPtr myList = SLCreate(compareInts); // create a list for integers
	

	int a,b,c,d;
	a = 1;
	b = 2;
	c = 3;
	d = 4;

	void *A = &a;
	void *B = &b;
	void *C = &c;
	void *D = &d;

	//Add elements to the list
	success = SLInsert(myList,C); // Nodes are created and added to the list
	success = SLInsert(myList,B);	
	success = SLInsert(myList,C); // duplicates are not added to the list
	success = SLInsert(myList,D);	
	success = SLInsert(myList,A);

	SortedListIteratorPtr myIter = SLCreateIterator(myList); // create an iterator that points to the head of the list
/*	getRefCounts(myIter);*/
	
	printInts(myIter); // print the list


//	getRefCounts(myIter);
	



	SLDestroy(myList);

































/*	SortedListPtr myList = SLCreate(&compareStrings);

	char *a = "b";
	char *b = "f";
	char *c = "d";
	char *d = "z";

	*a = "f";
	*b = "d";
	*c = "b";
	
	void *A = a;
	void *B = b;
	void *C = c;
	void *D = d;
	int holder;

	holder = SLInsert(myList,A);
	holder = SLInsert(myList,B);
	holder = SLInsert(myList,C);
	printStrings(myList);


	SortedListIteratorPtr iter = SLCreateIterator(myList);

	holder = SLRemove(myList,"d");

	char * timp = SLNextItem(iter);
	printf("Next item is: %s\n",timp);

	timp = SLNextItem(iter);
	printf("Next item is: %s\n",timp);
	


	timp = SLNextItem(iter);
	printf("Next item is: %s\n",timp);
	
	SLDestroy(myList);

*/
}
