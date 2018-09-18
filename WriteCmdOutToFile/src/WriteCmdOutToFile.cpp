//============================================================================
// Name        : WriteCmdOutToFile.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <fstream>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;


void print_process_environment(pid_t pid) {
	int fd;
	char filename[24];
	char environment[8192];
	size_t length;
	char* next_var;
	/* Generate the name of the environ file for the process. */
	snprintf(filename, sizeof(filename), "/proc/%d/environ", (int) pid);
	/* Read the contents of the file. */
	fd = open(filename, O_RDONLY);
	length = read(fd, environment, sizeof(environment));
	close(fd);
	/* read does not NUL-terminate the buffer, so do it here. */
	environment[length] = '\0';

	/* Loop over variables. Variables are separated by NULs. */
	next_var = environment;
	while (next_var < environment + length) {
		/* Print the variable. Each is NUL-terminated, so just treat it
		 like an ordinary string. */
		//printf("%s\n", next_var);
		outFile << printf("%s\n", next_var) << endl;
		/* Advance to the next variable. Since each variable is
		 NUL-terminated, strlen counts the length of the next variable,
		 not the entire variable list. */
		next_var += strlen(next_var) + 1;
	}
}

string GetStdoutFromCommand(string cmd) {

	string data;
	FILE * stream;
	const int max_buffer = 256;
	char buffer[max_buffer];
	cmd.append(" 2>&1");

	stream = popen(cmd.c_str(), "r");
	if (stream) {
		while (!feof(stream))
			if (fgets(buffer, max_buffer, stream) != NULL)
				data.append(buffer);
		pclose(stream);
	}
	return data;
}

int main(int argc, char* argv[]) {



	//  ofstream outFile;
	//	outFile.open(outputFileName);




	string ls = GetStdoutFromCommand(
			"psadmin -c sstatus -d APPDOM | grep -v Picked");

	if (outFile.is_open()) {
		pid_t pid = (pid_t) atoi(argv[1]);
		print_process_environment(pid);
		outFile << ls << endl;
		outFile.close();
	} else {
		cout << "Could not create file: " << outputFileName << endl;
	}
	return 0;
}

