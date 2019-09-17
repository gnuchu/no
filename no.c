#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define VERSION 40

int main(int argc, char **argv)	{

  int vflag = 0;
  int c;

  char *message = calloc(argc+1, sizeof(char));

  while ((c = getopt (argc, argv, "v")) != -1) {
    switch(c) {
      case 'v':
        vflag = 1;
        break;
    }
  }

  if (vflag == 1) {
    printf("%d\n", VERSION);
    exit(0);
  } 
  else {
    if(argc>1 && !vflag) {
      strcpy(message, argv[1]);
    }
    else {
      strcpy(message, "n\0");
    }

    while(1)  {
      if(argc>1) {
        printf("%s\n", message);
      }
      else {
        printf("n\n");
      }
    } 

  }

  return 0; 
}
