//
// MODIFY THIS FILE AS DIRECTED
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vector.h"



#ifdef TEST_COMP
int cmp(const void *a, const void *b)
{
	Vector *one = (Vector *)a;
	Vector *two = (Vector *)b;
	int ans;

	if(one->x < two->x)
	{
		ans = -1;
	}
	if(one->x == two->x)
	{
		ans = 0;
	}
	if(one->x > two->x)
	{
		ans = 1;
	}
    return (ans);
}
#endif

#ifdef TEST_COUNT
int numberOfElements(char* in_file_name)
{
    //initialize file_pointer, and open file in read mode.
        //Please note that we are working with binary files.

    FILE * fptr = fopen(in_file_name, "rb");
    fseek(fptr, 0, SEEK_END);
    long info = ftell(fptr);
    float numelem = info / sizeof(Vector);
    fclose(fptr);
    return(numelem);

    //use fseek(fptr, 0, SEEK_END); to point to the end of the file.
    //use long where = ftell(file_pointer); to get the size of the file.
    //use float numelem = where / sizeof(Vector); to obtain the number of elements
    //return numelem; to send the number of elements back to main().
}
#endif

#ifdef TEST_FILL
void fillVector(Vector* vector, int count, char * in_file_name)
{
    // open binary file to read after initializing file_pointer

    FILE * fptr = fopen(in_file_name, "rb");
    fread(vector, sizeof(Vector), count, fptr);

    //How to read the file?
        //use fread(vector, sizeof(Vector), count, file_pointer)
    
    fclose(fptr);
}
#endif

#ifdef TEST_WRITE
void writeFile(Vector* vector, int count, char* out_file_name)
{
    // open binary file to write after initializing file_pointer

    FILE * fptr = fopen(out_file_name, "wb");

    //How to write to the file?
        //use fwrite(vector, sizeof(Vector), count, file_pointer)

    fwrite(vector, sizeof(Vector), count, fptr);
    fclose(fptr);
}
#endif
