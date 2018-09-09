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
#include "PSutils.h"


PSutils::PSutils() {
	std::cout << "PSutils intance created" << std::endl;
}

PSutils::~PSutils() {
	std::cout << "PSutils intance destroyed" << std::endl;
}


//#include <unistd.h>
//int execve(const char *filename, char *const argv[],char *const envp[]);
//int main(int argc, char *argv[], char *envp[])

int PSutils::spawn(char* program, char** arg_list) {
	// TODO Auto-generated constructor stub
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


