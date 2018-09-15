// ***
// *** Please modify this file, as indicated
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sort.h"


void printArray(int * arr, int size)
{
  int ind;
  for (ind = 0; ind < size; ind ++)
    {
      fprintf(stdout, "%d\n", arr[ind]);
    }
}



//============================ONLY EDIT BELOW THIS COMMENT============================//
#ifdef TEST_COMP
int comparator(const void *a, const void *b)
{
    //type cast both the parameters to the type const int*) a:
	//FOR EXAMPLE: const int* ia = (const int *) a;

  //if parameter2 > parameter1; return -1
  if(b > a)
  {
    return(-1);
  }
	//if parameter2 == parameter1; return 0
  if (b == a)
  {
    return(0);
  }
	//if parameter2 < parameter1; return 1
  if(b < a)
  {
    return(1);
  }
}
#endif


#ifdef TEST_COUNT
int countFromFile(char* file_name)
{
  int size = 0; //needs to be intialized so that we know the starting point
  int x;  //just a random variable to hold a number until the end of feof
  // open file to read
  fopen(file_name, "r");
  // count the number of integers using a loop
  while(!feof(file_name))
  {
    fscanf(file_name, "%d", &x);  //see if you can do without this(seems extrenous)
    size++;
  }
  // at the end of the loop close file_pointer
  fclose(file_name);

  return(size);
}
#endif

#ifdef TEST_FILL
void fillArray(int* arr, int count, char* file_name)
{
  int iter = 0;
  // open file to read
  fopen(file_name, "r");
  for(iter = 0; iter < count: iter++)
  {
    fscanf(file_name, "%d", &arr[iter]);
  }
  //How to read the file?
	// run a loop, from index = 0 to "count", and use: fscanf(file_pointer, "%d", &arr[index]);
	// at the end of the loop close file_pointer
  fcloes(file_name);
}
#endif

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
  // input file will be specified from the terminal - test files are made available in inputs folder

  // check for missing input file, if so, "return EXIT_FAILURE;"
  if(argv[1] = NULL)
  {
    fprintf(stderr, "fopen %s fail\n", argv[1]);
    return EXIT_FAILURE;
  }
  // use argv[1] to save the file name, you will use this file name to call the countFromFile(), and fillArray() functions
      //FOR EXAMPLE: char* file_name = argv[1];
  char* file_name = argv[1];

  // call the countFromFile(file_name); and store the number of elements in the file.
  int count  = countFromFile(file_name);
  // allocate memory to store the numbers (initialize an array)
	int arr = malloc(count);
  // check for malloc fail, if so, "return EXIT_FAILURE;"
  if(arr == NULL)
  {
    fprintf(stderr, "malloc fail\n");
    return EXIT_FAILURE
  }
  // call the fillArray(arr, count, file_name); and store the values from the file in the array.
  fillArry(arr, count, file_filename);
  // Use qsort() function, after defining the comparator() function - "qsort (arr, count, sizeof(int), comparator);"
  qsort(arr, count, sizeof(int), comparator);
  // call the printArray() function provided to you.
  printArray(arr, count);

  return EXIT_SUCCESS;
}
#endif
