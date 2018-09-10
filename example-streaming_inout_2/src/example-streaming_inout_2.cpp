//============================================================================
// Name        : example-streaming_inout_2.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {
	char s[1000];   // s is a character array and value of s cannot be changed
	char *lastline;    // lastline is a variable pointer to a char
	char *penultimate;
	int line;

	line = 0;

	while (!cin.fail()) {
		cin.getline(s, 1000);
		if (!cin.fail()) {
			line++;
			if (line > 2)
				delete penultimate;
			if (line > 1)
				penultimate = lastline;
			lastline = new char[strlen(s) + 1];
			strcpy(lastline, s);
		}
		cout << s << endl;
	}
	if (line == 0)
		exit(0);
	if (line == 1) {
		cout << "The last line was '" << lastline << "'" << endl;
	} else {
		cout << "The last two lines were '" << penultimate << "' and '"
				<< lastline << "'" << endl;
	}
}
