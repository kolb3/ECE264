//edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"

//Do Not Change this function
void PrintAnswer(ListNode* head, ListNode* min1, ListNode* min2)
{
	ListNode* temp = head;
	int i;
	while(temp!=NULL)
	{
		i = 0;
		while(i < head -> treenode->dimension)
		{
			if(i == 0)
				printf("(%d, ", temp->treenode->data[i]);
			else if(i == head -> treenode->dimension-1)
				printf("%d)\n", temp->treenode->data[i]);
			else
				printf("%d, ", temp->treenode->data[i]);
			i+=1;

		}
		temp = temp->next;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min1->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d) <-> ", min1->treenode->data[i]);
		else
			printf("%d, ", min1->treenode->data[i]);
		i+=1;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min2->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d)\n", min2->treenode->data[i]);
		else
			printf("%d, ", min2->treenode->data[i]);
		i+=1;
	}
}

/*
YOU CAN EDIT BELOW THIS COMMENT
*/

#ifdef TEST_MIN
void FindMin(ListNode* head)
{
	// find pair of ListNodes with least distance between them.
	// call print Function
	ListNode * one = head;
  ListNode * two = head-> next;
	ListNode * newone = NULL;
	ListNode * newtwo = NULL;
	ListNode * temp = NULL;
	int max = 2147483647;
	int dist = 0;
	int dim = head->treenode->dimension;
 	 while(one->next != NULL )//&& one->next->next != NULL)
	{
		while(two != NULL)
		{
			dist = FindDist(one->treenode, two->treenode);
			if(dist <= max)
			{
				max = dist;
				newone = one;
				newtwo = two;
			}
			two = two -> next;
		}
		one = one -> next;
		two = one -> next;
	}

	for(int i = 0; i < dim; i++)
	{
		if(newone->treenode->data[i] > newtwo->treenode->data[i])
		{
			temp = newtwo;
			newtwo = newone;
			newone = temp;
		}
		if(newone->treenode->data[i] < newtwo->treenode->data[i])
		{
			i = dim;
		}
	}

	PrintAnswer(head, newone, newtwo);
	/*
	ENSURE the 2nd parameter of the print function (min1) is smaller than
	the 3rd parameter (min2).
	Look at README, and expected output for more details.
	*/

}
#endif


#ifdef TEST_DIST
int FindDist(TreeNode* x, TreeNode* y)
{
	//find the eucledian distance between
	// x->data and y->data
	// DO NOT FIND SQUARE ROOT (we are working with int)
	// return the distance

	int len = x->dimension;
	int diff = 0;

	for(int i = 0; i < len; i++)
	{
		diff += (x->data[i] - y->data[i]) * (x->data[i] - y->data[i]);
	}

	return diff;
}
#endif


#ifdef TEST_CREATENODE
ListNode* CreateNode(int n, int dim, int* arr)
{
	// check for malloc error
	ListNode * head = malloc(sizeof(ListNode));
	if(head == NULL)
	{
		fprintf(stderr, "memallocation of head didnt work\n");
	}
	head -> next = NULL;
	// initialize dim
	TreeNode * new = malloc(sizeof(TreeNode)); // Possibly need to create a second head
	if(new == NULL)
	{
		fprintf(stderr, "mem alloc of treenode didnt work\n");
	}
	head -> treenode = new;
	new -> dimension = dim;
	// both left and right childern will be NULL
	new -> left = NULL;
	new -> right = NULL;
	// allocate memory for data
	new -> data = malloc(sizeof(int) * dim);
	for(int i = 0; i < dim; i++)
	{
		new -> data[i] = arr[i];
	}
	// return a ListNode
	return head;
}
#endif


#ifdef TEST_LINKEDLISTCREATE
void LinkedListCreate(ListNode ** head, int n, int dim, FILE* fptr)
{
	// create temp node using CreateNode
	// read from file into an array, pass array to CreateNode
	// assign temp to that node
 	ListNode * one = NULL;
 	ListNode * two = NULL;
 	int spot = 0;
 	//fseek(fptr, 1, SEEK_CUR);
 	int * arr = malloc(sizeof(int) * n * dim);
 	for(int q = 0; q < (n * dim); q++)
 	{
		 fscanf(fptr, "%d", &arr[q]);
 	}
 	for(int i = 0; i < n; i++)
 	{
	spot = i;

	 /*for(q = 0; q < dim; q++)
	 {
		 fscanf(fptr, "%d", &arr[q]);
	 }*/

	 	if(i == 0)
	 	{
			 *head = CreateNode(n, dim, arr);
		 	one = *head;
	 	}
	 	else
	 	{
			two = CreateNode(n,dim,&arr[(spot*dim)]);
		 	one -> next = two;
		 	one = two;
	 	}

 	}
	free(arr);

	// use a loop to create nodes for the remaining elements of the list.
}
#endif
