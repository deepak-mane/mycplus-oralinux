//============================================================================
// Name        : print_env.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/* The ENVIRON variable contains the environment. */
extern char** environ;


int main() {
	//system("/opt/oracle/psft/pt/ps_home8.56.08/psconfig_new.sh");
	char** var;
	for (var = environ; *var != NULL; ++var)
	printf ("%s\n", *var);
	return 0;

}

