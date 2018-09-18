//============================================================================
// Name        : example-vector_1.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <sys/stat.h>
#include <fcntl.h> //for fd file
#include <stringstream>
//using namespace std;

int main( void )
{
    int status;
    std::string info;
    char *args[3];
    std::stringstream ss;

    ss << "psadmin -c sstatus -d APPDOM >test.txt";
    info = ss.str();
    args[0] = "/bin/ls";        // first arg is the full path to the executable
    args[1] = "-lart";
    args[2] = NULL;// list of args must be NULL terminated
	int fd = open("psoft-out.txt", O_WRONLY|O_CREAT|O_APPEND, 0644);
	if (fd < 0) { perror("open"); abort(); }

	if (dup2(fd, 1) < 0) { perror("dup2"); abort(); }


    if ( fork() == 0 ) {
//      execv( args[0], args ); // child: call execv with the path and the args
    	system(info); // execute the UNIX command "ls -l >test.txt"
    	//std::cout << std::ifstream("test.txt").rdbuf();
    } else {
        wait( &status );        // parent: wait for the child (not really necessary)
        perror("wait");
       _exit(1);
    }
        		  printf("thread ended successfully\n");
        	    //	    printf("Parent: finished\n");
    }
    //close(fd);
