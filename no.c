#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_STRING 20

int main(int argc, char *argv[])	{

  char * message = calloc(INPUT_STRING, sizeof(char));

  if(argc>1) {
		strcpy(message, argv[1]);
  }
	else {
		strcpy(message, "n\0");
	}

  while(1)	{
    if(argc>1) {
	  	printf("%s\n", message);
		}
		else {
	  	printf("n\n");
		}
  } 
  return 0; 
}
