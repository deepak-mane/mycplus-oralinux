//============================================================================
// Name        : GetInputFromUser.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<iostream>
#include<sstream>

using namespace std;

bool isNumber(string s) {
    char* p;
    strtol(s.c_str(), &p, 10);
    return *p == 0;
}

int getNumber(string s) {
    char* p;
    return strtol(s.c_str(), &p, 10);
}

int main() {
	 string strInput;
	 int nums[4];
	 int cnt;


	 do
	 {
	  cnt = 0;
	  cout << "Input 4 values: ";
	  getline(cin, strInput, '\n');

	  stringstream ss(strInput);
	  string s;

		  while (getline(ss, s, ' '))   {
			  if(isNumber(s))  {
				  if(cnt < 4)  {
					  nums[cnt] = getNumber(s);
				  }
				  cnt++;
			  }
		  }

		  if(cnt!=4) {
			  cout<<"Invalid number of inputs!\n";
		  }
	 }	while(cnt!=4);

	 int i;
	 cout<<"The 4 numbers input by the user are: ";
	 for(i = 0; i < 4; i++)  {
		 cout<<nums[i]<<" ";
	 }
	 cout<<endl;
}
