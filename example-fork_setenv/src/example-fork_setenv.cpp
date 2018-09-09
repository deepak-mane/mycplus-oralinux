//============================================================================
// Name        : example-fork_setenv.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
/* Spawn a child process running a new program. PROGRAM is the name
 of the program to run; the path will be searched for this program.
 ARG_LIST is a NULL-terminated list of character strings to be
 passed as the program's argument list. Returns the process ID of
 the spawned process. */
int spawn(char* program, char** arg_list) {
	pid_t child_pid;
	/* Duplicate this process. */
	child_pid = fork();
	if (child_pid != 0)
		/* This is the parent process. */
		return child_pid;
	else {
		   	 	char *argv1[] = { "/bin/sh", "-c", "env", 0 };
				char *envp[] =
				{
				"USER=psadm2",
				"HOME=/home/psadm2"
				"LOGNAME=psadm2",
				"PS_HOME=/opt/oracle/psft/pt/ps_home8.56.08",
				"PS_CFG_HOME=/home/psadm2/psft/pt/8.56",
				"PS_APP_HOME=/opt/oracle/psft/pt/fscm_app_home",
				"TUXDIR=/opt/oracle/psft/pt/bea/tuxedo/tuxedo12.2.2.0.0",
				"ORACLE_HOME=/opt/oracle/psft/db/oracle-server/12.1.0.2",
				0
				};
				execve(argv1[0], &argv1[0], envp);
				fprintf(stderr, "Oops!\n");

		  FILE *in; //File stream
		  char buff[64]; // setting buffer

		  if( !(in = popen("env", "r")))
		    return 0;;

		  while(fgets(buff, sizeof(buff), in) != NULL)
		    cout << buff;

		    pclose(in);


		/* Now execute PROGRAM, searching for it in the path. */
		execvp(program, arg_list);
		/* The execvp function returns only if an error occurs. */
		fprintf (stderr, "an error occurred in execvp\n");
		abort();
	}
}
int main() {
	/* The argument list to pass to the "ls" command. */
	char* arg_list[] = {
		"psadmin", /* argv[0], the name of the program. */
		"-c",
		"sstatus",
		"-d",
		"APPDOM",
		"/",
		NULL /* The argument list must end with a NULL. */
	};

/* Spawn a child process running the "ls" command. Ignore the
 returned child process ID. */
	spawn ("psadmin", arg_list);
	printf ("done with main program\n");
	return 0;
}
