#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])	{

  char * message = calloc(argc+1, sizeof(char));

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
