/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw12.h"



/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	if(argc < 4)
	{
		fprintf(stderr, "Must have at least 4 inputs\n");
		return EXIT_FAILURE;
	}
	// if argc < 4 then return EXIT_FAILURE
	// argv[1] - length of linked list
	// argv[2] - value of k as mentioned in josephus algorithm
	// argv[3] - value of elemDivisible
	// create head node
	Node * head = NULL;
	// create Linked list with length as argv[1]
	if(head != NULL)
	{
		fprintf(stderr, "some how set up memory for head, witchcraft is afoot\n");
		return EXIT_FAILURE;
	}
	LinkedListCreate(*head, argv[1]);
	// run josephus
	Josephus(*head, argv[2], argv[3]);
	// free the head node
	
	free(head);

	return EXIT_SUCCESS;
}

#endif
