//You must modify specific portions of this file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifdef TEST_MERGE
/* The merge(arr, l, m, r) is key process that assumes that arr[l..m] and
arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.*/

void merge(int arr[], int l, int m, int r)
{
 /* int l defines the start index of the left sub array
    int r defines the end index of the right sub array, if the length of array is n, then r=n-1
    int m can be defined as (l+r)/2 or l+(r-l)/2, use the later to avoid overflow
    m is the endpoint of the left sub array.
    For example- an array of size 5 has start index l= 0, and end index r= 4,
    Therefore, m = 2
*/
    int n1 = m - l + 1; //The number of elements in the left sub array
    int n2 =  r - m; //The number of elements in trhe right sub array

    //create temporary arrays dynamically to help with sorting
    int *L=malloc(sizeof(int) * n1);
    int *R=malloc(sizeof(int) * n2);

    if(L == NULL && R == NULL)
    {
	fprtinf(stderr, "malloc did not work in merge\n");
    }    

    /* NOTE:
    L[] is the left sub array
    R[] is the right sub array
    L[] is different from l. l is the starting index of left sub array.
    R[] is different from r. r is the ending index for the right sub array.
    Please do not be confused
    */
    //WRITE YOUR CODE BELOW THIS
    //Initialise variables
    int iter;
    for(iter = 0; iter < n1; iter++)
    {
      L[iter] = arr[l+iter];
    }

    for(iter = 0; iter < n2; iter++)
    {
      R[iter] = arr[m + 1 + iter];
    }

    iter = 0;
    int iter2 = 0;
    int ct = 1;

    while(iter < n1 && iter2 < n2)
    {
      if(L[iter] <= R[iter2])
      {
        arr[ct] = L[iter];
        iter++;
      }
      else
      {
        arr[ct] = R[iter2];
        iter2++;
      }
      ct++;
    }

    while(iter < n1)
    {
      arr[ct] = L[iter];
      iter++;
      ct++;
    }

    while(iter2 < n2)
    {
      arr[ct] = R[iter2];
      iter2++;
      ct++;
    }
    /*
    1.Copy data to temp arrays L[] and R[] from arr[]
    2. Merge the temp arrays back into arr[l..r]
    3. Copy the remaining elements of L[], check if there
       are any
    4. Copy the remaining elements of R[], check if there
       are any */
 //DO not modify below this line until specified in comments

}
#endif

/* Merge Sort uses recursion to call itself. Thus, efficiently dividing the array into two halves.
Then it must sort each half individually and finally join them back together using merge() into a single sorted array*/

#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r)
{
 /* int l defines the start index of the left sub array
    int r defines the end index of the right sub array
    int m has to be defined as (l+r)/2 or l+(r-l)/2, use the later to avoid overflow
    m will represent the endpoint of the left sub array.
    For example- an array of size 6 has start index l= 0, and end index r= 5,
    Therefore, m = 2*/
    if (r > 1)
    {
      int m  = l + ((r - 1) / 2);

	//MODIFY THE CODE BELOW THIS LINE
    	/*
	1. SET CONDITION for RECURSION
	2. Sort first half arr[l..m]
	3. Sort second half arr[m+1..r]
        4. Use the merge() function to arrange in order */
	//DO not modify below this line until specified in comments
      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);

      merge(arr, l, m, r);

    }

}
#endif

int main(int argc, char * * argv)
{
  // read input file
  if (argc != 3)
    {
      fprintf(stderr, "need the name of input and output file\n");
      return EXIT_FAILURE;
    }
  // open file to read
  FILE * fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      fprintf(stderr, "fopen fail\n");
      // do not fclose (fptr) because fptr failed
      return EXIT_FAILURE;
    }
  // count the number of integers
  int value;
  int count = 0;
  while (fscanf(fptr, "%d", & value) == 1)
    {
      count ++;
    }
  // allocate memory to store the numbers
  int * arr = malloc(sizeof(int) * count);
  if (arr == NULL) // malloc fail
    {
      fprintf(stderr, "malloc fail\n");
      fclose (fptr);
      return EXIT_FAILURE;
    }
  // return to the beginning of the file
  fseek (fptr, 0, SEEK_SET);
  int ind = 0;
  while (ind < count)
  {
      if (fscanf(fptr, "%d", & arr[ind]) != 1)
	    {
	       fprintf(stderr, "fscanf fail\n");
	       fclose (fptr);
	       free (arr);
	       return EXIT_FAILURE;
	    }
      ind ++;
  }
  fclose(fptr);
#ifdef TEST_MERGESORT

<<<<<<< HEAD
  mergeSort(&arr, 0, ind);

=======
  mergeSort(arr, 0, ind);  //changed the &arr to just arr
>>>>>>> eda63872c1664935d6adfa382084db6ce285f610
  // modify here between ifdef and endif
  // do not modify anywhere else in this function
  // call mergesort function and provide the correct arguments (Hint: array, start index, end index)
#endif

  int i;
   /* open the file for writing*/
  FILE * fp = fopen(argv[2], "w");
  if (fp == NULL)
    {
       fprintf(stderr, "fopen fail\n");
	// do not fclose (fp) because fp failed
       return EXIT_FAILURE;
    }
  for (i = 0; i < count; i ++)
    {
       fprintf (fp,"%d\n", arr[i]);
    }
  fclose (fp);
  free (arr);
  return EXIT_SUCCESS;
}

/* After completion of code check for FLAGS:
TEST_MERGE
TEST_MERGESORT
TEST_MERGESSORT
The three flags must be defined for grading*/
