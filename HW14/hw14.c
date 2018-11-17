/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw14.h"


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
//val: value of the element of the node to be created
{
	// same as previous homeworks
	Node * head = malloc(sizeof(Node));
	head -> value = val;
	head -> next = NULL;
	return(head);
}
#endif

#ifdef TEST_LINKEDLISTCREATE
//source: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

void LinkedListCreate(Node * * source, int len, int* arr)
{
	// Refer HW13 and HW12
	// Tip: use CreateNode(arr[index])
	(*source) = CreateNode(arr[0]);
	Node * one = (*source);
	Node * two = NULL;
	for(int i = 1; i<len;i++)
	{
		two = CreateNode(arr[i]);
		one -> next = two;
		one = two;
	}
}
#endif


#ifdef TEST_SPLIT
// source is the head of the list to be split.
// head1 is the head of the upper sub-list.
// head2 is the head of the lower sub-list.

void SplitList(Node* source, Node** head1, Node** head2)
{
	// Refer HW13
	int elem = 1;
	Node * q = source;
	while(q -> next != NULL)
	{
		elem++;
		q = q->next;
	}
	int mid = elem / 2;
	if((elem % 2) != 0)
	{
		mid++;
	}
	*head1 = source;
	q = *head1;
	for(int i = 1; i < mid; i++)
	{
		q = q->next;
	}
	*head2 = q->next;
	q->next = NULL;
} 
#endif

#ifdef TEST_MERGE
// upper is the upper sub-list to be merged
// lower is the lower sub-list to be merged
Node* Merge(Node* upper, Node* lower) 
{ 
	// Check for the base cases. (When either sub-list is NULL)
  	Node*pt = NULL;
	// Pick the larger between upper and lower, and recur appropriately.
	if(upper == NULL)
	{
		return lower;
	}
	else if(lower == NULL)
	{
		return upper;
	}

	if(upper->value <= lower->value)
	{
		pt = upper;
		pt->next = Merge(upper->next, lower);
	}
	else
	{
		pt = lower;
		pt->next = Merge(upper, lower->next);
	}
	// return the merged array
	return(pt);
} 
#endif

#ifdef TEST_SORT
// source is the head of the list to for which MergeSort is to be performed.
void MergeSort(Node** source) 
{ 
	// Declare a node, to hold the current head of the source list.
	Node * new = (*source);
	Node * a = NULL;
	Node * b = NULL;	
	// Declare nodes, to hold the two the heads of the two sub-lists.
  
	// Check for the base case -- length 0 or 1
		// if so, return;
	if(new == NULL || new -> next == NULL)
	{
		return;
	}
	// Use SpiltList() to partition the list into sub lists.
		// This will partiton the source list, into two lists (As done in the previous homework)
	SplitList(new, &a, &b); 
	// Recursively sort the sub-lists by calling MergeSort() on the upper and lower sub-lists.
		// MergeSort() is a recursive function, and MergeSort() needs to be called
		// on both sub-lists (obtained after partitioning)
	MergeSort(&a);
	MergeSort(&b);
	// Merge the two sorted lists together, using the Merge()
	*source = Merge(a,b);
} 
#endif

