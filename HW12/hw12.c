/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw12.h"

#ifdef LINKEDLIST

// Do not modify the below program, we are using ifdef block for
// ease of grading. Please include this flag in your Makefile
void LinkedListPrint(Node * head)
{

	Node *temp = head;

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


/********** Do Not modify the file above this line, you should modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int value)
{
	// allocate memory for the new Node*	
 	
	Node * newhead = malloc(sizeof(Node)); //do i need this??????
	
	if(newhead == NULL)
	{
		fprintf(stderr, "memory allocation error in create\n");
		return EXIT_FAILURE;
	}

	// check memory allocation fails
	// create a Node* with the value as 'value'(input argument).
	newhead -> value = value;
//	newhead -> next = newhead;

}
#endif

#ifdef TEST_LINKEDLISTCREATE
// 1. head: the head of the singly linkedlist.
// 2. length: the length of the singly linkedlist.

// This function creates and initializes a singly linkedlist with length as 'length'(input argument),
// The values of the nodes within the singly linkedlist will be the same as array indddices.
// For example, if the singly linkedlist length is 4, the value of the nodes will be 0 1 2 3
void LinkedListCreate(Node * * head, int length)
{
	Node * t; //not sure if i need it???

	// check if length is not negative
	if(length <= 0)
	{
		fprintf(stderr, "Length needs to be a positive integer greater than 0\n");
		return EXIT_FAILURE;
	}
	// create linked list of length as 'length'
	int i = 0;
	while(i < length && t != NULL)
	{
		Node * n = Createnode(i);
		printf("Entered the while create loop\n");
		t -> next = n;
		t = t -> next;
		i++;
	}
	// do not return anything
}
#endif



#ifdef TEST_JOSEPHUS

// 1. head: the head of the singly linkedlist.
// 2. k : this variable will be used for counting if count = k, the element will be out.
// 3. elemDivisible : this variable will be used for printing. When the number of
//    remaining nodes in linked list is divisible by elemDivisible then you should 
//    print the remaining LinkedList with print functin provided to you.

// This function should solve the josephus problem using the singly linkedlist.

void Josephus(Node ** head, int k, int elemDivisible)
{
	// implement the algorithm here
	// remember to free the memory of the nodes
	// print the linked list using our function when number of nodes remaining is divisible by elemDivisible
	int c = 0;
	Node * p = head;
	Node * q = p -> next;
 	

}

#endif
