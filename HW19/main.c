// Please modify this file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw19.h"


#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
	// check for input error
	if(argc < 3)
	{
		fprintf(stderr, "need 3 inputs\n");
		return EXIT_FAILURE;
	}

	// open the file
	FILE * fptr = fopen(argv[1], "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "fopen did not work\n");
		return EXIT_FAILURE;
	}
	// n is availavle in argv[1]
	int n;
	fscanf(fptr, "%d", &n);
	// dim is available in argv[2]
	int dim;
	fsanf(fptr, "%d", &dim);
	// input file is in argv[3]
	ListNode * newhead = NULL;
	// Create linkedList
	LinkedListCreate(&newhead, n, dim, fptr);
	// call MakeCluster
	MakeCluster(&newhead);

	fclose(fptr);
	ListNode * temp = newhead->next;

	while(newhead->next != NULL)
	{
		temp = newhead->next->next;
		free(newhead->next->treenode->data);
		free(newhead->next->treenode->left);
		free(newhead->next->treenode->right);
		free(newhead->next->treenode);
		free(newhead->next);
		newhead->next = temp;
	}
	free(newhead->treenode->data);
	free(newhead->treenode->left);
	free(newhead->treenode->right);
	free(newhead->treenode);
	free(newhead);
}
#endif
