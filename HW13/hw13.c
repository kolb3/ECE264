/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw13.h"

#ifdef LINKEDLIST
// Do not modify this function, we are using this within ifdef block for
// ease of grading.
void LinkedListPrint(Node * * source)
{

	Node *temp = * source;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");
}
#endif


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
//val: value of the element of the node to be created
{
	Node * head = malloc(sizeof(Node));
	// Define a new variable of type Node
	// Initialize "next", and "value" appropriately 
	head->value = val;
	head->next = NULL;
	
	//return the newNode
	return(head);
}
#endif

#ifdef TEST_LINKEDLISTCREATE
//head: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

//This function will create and initialize the singly linkedlist with length=len,

void LinkedListCreate(Node * * source, int len, int* arr)
{
	// This function is similar to the one in HW12.
	// Tip: use CreateNode(arr[index])
	*(source) = CreateNode(arr[0]);
	Node * one = (*source);
	Node * two = NULL;
	//one = CreateNode(arr[0]);
	for(int i = 1; i < len; i++)
	{
		two = CreateNode(arr[i]);
		one->next = two;
		one = two;
	}
}
#endif


#ifdef TEST_SPLIT
// source is the Node corresponding to the head of the list
// head1 is the list corresponding upper half of the list. (After Partition)
// head2 is the list corresponding lower half of the list. (After Partition)
void SplitList(Node* source, Node** head1, Node** head2) 
{ 
	// Find the mid point of the list.
	int elem = 1;
	Node * q = source;
	//int t = q;
	while(q->next != NULL)
	{
		elem++;
		q = q->next;
	}
		//in case of an even number of nodes, mid point will be floor(<num_elements>/2)
			//Example: 1,2,3,4

	int mid = elem / 2;
	if((elem % 2) != 0)
	{
		mid++;
	}
	//if((mid % 2) == 0)
	//{
		*head1 = source;
		q = *head1;
		for(int i = 1; i < mid; i++)
		{
			q = q->next;
		}
		*head2 = q->next;
		q->next = NULL;
	//}
	/*if((mid % 2) != 0)
	{
		*head1 = source;
		q = *head1;
		for(int i = 1; i < mid; i++)
		{
			q = q->next;
		}
		*head2 = q->next;
		q->next = NULL;
	}*/	
		//in case of an odd number of nodes, mid point will be <num_elements>/2
			//Example: 1,2,3,4,5
				// The list should split into 1,2,3 and 4,5				

    	// Tip: head1 will point to the source node.
	// Tip: head2 will point to the mid-point of the list.
	// Tip: Ensure you break the link between the sub-lists.
} 
#endif


#ifdef TEST_DIV
void Divide(Node** source) 
{ 
	// Declare a node, to hold the current head of source list.
	Node * pthead = *source;
	Node * a = NULL;
	Node * b = NULL;	
	// Declare nodes, to hold the two the heads of the two sub-lists.
	// Check for the base case -- length 0 or 1
		// if so, return;
	if(pthead == NULL || pthead->next == NULL)
	{
		return;
	}
	// Use SpiltList(...) to partition the list into sub lists.
	SplitList(pthead, &a, &b);
	// Use LinkedListPrint(...); to print the upper sub-list.
	// Use LinkedListPrint(...); to print the lower sub-list
		// DO NOT USE YOUR OWN PRINT FUNCTION.

	LinkedListPrint(&a);
	LinkedListPrint(&b);
	
	Divide(&a);
	Divide(&b);
	 // Recursively Divide(...) both sub-lists, to find their respective mid-points
	 // till only one or no elements are left in the sub-lists.
} 
#endif

