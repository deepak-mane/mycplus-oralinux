//============================================================================
// Name        : GetInputFromUser.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<iostream>
#include<sstream>
using namespace std;

int main(int argc, char* argv[])
{
  int i, sum = 0;
  printf("argc = %d\n", argc);
  printf("Let's see what is in argv[]\n");

  if(argc > 1 && argc > 3)
  {
    for(i = 1; i < argc; i++)
    {
      printf("argv[%d] = %s\n", i, argv[i]);
      // sum = sum + attoi(argv[i]);
      sum += atoi(argv[i]);
    }
    printf("Total = %d\n", sum);
  }
  else {
    printf("Number Arguments Entered is incorrect\n");
    printf("Usage: ./add arg1 arg2 arg3\n");
  }
  return 0;
}

