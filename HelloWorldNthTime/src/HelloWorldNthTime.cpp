//============================================================================
// Name        : HelloWorldNthTime.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setfill, std::setw
#include <ctime>
#include <string>
#include <errno.h>
#include <pthread.h>
// Code Specific Header Files(s)
#include "Logger.h"

#include <unistd.h>


using namespace std;

#include <fstream>

int main()
{
   ofstream out( "textfile.txt" );
   if( !out )
   {
      cout << "Couldn't open file."  << endl;
      return 1;
   }

   out << "This is output to the file.\n";

   out.close();


   enum Color { red,
	   	   	   green,
			   blue };

   Color r = red;
   switch(r)
   {
       case red  : std::cout << "red\n";   break;
       case green: std::cout << "green\n"; break;
       case blue : std::cout << "blue\n";  break;
   }


   return 0;
}
