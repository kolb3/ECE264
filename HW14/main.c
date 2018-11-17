/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw14.h"


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

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc is less than 2 then, return EXIT_FAILURE
	// input file is specified through the Makefile.
	if(argc < 2)
	{
		fprintf(stderr, "need 2 inputs\n");
		return EXIT_FAILURE;
	}
	// open file to read
	FILE * fptr = fopen(argv[1], "r");
	// check for fopen fail. If so, return EXIT_FAILURE
	if(fptr == NULL)
	{
		fprintf(stderr, "fopen failed to open file\n");
		return EXIT_FAILURE;
	}
	// count the number of integers in the file.
	int count = 0;
	int val;
	while(fscanf(fptr, "%d", &val) == 1)
	{
	count++;
	}
	// allocate memory to store the numbers
	fseek(fptr,0,SEEK_SET);
	// check for malloc fail, if so, return EXIT_FAILURE
	int * arr = malloc(sizeof(int) * count);
	if(arr == NULL)
	{
		fprintf(stderr, "mem allocation of array didnt work\n");
	}	
	// use fscanf to read the file for its contents.
	for(int i=0;i<count;i++)
	{
		fscanf(fptr, "%d", &arr[i]);
	}	
	// create head node, which corresponds to the head of the linked-list.
	Node * newhead = NULL;
	// You must now use the appropriate function to construct the remaining list.
	LinkedListCreate(&newhead, count, arr);
	
	// call MergerSort() function for final output.
		// This will call a recursive function.
		// The input list will be divided into two sub-lists recursively,
		// Then the contents of the sub-lists are compared and merged back to form the
		// sorted output list.
	MergeSort(&newhead);	
	// use the provided function to print the final list.
	LinkedListPrint(&newhead);	
	// Tip: Check for memory errors.
	free(arr);
	free(newhead);
	fclose(fptr);	

	return EXIT_SUCCESS;
}

#endif
