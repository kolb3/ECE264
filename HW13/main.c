/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw13.h"

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc is less than 2 then, return EXIT_FAILURE
	// input file is specified through the Makefile.

	if(argc < 2)
	{
		fprintf(stderr, "need 2 inputs at least\n");
		return EXIT_FAILURE;
	}

	// open file to read
	FILE * fptr = fopen(argv[1], "r");	
	// check for fopen fail. If so, return EXIT_FAILURE
	if(fptr == NULL){
	fprintf(stderr, "F open did not open\n");
	return EXIT_FAILURE;
	}
	// count the number of integers in the file.
	int val;
	int count = 0;
	while(fscanf(fptr, "%d", &val) == 1){
	//fread(&val, sizeof(int), 1, fptr);
	count++;
	}
	// allocate memory to store the numbers
	fseek(fptr,0,SEEK_SET);
	int * ary = malloc(sizeof(int) * count);
	// check for malloc fail, if so, return EXIT_FAILURE
	if(ary == NULL)
	{
		fprintf(stderr, "array memory was not created\n");
		return EXIT_FAILURE;
	}
	// use fscanf to read the file, and store its contents into an array.
	//fseek(fptr, 0, SEEK_SET);
	for(int i = 0; i < count; i++)
	{
		fscanf(fptr, "%d", &ary[i]);
	}
	// create head node to store the head of the linked list.
	Node * newhead = NULL; //CreateNode(ary[0]);
	// call the appropriate function to create the rest of the linked list, with the values of the array.
	LinkedListCreate(&newhead, count, ary);
	// Divide is a function to break the lists into smaller sublists.
		// You are supposed to find the mid-point of the list, and then break the list into two lists.
		// Then the sub-lists are broken down further into smaller sub-lists.
		// Refer to the example in the README
	Divide(&newhead);
	// Tip: check for memory errors.

	fclose(fptr);
	free(ary);
	return EXIT_SUCCESS;
}

#endif
