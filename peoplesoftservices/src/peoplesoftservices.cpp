//============================================================================
// Name        : peoplesoftservices.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#define C_TEXT( text ) ((char*)std::string( text ).c_str())
#include "PSutils.h"
#include "Appserver.h"
#include "ProcessScheduler.h"
#include "Webserver.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"
// Logger specific
#include <errno.h>
#include <pthread.h>
// Code Specific Header Files(s)
#include "Logger.h"
#include <fstream>

//using namespace std;
using namespace CPlusPlusLogging;


int main() {
	   Logger* pLogger = NULL; // Create the object pointer for Logger Class
	   pLogger = Logger::getInstance();

//	   pLogger->enableConsoleLogging();
//	   pLogger->updateLogLevel(LOG_LEVEL_INFO);
//	   pLogger->error("Message Logged using C++ Interface, Log level: LOG_ERROR");
//	   pLogger->alarm("Message Logged using C++ Interface, Log level: LOG_ALARM");
//	   pLogger->always("Message Logged using C++ Interface, Log level: LOG_ALWAYS");
//	   pLogger->buffer("Message Logged using C++ Interface, Log level: LOG_INFO");
//	   pLogger->info("Message Logged using C++ Interface, Log level: LOG_BUFFER");
//	   pLogger->trace("Message Logged using C++ Interface, Log level: LOG_TRACE");
//	   pLogger->debug("Message Logged using C++ Interface, Log level: LOG_DEBUG");

	std::cout <<""<<std::endl;
	std::cout <<""<<std::endl;
//	if(!ofs) {
//	  std::cout << "Couldn't open peoplesoftservices.out file."  << std::endl;
//	  return 1;
//	}

	LOG_ALWAYS("peoplesoftservices script started.");

//	PSutils::GetStream() << "test\n";

	Appserver app;
	Webserver web;
	ProcessScheduler prcs;
/////////////////////////////////////////////////////////
	LOG_INFO("Stopping Appserver");
	app.stop();
	LOG_INFO("Stopping Webserver");
	web.stop();
	LOG_INFO("Stopping Process Scheduler");
	prcs.stop();
/////////////////////////////////////////////////////////
	LOG_INFO("Starting Appserver");
	app.start();
	LOG_INFO("Starting Webserver");
	web.start();
	LOG_INFO("Starting ProcessScheduler");
	prcs.start();
/////////////////////////////////////////////////////////
	LOG_INFO("Checking Status - Appserver");
	app.status();
	LOG_INFO("Checking Status - Webserver");
	prcs.status();
	LOG_INFO("Checking Status - ProcessScheduler");
	web.status();
/////////////////////////////////////////////////////////
	LOG_ALWAYS("peoplesoftservices script completed.");
	std::cout <<""<<std::endl;
	std::cout <<""<<std::endl;
	return 0;
}
