/*
 * Appserver.cpp
 *
 *  Created on: Sep 6, 2018
 *      Author: psadm2
 */
#include <iostream>
#define C_TEXT( text ) ((char*)std::string( text ).c_str())
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "Appserver.h"
#include "PSutils.h"
#include <cstring>
#include "Logger.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace CPlusPlusLogging;

Appserver::Appserver() {
	LOG_DEBUG("Appserver Instance created.");
	Appserver_status = true;
}


void Appserver::status(std::string environment, std::string server, std::string action, std::string app_server, std::string app_status) {
	// TODO Auto-generated constructor stub
	printf ("Checking Status of Appserver ...\n");
	std::cout << environment << ": Variable environment" << std::endl;
	std::cout << server << ": Variable server" << std::endl;
	std::cout << action << ": Variable Action" << std::endl;
	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	std::string flag1 = app_server;
	std::string flag2 = app_status;
	std::string flag3 = environment;
	psutils.buildarg(flag1, flag2, flag3);
}

void Appserver::start(std::string environment, std::string server, std::string action, std::string app_server, std::string app_start) {
	// TODO Auto-generated constructor stub
	printf ("Starting  Appserver ...\n");
	/* The argument list to pass to the "psadmin" command. */
	//char* arg_list[] = {	"psadmin", "-c", "parallelboot", "-d", "APPDOM", "/", NULL };
	std::cout << environment << ": Variable environment" << std::endl;
	std::cout << server << ": Variable server" << std::endl;
	std::cout << action << ": Variable Action" << std::endl;
	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	std::string flag1 = app_server;
	std::string flag2 = app_start;
	std::string flag3 = environment;
	psutils.buildarg(flag1, flag2, flag3);
}

void Appserver::stop(std::string environment, std::string server, std::string action, std::string app_server, std::string app_stop) {
	// TODO Auto-generated constructor stub
	printf ("Stopping  Appserver ...\n");
	std::cout << environment << ": Variable environment" << std::endl;
	std::cout << server << ": Variable server" << std::endl;
	std::cout << action << ": Variable Action" << std::endl;
	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	std::string flag1 = app_server;
	std::string flag2 = app_stop;
	std::string flag3 = environment;
	psutils.buildarg(flag1, flag2, flag3);
}

void Appserver::restart(std::string environment, std::string server, std::string action, std::string app_server, std::string app_restart) {
	// TODO Auto-generated constructor stub
	printf ("Re-Starting  Appserver ...\n");
	std::cout << environment << ": Variable environment" << std::endl;
	std::cout << server << ": Variable server" << std::endl;
	std::cout << action << ": Variable Action" << std::endl;
	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	std::string flag1 = app_server;
	std::string flag2 = app_restart;
	std::string flag3 = environment;
	psutils.buildarg(flag1, flag2, flag3);
}

Appserver::~Appserver() {
	LOG_DEBUG("Appserver  Instance destroyed.");
	Appserver_status = false;
}
