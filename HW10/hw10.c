#include "hw10.h"
//modify the main() function
#ifdef TEST_MAINFUNC

int main(int argc, char **argv)
{
  // check the arguments
  if(argc < 3)
  {
	printf("Must have a least 3 inputs\n");
	return EXIT_FAILURE;
  }
  // open the BMP file
  BMP_Open(argc[1]);
  // convert to gray scale
	// check for error in converting to gray scale

	// write the gray image to file
	// free all the images
	return EXIT_SUCCESS;
}

#endif
