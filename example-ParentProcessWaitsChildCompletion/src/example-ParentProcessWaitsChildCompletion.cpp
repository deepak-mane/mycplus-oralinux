//============================================================================
// Name        : example-ParentProcessWaitsChildCompletion.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv[])
{
  int i, j, k;
  int pid;

  // Fork the processes
  for(j = 0; j < 3; j++)
  {
    if (fork() == 0)
    {
        printf("starting child %d\n", j);
        // Child process - do your child stuff
        for (i = 0; i < 5; ++i)
        {
          for (k = 0; k < 10000000; ++k);
          printf("child %d printing: %d\n", j, i);
        }
         printf("child %d ending\n", j);
        // then just quit
        exit(0);
    }
  }

  j = 1;
  while (wait(NULL) > 0)
  {
    printf("%d child completed\n", j++);
  }

  // In parent now
  printf("all children terminated. in parent now\n");

  return 0;
}
