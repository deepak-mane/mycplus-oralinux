/*
 * Appserver.cpp
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
#include "Appserver.h"
#include "PSutils.h"
#include <string.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"

Appserver::Appserver() {
	std::cout << "Appserver Instance created." << std::endl;
	Appserver_status = true;
}



void Appserver::status() {
	// TODO Auto-generated constructor stub
	printf ("Checking Status of Appserver ...\n");

	/* The argument list to pass to the "psadmin" command. */
	char* arg_list[] = {	"psadmin", "-c", "sstatus", "-d", "APPDOM", "/", NULL };

	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list);
}

void Appserver::start() {
	// TODO Auto-generated constructor stub
	printf ("Starting  Appserver ...\n");
	/* The argument list to pass to the "psadmin" command. */
	char* arg_list[] = {	"psadmin", "-c", "parallelboot", "-d", "APPDOM", "/", NULL };

	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list);
}

void Appserver::stop() {
	// TODO Auto-generated constructor stub
	printf ("Stopping  Appserver ...\n");
	/* The argument list to pass to the "psadmin" command. */
	char* arg_list[] = {	"psadmin", "-c", "shutdown!", "-d", "APPDOM", "/", NULL };

	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list);
}

void Appserver::restart() {
	// TODO Auto-generated constructor stub
	printf ("Re-Starting  Appserver ...\n");
	/* The argument list to pass to the "psadmin" command. */
	char* arg_list[] = {	"psadmin", "-c", "shutdown!", "-d", "APPDOM", "/", NULL };

	PSutils psutils;
	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list);
	char* arg_list1[] = {	"psadmin", "-c", "cleanipc", "-d", "APPDOM", "/", NULL };

	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list1);

	char* arg_list2[] = {	"psadmin", "-c", "purge", "-d", "APPDOM", "/", NULL };

	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list2);

	char* arg_list3[] = {	"psadmin", "-c", "parallelboot", "-d", "APPDOM", "/", NULL };

	/* Spawn a child process running the "psadmin" command. Ignore the returned child process ID. */
	psutils.spawn ("psadmin", arg_list3);
}

Appserver::~Appserver() {
	std::cout << "Appserver  Instance destroyed." << std::endl;
	Appserver_status = false;
}
