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


using namespace std;

int main() {

	Appserver app;
	Webserver web;
	ProcessScheduler prcs;

//		app.stop();
//		web.stop();
//		prcs.stop();

	app.start();
	web.start();
	prcs.start();


//	app.start();
//	app.stop();
//	app.status();
//	app.restart();
//  app.status();

	printf("done with main program\n");

	return 0;
}
