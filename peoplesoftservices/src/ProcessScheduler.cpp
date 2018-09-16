/*
 * ProcessScheduler.cpp
 *
 *  Created on: Sep 6, 2018
 *      Author: psadm2
 */
#include <iostream>
#define C_TEXT( text ) ((char*)std::string( text ).c_str())
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ProcessScheduler.h"
#include "PSutils.h"
#include "Logger.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace CPlusPlusLogging;



ProcessScheduler::ProcessScheduler() {
	LOG_DEBUG("ProcessScheduler Instance created.");
	ProcessScheduler_status = true;
}

void ProcessScheduler::status(std::string environment, std::string server, std::string action, std::string prcs_server, std::string prcs_status) {
	// TODO Auto-generated constructor stub
	printf ("Checking Status of Process Scheduler ...\n");
	/* The argument list to pass to the "psadmin" command. */
	std::cout << environment << ": Variable environment" << std::endl;
	std::cout << server << ": Variable server" << std::endl;
	std::cout << action << ": Variable Action" << std::endl;
	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	std::string flag1 = prcs_server;
	std::string flag2 = prcs_status;
	std::string flag3 = environment;
	psutils.buildarg(flag1, flag2, flag3);
}

void ProcessScheduler::start(std::string environment, std::string server, std::string action, std::string prcs_server, std::string prcs_start) {
	// TODO Auto-generated constructor stub
	printf ("Starting Process Scheduler ...\n");
	/* The argument list to pass to the "psadmin" command. */
	std::cout << environment << ": Variable environment" << std::endl;
	std::cout << server << ": Variable server" << std::endl;
	std::cout << action << ": Variable Action" << std::endl;
	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	std::string flag1 = prcs_server;
	std::string flag2 = prcs_start;
	std::string flag3 = environment;
	psutils.buildarg(flag1, flag2, flag3);
}

void ProcessScheduler::stop(std::string environment, std::string server, std::string action, std::string prcs_server, std::string prcs_stop) {
	// TODO Auto-generated constructor stub
	printf ("Stopping Process Scheduler ...\n");
	/* The argument list to pass to the "psadmin" command. */
	std::cout << environment << ": Variable environment" << std::endl;
	std::cout << server << ": Variable server" << std::endl;
	std::cout << action << ": Variable Action" << std::endl;
	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	std::string flag1 = prcs_server;
	std::string flag2 = prcs_stop;
	std::string flag3 = environment;
	psutils.buildarg(flag1, flag2, flag3);
}

void ProcessScheduler::restart(std::string environment, std::string server, std::string action, std::string prcs_server, std::string prcs_restart) {
	// TODO Auto-generated constructor stub
	printf ("Re-Starting Process Scheduler ...\n");
	std::cout << environment << ": Variable environment" << std::endl;
	std::cout << server << ": Variable server" << std::endl;
	std::cout << action << ": Variable Action" << std::endl;
	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	std::string flag1 = prcs_server;
	std::string flag2 = prcs_restart;
	std::string flag3 = environment;
	psutils.buildarg(flag1, flag2, flag3);
}

ProcessScheduler::~ProcessScheduler() {
	LOG_DEBUG("ProcessScheduler Instance destroyed.");
	ProcessScheduler_status = false;
}
