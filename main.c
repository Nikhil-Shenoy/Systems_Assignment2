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

void printInts(SortedListPtr list)
{
	Node *cur = list->head;

	while(cur != NULL)
	{
		void *temp = cur->data;
		int toPrint = *((int*)temp);

		printf("%u\n",toPrint);

		cur = cur->next;
	}
}

void printDoubles(SortedListPtr list)
{
	Node *cur = list->head;

	while(cur != NULL)
	{
		void *temp = cur->data;
		double toPrint = *((double*)temp);

		printf("%f\n",toPrint);

		cur = cur->next;
	}
}

void printStrings(SortedListPtr list)
{
	Node *cur = list->head;

	while(cur != NULL)
	{
		char *temp = cur->data;
		printf("%s\n",temp);

		cur = cur->next;
	}
}

int main()
{
	SortedListPtr myList = SLCreate(&compareStrings);

	char *a = "b";
	char *b = "f";
	char *c = "d";
	char *d = "z";

/*	*a = "f";
	*b = "d";
	*c = "b";
*/	
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
}
