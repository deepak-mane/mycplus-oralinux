/*
 * Webserver.cpp
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
#include "Webserver.h"
#include "PSutils.h"
#include "Logger.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace CPlusPlusLogging;

Webserver::Webserver() {
	LOG_DEBUG("Webserver Instance created.");
	Webserver_status = true;
}


void Webserver::status(std::string environment, std::string server, std::string action, std::string web_server, std::string web_status) {
	// TODO Auto-generated constructor stub
	printf ("Checking Status of Webserver ...\n");
	/* The argument list to pass to the "psadmin" command. */
	std::cout << environment << ": Variable environment" << std::endl;
	std::cout << server << ": Variable server" << std::endl;
	std::cout << action << ": Variable Action" << std::endl;
	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	std::string flag1 = web_server;
	std::string flag2 = web_status;
	std::string flag3 = environment;
	psutils.buildarg(flag1, flag2, flag3);
}

void Webserver::start(std::string environment, std::string server, std::string action, std::string web_server, std::string web_start) {
	// TODO Auto-generated constructor stub
	printf ("Starting Webserver ...\n");
	/* The argument list to pass to the "psadmin" command. */
	std::cout << environment << ": Variable environment" << std::endl;
	std::cout << server << ": Variable server" << std::endl;
	std::cout << action << ": Variable Action" << std::endl;
	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	std::string flag1 = web_server;
	std::string flag2 = web_start;
	std::string flag3 = environment;
	psutils.buildarg(flag1, flag2, flag3);
}

void Webserver::stop(std::string environment, std::string server, std::string action, std::string web_server, std::string web_stop) {
	// TODO Auto-generated constructor stub
	printf ("Stopping Webserver ...\n");
	/* The argument list to pass to the "psadmin" command. */
	std::cout << environment << ": Variable environment" << std::endl;
	std::cout << server << ": Variable server" << std::endl;
	std::cout << action << ": Variable Action" << std::endl;
	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	std::string flag1 = web_server;
	std::string flag2 = web_stop;
	std::string flag3 = environment;
	psutils.buildarg(flag1, flag2, flag3);
}

void Webserver::restart(std::string environment, std::string server, std::string action, std::string web_server, std::string web_restart) {
	// TODO Auto-generated constructor stub
	printf ("Re-Starting  Webserver ...\n");
	std::cout << environment << ": Variable environment" << std::endl;
	std::cout << server << ": Variable server" << std::endl;
	std::cout << action << ": Variable Action" << std::endl;
	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	std::string flag1 = web_server;
	std::string flag2 = web_restart;
	std::string flag3 = environment;
	psutils.buildarg(flag1, flag2, flag3);
}

Webserver::~Webserver() {
	LOG_DEBUG("Webserver Instance destroyed.");
	Webserver_status = false;
}
