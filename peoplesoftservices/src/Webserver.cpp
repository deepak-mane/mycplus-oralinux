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

using namespace std;

void Webserver::status() {
	// TODO Auto-generated constructor stub
	printf ("Checking Status of Appserver ...\n");
	/* The argument list to pass to the "psadmin" command. */
	char* arg_list[] = {	"psadmin", "-c", "sstatus", "-d", "APPDOM", "/", NULL };

	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list);
}

void Webserver::start() {
	// TODO Auto-generated constructor stub
	printf ("Starting Webserver ...\n");
	/* The argument list to pass to the "psadmin" command. */
	char* arg_list[] = {	"psadmin", "-w", "start", "-d", "peoplesoft" , NULL };

	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list);
}

void Webserver::stop() {
	// TODO Auto-generated constructor stub
	printf ("Stopping Webserver ...\n");
	/* The argument list to pass to the "psadmin" command. */
	char* arg_list[] = {	"psadmin", "-w", "shutdown!", "-d", "peoplesoft" , NULL };

	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list);
}


