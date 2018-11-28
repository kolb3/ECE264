// Edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"


#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
	// check for input error
  if(argc < 2)
  {
    fprintf(stderr, "Need at least 2 inputs\n");
    return EXIT_FAILURE;
  }
	// open the file
  FILE * fptr = fopen(argv[1], "r");
	// input file is in argv[1]

	// n is the first element in the file
  int n = 0;
  fscanf(fptr, "%d", &n);
	// dim is the second element in the file
  int dim = 0;
  fscanf(fptr, "%d", &dim);
	// the rest of the data in the file are the datapoints.
  ListNode * newhead = NULL;
	// call LinkedListCreate
  LinkedListCreate(&newhead, n, dim, fptr);
	// call FindMin
  FindMin(newhead);
  ListNode * temp = NULL;
  fclose(fptr);
	while(newhead->next != NULL)
	{
		temp = newhead->next->next;
		free(newhead->next->treenode->data);
  		free(newhead->next->treenode);
  		free(newhead->next);
		newhead->next = temp;
	}
	free(newhead->treenode->data);
	free(newhead->treenode);
	free(newhead);
}
#endif