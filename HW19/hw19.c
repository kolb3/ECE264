// You can modify this file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw19.h"

// DO NOT MODIFY THIS FUNCTION
void PrintAns(ListNode* head, ListNode* min1, ListNode* min2)
{
	int i;
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
MODIFY BELOW THIS COMMENT
*/


#ifdef TEST_CENT
ListNode* FindCentroid(TreeNode* x, TreeNode* y)
{
	// Create a new node
	// new -> treenode.left should be x
	// new -> treenode.right should be y
	// x -> treenode.data should be less than y -> treenode.data (refer to README)
	ListNode * new = malloc(sizeof(ListNode));
	TreeNode * newcent = malloc(sizeof(TreeNode));
	if(new == NULL || newcent == NULL)
	{
		fprintf(stderr, "malloc fail in centroid\n");
	}
	new->treenode = newcent;
	// Use a loop to average the data from the two parameters (x and y).
	/*
	EXAMPLE
	Average x->treenode.data[0] and y->treenode.data[0] to new->treenode.data[0]
	Average x->treenode.data[1] and y->treenode.data[1] to new->treenode.data[1]
	and so on
	*/
	new -> treenode->left = x;
	new -> treenode->right = y;

	for(int i = 0; i < x->dimension; i++)
	{
		new->treenode->data[i] = (x->data[i] + y->data[i]) / 2 ;
	}
	return(new);
	// Return the new node
}
#endif


#ifdef TEST_DIST
int FindDist(TreeNode* x, TreeNode* y)
{
	//Same as previous HW
	int len = x->dimension;
	int diff = 0;

	for(int i = 0; i < len; i++)
	{
		diff += (x->data[i] - y->data[i]) * (x->data[i] - y->data[i]);
	}

	return diff;
}
#endif


#ifdef TEST_FUSE
ListNode* Fuse(ListNode* head, ListNode* fuse1, ListNode* fuse2)
{

	// Create a new ListNode element using findCentroid function.
	// The new->treenode.data will hold the averaged values of the two parameters' data (fuse1, and fuse2)
	// add the new ListNode to the list.
	// remove the fuse1 and fuse2 from the list. (Do NOT free)
	// you may want to return head from this function (depending on your implementation)
	ListNode * element = malloc(sizeof(ListNode));
	TreeNode * eltree = malloc(sizeof(TreeNode));
  if(element == NULL || eltree == NULL)
	{
		fprintf(stderr, "malloc error in fuse\n");
	}
	element -> treenode = eltree;
	element ->treenode->dimension = head->treenode->dimension;
	for(int i = 0; i < (head->dimension); i++)
	{
		element = FindCentroid(fuse1->treenode,fuse2->treenode);
		//element->treenode->left = fuse1->treenode->data;
		//element->treenode->right = fuse2->treenode->data;
	}
	ListNode * temp = head;
	while(temp->next != NULL)
	{
		if(temp->next == fuse1)
		{
			temp->next = fuse1->next;
		}
		if(temp->next == fuse2)
		{
			temp->next = fuse2->next;
		}
		temp = temp->next;
	}
	temp->next = element;
	//return(element);
}
#endif


#ifdef TEST_CREATENODE
ListNode* CreateNode(int n, int dim, int* arr)
{
	// Same as previous HW
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
	// Same as previous HW
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
}
#endif

#ifdef TEST_CLUSTER
void MakeCluster(ListNode** head)
{
	// Walk through the linked list.
	// find pair of nodes with minimum distance.
	// fuse the two nodes into one node.
	// call print function
	// repeat till one node is remaining.
	ListNode * one = *head
	ListNode * two = NULL;
	ListNode * newone = NULL;
	ListNode * newtwo = NULL;
	//ListNode * hold = NULL;
	ListNode * newhead = NULL;
	int max = (2^32) -1;
	int dist = 0;
	while(one->next != NULL)
	{
		two = one->next;
		while(two != NULL)
		{
			dist = FindDist(one->treenode, two->treenode);
			if(dist<=max);
			{
				max = dist;
				newone = one;
				newtwo = two;
			}
			two = two->next;
		}
		*head = Fuze(head, newone, newtwo); // might need to set this equal to something
		PrintAnswer(head, newone, newtwo);

		one = one->next;
	}
	*head = one;
}
#endif
