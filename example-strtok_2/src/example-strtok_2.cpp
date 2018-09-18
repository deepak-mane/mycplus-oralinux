//============================================================================
// Name        : example-strtok_2.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <sstream>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>


using namespace std;

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;

  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }

  return internal;
}

int main(int argc, char **argv) {
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


		stringstream ss1;
		ss1 << "psadmin,";

		int choice1 = 0;
		if(server == "app") {
			choice1 = 101;
			ss1 << "-c,";
		} else if (server == "web") {
			choice1 = 202;
			ss1 << "-w,";
		} else if (server == "prcs") {
			choice1 = 303;
			ss1 << "-p,";
		} else {
	        std::cerr << argv[2] << " :: Invalid Server passed .." << std::endl;
			exit(1);
		}

		int choice2 = 0;
		if(action == "status") {
			choice2 = 200;
			if(server == "app") {
				ss1 << "sstatus";
			} else {
				ss1 << "status";
			}
		} else if (action == "start") {
			choice2 = 201;
			if(server == "app") {
				ss1 << "parallelboot";
			} else {
				ss1 << "start";
			}
		} else if (action == "stop") {
			choice2 = 202;
			if(server == "app") {
				ss1 << "shutdown!";
			} else if(server == "web") {
				ss1 << "shutdown";
			} else {
				ss1 << "stop";
			}
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

		string info = ss1.str();
		cout << info << endl;
		//string info = "psadmin,-c,sstatus,-d,APPDOM";
		//vector<string> arg_list = split(info, ',');

//		for(int i = 0; i < arg_list.size(); ++i) {
//		cout << arg_list[i] << endl;
//		}

        // get input from user
        bool background = false;
        string inputStr = info;
        string commandStr;
        char inputStrArr[128];
        char * argArr[128];
        char separators[]   = " ,\t\n";
        char *token, *command;
        int numArgs = -1;
        int k;
        int i;



        for(i=0; i<inputStr.length(); i++)
                inputStrArr[i] = inputStr[i];
        inputStrArr[i] = '\0';

    token = strtok( inputStrArr, separators );
        command = token;

        for (i=0; token[i] != '\0'; i++)
        {
                commandStr += token[i];

        }

        argArr[++numArgs] = token;

        while( token != NULL )
        {
                token = strtok( NULL, separators );
                argArr[++numArgs] = token;
        }

        if (argArr[numArgs] == "&")
        {
                background = true;
                argArr[numArgs] = NULL;
        }
        else
                argArr[++numArgs] = NULL;

    // is command built-in?
        if(commandStr == "quit")
        {
                cout << "============= quit called\n";
                return 0;
        }
        else
        {
        // execute external command
            int childpid, flag;
            childpid = fork();
            cout << "forking\n";
            if (childpid == 0) // child code
            {
                    cout << "Process ID: child: " << getpid();
                    flag = execvp(command, argArr);

                    if (flag < 0)
                    {
                            perror("execvp failed");
                    }
            }
            else if (childpid > 0) // parent code
            {
                    cout << "Process ID: " << getpid();
            }
            else // fork unsuccessful
            {
                    cout << "\nError: fork failed\n";
            }
    } // end else



    }
}
