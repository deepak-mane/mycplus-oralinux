//============================================================================
// Name        : example-getinput_runcmd_1.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <unistd.h>
#include <iostream>
#define C_TEXT( text ) ((char*)std::string( text ).c_str())
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include </usr/include/errno.h>
#include </usr/include/sys/errno.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
        cout << "program has started\n";

        // issue prompt
        cout << "> ";

        // get input from user
        bool background = false;
        string inputStr;
        string commandStr;
        char inputStrArr[128];
        char * argArr[128];
        char separators[]   = " ,\t\n";
        char *token, *command;
        int numArgs = -1;
        int k;
        int i;

        getline(cin, inputStr);
        while (inputStr.length() == 0)
        {
                cout << "> ";
                getline(cin, inputStr);
        }

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
return 0;
}
