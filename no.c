#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])	{

  char message[20];
  memset(message, '\0', sizeof(message));

  if(argc>1) {
	strcpy(message, argv[1]);
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
