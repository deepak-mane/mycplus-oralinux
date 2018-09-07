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

using namespace std;

void ProcessScheduler::status() {
	// TODO Auto-generated constructor stub
	printf ("Checking Status of Process Scheduler ...\n");
	/* The argument list to pass to the "psadmin" command. */
	char* arg_list[] = {	"psadmin", "-p", "status", "-d", "PRCSDOM", "/", NULL };

	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list);
}

void ProcessScheduler::start() {
	// TODO Auto-generated constructor stub
	printf ("Starting Process Scheduler ...\n");
	/* The argument list to pass to the "psadmin" command. */
	char* arg_list[] = {	"psadmin", "-p", "start", "-d", "PRCSDOM", "/", NULL };

	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list);
}

void ProcessScheduler::stop() {
	// TODO Auto-generated constructor stub
	printf ("Stopping Process Scheduler ...\n");
	/* The argument list to pass to the "psadmin" command. */
	char* arg_list[] = {	"psadmin", "-p", "stop", "-d", "PRCSDOM", "/", NULL };

	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list);
}

void ProcessScheduler::restart() {
	// TODO Auto-generated constructor stub
	printf ("Re-Starting Process Scheduler ...\n");
	/* The argument list to pass to the "psadmin" command. */
	char* arg_list[] = {	"psadmin", "-p", "stop", "-d", "PRCSDOM", "/", NULL };

	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list);

	/* The argument list to pass to the "psadmin" command. */
	char* arg_list1[] = {	"psadmin", "-p", "cleanipc", "-d", "PRCSDOM", "/", NULL };

	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list1);

	/* The argument list to pass to the "psadmin" command. */
	char* arg_list2[] = {	"psadmin", "-p", "stop", "-d", "PRCSDOM", "/", NULL };

	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list2);

}
