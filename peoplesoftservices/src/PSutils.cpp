/*
 * PSutils.cpp
 *
 *  Created on: Sep 6, 2018
 *      Author: psadm2
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
// for fd included
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>

#include "PSutils.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"



/* since pipes are unidirectional, we need two pipes.
   one for data to flow from parent's stdout to child's
   stdin and the other for child's stdout to flow to
   parent's stdin */

#define NUM_PIPES          2
#define PARENT_WRITE_PIPE  0
#define PARENT_READ_PIPE   1

int pipes[NUM_PIPES][2];

/* always in a pipe[], pipe[0] is for read and
   pipe[1] is for write */
#define READ_FD  0
#define WRITE_FD 1

#define PARENT_READ_FD  ( pipes[PARENT_READ_PIPE][READ_FD]   )
#define PARENT_WRITE_FD ( pipes[PARENT_WRITE_PIPE][WRITE_FD] )
#define CHILD_READ_FD   ( pipes[PARENT_WRITE_PIPE][READ_FD]  )
#define CHILD_WRITE_FD  ( pipes[PARENT_READ_PIPE][WRITE_FD]  )


PSutils::PSutils() {
	std::cout << "PSutils instance created" << std::endl;
}

PSutils::~PSutils() {
	std::cout << "PSutils instance destroyed" << std::endl;
}


//#include <unistd.h>
//int execve(const char *filename, char *const argv[],char *const envp[]);
//int main(int argc, char *argv[], char *envp[])

int PSutils::spawn(char* program, char** arg_list) {
	// TODO Auto-generated constructor stub
	int outfd[2];
	int infd[2];

	pipe(outfd); /* Where the parent is going to write to */
	pipe(infd); /* From where parent is going to read */

	close(STDOUT_FILENO);
	close(STDIN_FILENO);

	dup2(outfd[0], STDIN_FILENO);
	dup2(infd[1], STDOUT_FILENO);

	close(outfd[0]); /* Not required for the child */
	close(outfd[1]);
	close(infd[0]);
	close(infd[1]);


	/* Spawn a child process running a new program. PROGRAM is the name
	 of the program to run; the path will be searched for this program.
	 ARG_LIST is a NULL-terminated list of character strings to be
	 passed as the program's argument list. Returns the process ID of
	 the spawned process. */
	pid_t child_pid, pid;
	int status;

	/* Duplicate this process. */
	child_pid = fork();

	char *envp[] =
	{
	"USER=psadm2",
	"HOME=/home/psadm2"
	"LOGNAME=psadm2",
	"_JAVA_OPTIONS=-Djava.security.egd=file:/dev/./urandom",
	"PS_HOME=/opt/oracle/psft/pt/ps_home8.56.08",
	"PS_CFG_HOME=/home/psadm2/psft/pt/8.56",
	"PS_APP_HOME=/opt/oracle/psft/pt/fscm_app_home",
	"PS_JRE=/opt/oracle/psft/pt/ps_home8.56.08/jre",
	"PS_LIBPATH=/opt/oracle/psft/pt/ps_home8.56.08/bin",
	"PATH=/opt/oracle/psft/pt/ps_home8.56.08/jre/bin:/opt/oracle/psft/pt/ps_home8.56.08/python:/opt/oracle/psft/pt/ps_home8.56.08/appserv:/opt/oracle/psft/pt/ps_home8.56.08/setup:/opt/oracle/psft/pt/bea/tuxedo/tuxedo12.2.2.0.0/bin:.:/opt/oracle/psft/db/oracle-server/12.1.0.2/bin:/opt/oracle/psft/db/oracle-server/12.1.0.2/OPatch:/opt/oracle/psft/db/oracle-server/12.1.0.2/perl/bin:/usr/lib64/qt-3.3/bin:/usr/local/bin:/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/sbin:/opt/puppetlabs/bin:/opt/oracle/psft/pt/ps_home8.56.08/bin:/opt/oracle/psft/pt/ps_home8.56.08/bin/sqr/ORA/bin:/opt/oracle/psft/pt/ps_home8.56.08/verity/linux/_ilnx21/bin:/home/psadm2/bin",
	"TUXDIR=/opt/oracle/psft/pt/bea/tuxedo/tuxedo12.2.2.0.0",
	"ORACLE_HOME=/opt/oracle/psft/db/oracle-server/12.1.0.2",
	0
	};


	if (child_pid == 0){
		/* CHILD */
		//printf("Child: executing program\n");
		std::cout << "Child: executing " << program << std::endl;

		char input[100];

		close(outfd[0]); /* These are being used by the child */
		close(infd[1]);

		write(outfd[1],"2^32\n",5); /* Write to child_pid stdin */

		input[read(infd[0],input,100)] = 0; /* Read from child_pid stdout */

		printf("%s",input);

//		std::ifstream input_file("peoplesoftservices.input");	// open the input file
//		if (!input_file.is_open()) { 		// check for successful opening
//			std::cout << "Input file could not be opened! Terminating!" << std::endl;
//			return 1;
//		}

		std::ofstream output_file("peoplesoftservices.output"); // open the output file
		if (!output_file.is_open()) { // check for successful opening
			std::cout << "Output file could not be opened! Terminating!" << std::endl;
			return 1;
		}
		// read as long as the stream is good - any problem, just quit.
		// output is each number times two on a line by itself
		// char s[1000]; which is subsitute for char input[100]
		char *lastline;

		while (!std::cin.fail()) {
			std::cin.getline(input, 1000);
			if (!std::cin.fail()) {
				lastline = input;
			}
			std::cout << "Reading... " << input << std::endl;
		}
		std::cout << "The last line was '" << lastline << "'" << std::endl;
//		input_file.close();
		output_file.close();
		std::cout << "Done!" << std::endl;


//		PSutils::GetStream() << input;
//		PSutils::GetStream() << "test\n";
		close(outfd[1]);
		close(infd[0]);

		/* Now execute PROGRAM, searching for it in the path. */
		execvp(program, arg_list);
		//only get here if exec failed
		perror("execve failed");
	}else if (child_pid > 0){
		/* PARENT */

		if( (pid = wait(&status)) < 0){
		perror("wait");
		_exit(1);
		}
		printf("thread ended successfully\n");
		//	    printf("Parent: finished\n");

	}else{
		perror("fork failed");
		_exit(1);
	}

	return 0;
}


