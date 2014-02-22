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

void destroyBasicTypeAlloc(void *p)
{
	//For pointers to basic data types (int*,char*,double*,...)
	//Use for allocated memory (malloc,calloc,etc.)
	free(p);
}

void destroyBasicTypeNoAlloc(void *p)
{
	//For pointers to basic data types (int*,char*,double*,...)
	//Use for memory that has not been allocated (e.g., "int x = 5;SLInsert(mylist,&x);SLRemove(mylist,&x);")
	return;
}



int main()
{
	char *f = "f";
	char *d = "d";
	char *b = "b";

	void *F = f;
	void *D = d;
	void *B = b;

	SortedListPtr myList = SLCreate(compareStrings);

	int success;
	success = SLInsert(myList,F);
	success = SLInsert(myList,D);
	success = SLInsert(myList,B);

	SortedListIteratorPtr myIter = SLCreateIterator(myList);
	void *holder = SLNextItem(myIter);
	SLRemove(myList,D);
	printStrings(myIter);

	SLDestroyIterator(myIter);
	SLDestroy(myList);
////////////////////////////////////////
//
/*
SortedListPtr myList2 = SLCreate(compareInts); // create a list for integers


        int w,x,y,z;
        w = 1;
        x = 2;
        y = 3;


        void *X = &x;
        void *Y = &y;
        void *W = &w;


        //Add elements to the list
                success = SLInsert(myList2,W); // Nodes are created and added to the list
                        success = SLInsert(myList2,X);
                                success = SLInsert(myList2,Y);
        
                                       SortedListIteratorPtr myIter2 = SLCreateIterator(myList2);
                                               int temp = *((int*)SLNextItem(myIter2));
                                                       printf("%d\n", temp);
       
                                                          temp = *((int*)SLNextItem(myIter2));
                                                                   printf("%d\n", temp);
       
                                                                        SRemove(myList2, F);
        
                                                                          SortedListIteratorPtr SecondIter = SLCreateIterator(myList2);
       
                                                                                temp = *((int*)SLNextItem(SecondIter));     //No items in the list
                                                                                        printf("%d\n", temp);

                                                                                            temp = *((int*)SLNextItem(SecondIter));     //No items in the list
                                                                                                    printf("%d\n", temp);
                                                                                                    	
	
	
*/


}
