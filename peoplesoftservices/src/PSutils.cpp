/*
 *
 * PSutils.cpp
 *  Created on: Sep 6, 2018
 *      Author: psadm2
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
// for fd included
#include <spawn.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Appserver.h"
#include "PSutils.h"
#include "Logger.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace CPlusPlusLogging;




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
	// TODO Auto-generated constructor stub
	LOG_DEBUG("PSutils instance created");
}

PSutils::~PSutils() {
	LOG_DEBUG("PSutils instance destroyed");
}


int PSutils::spawn(char* program, char** arg_list) {
	std::cout << "LOC --- --- PSutils::spawn:: execvp" << std::endl;

	/* Spawn a child process running a new program. PROGRAM is the name
	 of the program to run; the path will be searched for this program.
	 ARG_LIST is a NULL-terminated list of character strings to be
	 passed as the program's argument list. Returns the process ID of
	 the spawned process. */

	pid_t child_pid, pid;
	int status;

	/* Duplicate this process. */
	child_pid = fork();

//	char *envp[] =
//	{
//	"USER=psadm2",
//	"HOME=/home/psadm2"
//	"LOGNAME=psadm2",
//	"_JAVA_OPTIONS=-Djava.security.egd=file:/dev/./urandom",
//	"PS_HOME=/opt/oracle/psft/pt/ps_home8.56.08",
//	"PS_CFG_HOME=/home/psadm2/psft/pt/8.56",
//	"PS_APP_HOME=/opt/oracle/psft/pt/fscm_app_home",
//	"PS_JRE=/opt/oracle/psft/pt/ps_home8.56.08/jre",
//	"PS_LIBPATH=/opt/oracle/psft/pt/ps_home8.56.08/bin",
//	"PATH=/opt/oracle/psft/pt/ps_home8.56.08/jre/bin:/opt/oracle/psft/pt/ps_home8.56.08/python:/opt/oracle/psft/pt/ps_home8.56.08/appserv:/opt/oracle/psft/pt/ps_home8.56.08/setup:/opt/oracle/psft/pt/bea/tuxedo/tuxedo12.2.2.0.0/bin:.:/opt/oracle/psft/db/oracle-server/12.1.0.2/bin:/opt/oracle/psft/db/oracle-server/12.1.0.2/OPatch:/opt/oracle/psft/db/oracle-server/12.1.0.2/perl/bin:/usr/lib64/qt-3.3/bin:/usr/local/bin:/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/sbin:/opt/puppetlabs/bin:/opt/oracle/psft/pt/ps_home8.56.08/bin:/opt/oracle/psft/pt/ps_home8.56.08/bin/sqr/ORA/bin:/opt/oracle/psft/pt/ps_home8.56.08/verity/linux/_ilnx21/bin:/home/psadm2/bin",
//	"TUXDIR=/opt/oracle/psft/pt/bea/tuxedo/tuxedo12.2.2.0.0",
//	"ORACLE_HOME=/opt/oracle/psft/db/oracle-server/12.1.0.2",
//	0
//	};


	if (child_pid == 0){
		/* CHILD */
		//printf("Child: executing program\n");
		std::cout << "Child: executing " << program << std::endl;
//		char buffer[100];
//		int count;


		// std::ofstream file_;
		// file_.open("mytext.txt"); can also as below
		std::ofstream file_("mytext.txt");
		if(file_.is_open()) {
			file_ << "Hi \n";
			file_.close();
		}



		// To pause the script std::cin.get();

		/* Now execute PROGRAM, searching for it in the path. */
		execvp(program, arg_list); perror("execve failed");
		//only get here if exec failed
	} else if (child_pid > 0) {
		/* PARENT */

		std::string line_;
		std::ifstream file_1("mytext.txt");
		if(file_1.is_open()) {
			while(getline(file_1, line_)) {
				std::cout << line_ << std::endl;
			}
			file_1.close();
		} else {
			std::cout << "File mytext.txt cannot be opened." << std::endl;
		}

		/* Close fds not required by child. Also, we don't
		   want the exec'ed program to know these existed */


		if( (pid = wait(&status)) < 0) {
			perror("wait");
			_exit(1);
		}
		printf("fork process ended successfully\n");
	} else {
		perror("fork failed");
		_exit(1);
	}

	return 0;
}



void PSutils::wrapper(std::string term1, std::string term2, std::string term3) {
	std::cout << "LOC --- --- PSutils::wrapper" << std::endl;
	PSutils psutils;

	char * arg_list[6];
	std::string psadmin_1 = "psadmin";
	std::string psadmin_2 = term1;
	std::string psadmin_3 = term2;
	std::string psadmin_4 = "-d";
	std::string psadmin_5 = term3;
	std::string psadmin_6 = "/";

		std::cout << psadmin_1 << ": psadmin_1" << std::endl;
		std::cout << psadmin_2 << ": psadmin_2" << std::endl;
		std::cout << psadmin_3 << ": psadmin_3" << std::endl;
		std::cout << psadmin_4 << ": psadmin_4" << std::endl;
		std::cout << psadmin_5 << ": psadmin_5" << std::endl;
		std::cout << psadmin_6 << ": psadmin_6" << std::endl;

	arg_list[0] = (char*)psadmin_1.c_str();
	arg_list[1] = (char*)psadmin_2.c_str();
	arg_list[2] = (char*)psadmin_3.c_str();
	arg_list[3] = (char*)psadmin_4.c_str();
	arg_list[4] = (char*)psadmin_5.c_str();
	arg_list[5] = (char*)psadmin_6.c_str();
	arg_list[6] = NULL;

	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn (arg_list[0], arg_list);
}

void PSutils::buildarg(std::string flag1, std::string flag2, std::string flag3) {
	std::cout << "LOC --- --- PSutils::buildarg" << std::endl;
	std::cout << flag1 << ": FLAG1" << std::endl;
	std::cout << flag2 << ": FLAG2" << std::endl;
	std::cout << flag3 << ": FLAG3" << std::endl;

	if(flag1 == "-c" && flag2 == "status") {
		//----------status app-------------
		std::cout << "LOC --- --- PSutils::buildarg:: -c sstatus" << std::endl;
		PSutils psutils;
		std::stringstream ss;
		ss << "sstatus";

		//std::string term1 = flag1,term2 = "sstatus", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);

	}

	if(flag1 == "-c" && flag2 == "stop") {
		std::cout << "LOC --- --- PSutils::buildarg:: -c stop" << std::endl;
		PSutils psutils;
		std::stringstream ss;
		ss << "shutdown!";
		//----------stop app-------------
		//std::string term1 = flag1,term2 = "shutdown!", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);

		//----------cleanipc-------------
		ss << std::endl;
		ss << "cleanipc";
		//std::string term1 = flag1,term2 = "cleanipc", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);

		//----------purge cache----------
		ss << std::endl;
		ss << "purge";
		//std::string term1 = flag1,term2 = "purge", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);

	}


	if(flag1 == "-c" && flag2 == "start") {
		//----------start app-------------
		std::cout << "LOC --- --- PSutils::buildarg:: -c start" << std::endl;
		PSutils psutils;
		std::stringstream ss;
		ss << "parallelboot";

		//std::string term1 = flag1,term2 = "parallelboot", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);

	}


	if(flag1 == "-c" && flag2 == "restart") {
		std::cout << "LOC --- --- PSutils::buildarg:: -c restart" << std::endl;
		PSutils psutils;
		std::stringstream ss;
		ss << "shutdown!";
		//----------stop app-------------
		//std::string term1 = flag1,term2 = "shutdown!", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);
		//----------cleanipc-------------
		ss << std::endl;
		ss << "cleanipc";
		//std::string term1 = flag1,term2 = "cleanipc", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);

		//----------purge cache----------
		ss << std::endl;
		ss << "purge";
		//std::string term1 = flag1,term2 = "purge", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);

		//----------start app-------------
		ss << std::endl;
		ss << "parallelboot";
		//std::string term1 = flag1,term2 = "parallelboot", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);

	}

	if(flag1 == "-w" && flag2 == "status") {
		//----------status web-------------
		std::cout << "LOC --- --- PSutils::buildarg:: -w status" << std::endl;
		PSutils psutils;
		std::stringstream ss;
		ss << "status";

		//std::string term1 = flag1,term2 = "sstatus", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);

	}

	if(flag1 == "-w" && flag2 == "stop") {
		std::cout << "LOC --- --- PSutils::buildarg:: -w stop" << std::endl;
		PSutils psutils;
		std::stringstream ss;
		ss << "shutdown!";
		//----------stop web-------------
		//std::string term1 = flag1,term2 = "shutdown!", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);

	}

	if(flag1 == "-w" && flag2 == "start") {
		std::cout << "LOC --- --- PSutils::buildarg:: -w start" << std::endl;
		PSutils psutils;
		std::stringstream ss;
		ss << "start";
		{	//----------start web-------------
			std::string term1 = flag1,term2 = "start", term3 = flag3;
			psutils.wrapper(flag1,ss.str(),flag3);
		}
	}

	if(flag1 == "-w" && flag2 == "restart") {
		std::cout << "LOC --- --- PSutils::buildarg:: -w restart" << std::endl;
		PSutils psutils;
		std::stringstream ss;
		ss << "shutdown!";
		//----------stop web-------------
		//std::string term1 = flag1,term2 = "shutdown!", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);


		//----------purge cache----------
		// Need to find way to delete files/dir

		//----------start web-------------
		ss << std::endl;
		ss << "start";
		//std::string term1 = flag1,term2 = "start", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);
	}

	if(flag1 == "-p" && flag2 == "status") {
		//----------status prcs -------------
		std::cout << "LOC --- --- PSutils::buildarg:: -p status" << std::endl;
		PSutils psutils;
		std::stringstream ss;
		ss << "sstatus";

		//std::string term1 = flag1,term2 = "status", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);

	}

	if(flag1 == "-p" && flag2 == "stop") {
		std::cout << "LOC --- --- PSutils::buildarg:: -p stop" << std::endl;
		PSutils psutils;
		std::stringstream ss;
		ss << "stop";
		//----------stop prcs-------------
		//	std::string term1 = flag1,term2 = "stop", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);
	}

	if(flag1 == "-p" && flag2 == "start") {
		std::cout << "LOC --- --- PSutils::buildarg:: -c start" << std::endl;
		PSutils psutils;
		std::stringstream ss;
		ss << "start";
		//----------start prcs-------------
		//	std::string term1 = flag1,term2 = "start", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);
	}

	if(flag1 == "-p" && flag2 == "restart") {
		std::cout << "LOC --- --- PSutils::buildarg:: -p restart" << std::endl;
		PSutils psutils;
		std::stringstream ss;
		ss << "stop";
		//----------stop prcs-------------
		//	std::string term1 = flag1,term2 = "stop", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);

		//----------cleanipc-------------
		ss << std::endl;
		ss << "cleanipc";
		//	std::string term1 = flag1,term2 = "cleanipc", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);

		//----------purge cache----------
		// Need to find way to delete files/dir

		//----------start prcs-------------
		ss << std::endl;
		ss << "start";
		//	std::string term1 = flag1,term2 = "start", term3 = flag3;
		psutils.wrapper(flag1,ss.str(),flag3);
	}
}

