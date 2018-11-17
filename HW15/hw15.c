/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw15.h"

#ifdef LINKEDLIST
// Do not modify this function.
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
			printf("%d\n",temp->value);
		}
		temp=temp->next;
	}
}
#endif


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
{
	/*
	Create a new Node with `value` set to `val`. Set `next` to NULL.
	*/
	Node * header = malloc(sizeof(Node));
	header->value = val;
	header->next = NULL;
	return(header);
}
#endif

#ifdef TEST_LINKEDLISTCREATE

void LinkedListCreate(Node ** head, char* name)
{
	/*
	Create a linked list from the input file referenced by `name`.
	*/
	//Node * one = (*head);
	Node * two = NULL;
	int x;
	FILE * fptr = NULL;
	fptr = fopen(name, "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "Fopen failed\n");
		fclose(fptr);
		return; 
	}
	fscanf(fptr,"%d",&x);
	(*head) = CreateNode(x);
	Node *one = *head;
	while(fscanf(fptr,"%d",&x) == 1)
	{
		two = CreateNode(x);
		one->next = two;
		one = two;
	}
	fclose(fptr);
}
#endif
#ifdef TEST_REMOVED
//This function will remove repetitions of a linked list value.

void RemoveDuplicate(Node *headRef)
{
	/*
	This function will remove repetitions from the linked list referenced by headRef.
	Each time we check for a new Node in the linked list, we will check if it is distinct from
	the Nodes already present in the list ( upto the previous Node).
	So for each occurrence after its first, we will be deleting that node.
	To delete a node: we will map the next Node of the previous Node to the Node after the current Node.
	Print the linked list after all repetitions have been removed. Use the function given to you for priniting.
	*/
	Node * check = NULL;
	Node * two = NULL;
	Node * q = headRef;
	/*if(q->next == NULL || q == NULL)
	{
		return;
	}*/
	//int elem = 1;
	while(q != NULL && q->next != NULL)
	{	
		check = q;
		while(check->next != NULL )//&& q->value != check->value)
		{
			//two = check->next;
			if(q->value == check->next->value)
			{
				two = check->next;
				check->next = check->next->next;
				free(two);
			}
			else
			{
				check = check->next;
			}
			//two = two->next
			//check = two;
		}
		/*for(int i = 1; i<elem -1; i++)
		{
			if(check->value == q->value)
			{
				int p = 1;
				while(p < (elem -1))
				{
					p++;
					two = two->next;
				}
				two->next = q->next->next;
			}
			check = check->next;
			two = headRef;
		}*/
		q = q->next;
	}
	
	LinkedListPrint(headRef);
	
}
#endif
