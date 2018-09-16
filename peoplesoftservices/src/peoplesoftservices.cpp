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
#include <sstream>
#include <cstring>


//using namespace std;
using namespace CPlusPlusLogging;



struct Environment {
	char USER[10];
	char ENV_NAME[10];
	char PS_HOME[50];
	char PS_CFG_HOME[50];
	char PS_APP_HOME[50];
	char PS_CUST_HOME[50];
	char APP_DOMAIN[10];
	char PRCS_DOMAIN[10];
	char WEB_DOMAIN[10];
	char WEB_HOME[50];
	char TEMP_DIR[10];
	char ORACLE_HOME[50];
	char TUXDIR[50];
	char MY_HOME[50];
};

int main(int argc, char* argv[]) {

	Logger* pLogger = NULL; // Create the object pointer for Logger Class
	pLogger = Logger::getInstance();
	//pLogger->enableConsoleLogging();
	LOG_ALWAYS("peoplesoftservices script started.");

	std::string info;
    // Check the number of parameters
    if (argc != 4) {
        // Tell the user how to run the program
    	std::cerr << "Usage: " << std::endl;
        std::cerr << argv[0] << " <environment> <server> <action>" << std::endl;
        std::cerr << argv[0] << " psfin01d app start" << std::endl;
        /* "Usage messages" are a conventional way of telling the user
         * how to run a program if they enter the command incorrectly.
         */
        return 1;
    } else {
    	// Something has been passed in
    	std::string environment = argv[1];
    	std::string server = argv[2];
    	std::string action = argv[3];

		std::cout << "Environment Set: " << environment << std::endl;
		std::cout << "Server Set: " << server << std::endl;
		std::cout << "Action Set: " << action << std::endl;

		std::stringstream ss1;
		ss1 << "psadmin,";


		int choice1 = 0;
		if(server == "app") {
			choice1 = 101;
		} else if (server == "web") {
			choice1 = 202;
		} else if (server == "prcs") {
			choice1 = 303;
		} else {
	        std::cerr << argv[2] << " :: Invalid Server passed .." << std::endl;
			exit(1);
		}

		int choice2 = 0;
		if(action == "status") {
			choice2 = 200;
		} else if (action == "start") {
			choice2 = 201;
		} else if (action == "stop") {
			choice2 = 202;
		} else if (action == "restart") {
			choice2 = 203;
		} else {
	        std::cerr << argv[3] << " :: Invalid Action passed .." << std::endl;
			exit(1);
		}

		std::cout << choice1 << std::endl;
		std::cout << choice2 << std::endl;
		int choice = choice1 + choice2;
		std::cout << choice << std::endl;

		ss1 << ",-d,";
		ss1 << environment;

		std::string info = ss1.str();
		std::cout << info << std::endl;


		Appserver app;
		Webserver web;
		ProcessScheduler prcs;

		// Appserver flags
		std::string app_server = "-c";
		std::string app_status = "sstatus";
		std::string app_start = "parallelboot";
		std::string app_stop = "shutdown!";
		std::string app_restart = "restart";
		std::string app_cleanipc = "cleanipc";
		std::string app_cachepurge = "purge";

		// Webserver flags
		std::string web_server = "-w";
		std::string web_status = "status";
		std::string web_start = "start";
		std::string web_stop = "shutdown!";
		std::string web_restart = "restart";


		// Process Scheduler flags
		std::string prcs_server = "-p";
		std::string prcs_status = "status";
		std::string prcs_start = "start";
		std::string prcs_stop = "stop";
		std::string prcs_restart = "restart";
		std::string prcs_cleanipc = "cleanipc";

		switch(choice) {
			case 301:
						std::cout << "301" << std::endl;
						app.status(environment,server,action,app_server,app_status);
						break;
			case 302:
						std::cout << "301" << std::endl;
						app.start(environment,server,action,app_server,app_start);
						break;
			case 303:
						std::cout << "301" << std::endl;
						app.stop(environment,server,action,app_server,app_stop);
						break;
			case 304:
						std::cout << "304" << std::endl;
						app.restart(environment,server,action,app_server,app_restart);
						break;
			case 402:
						std::cout << "402" << std::endl;
						web.status(environment,server,action,web_server,web_status);
						break;
			case 403:
						std::cout << "403" << std::endl;
						web.start(environment,server,action,web_server,web_start);
						break;
			case 404:
						std::cout << "404" << std::endl;
						web.stop(environment,server,action,web_server,web_stop);
						break;
			case 405:
						std::cout << "405" << std::endl;
						web.restart(environment,server,action,web_server,web_restart);
						break;
			case 503:
						std::cout << "503" << std::endl;
						prcs.status(environment,server,action,prcs_server,prcs_status);
						break;
			case 504:
						std::cout << "504" << std::endl;
						prcs.start(environment,server,action,prcs_server,prcs_start);
						break;
			case 505:
						std::cout << "505" << std::endl;
						prcs.stop(environment,server,action,prcs_server,prcs_stop);
						break;
			case 506:
						std::cout << "506" << std::endl;
						prcs.restart(environment,server,action,prcs_server,prcs_restart);
						break;
			default :	printf("No Switch case matched\n");
		}

    }

	LOG_ALWAYS("peoplesoftservices script completed.");
	std::cout <<""<<std::endl;
	std::cout <<""<<std::endl;
	return 0;
}
