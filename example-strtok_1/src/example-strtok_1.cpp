//============================================================================
// Name        : example-strtok_1.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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
  string myCSV = "one,two,three,four";
  vector<string> sep = split(myCSV, ',');

  // If using C++11 (which I recommend)
  /* for(string t : sep)
   *  cout << t << endl;
   */

  for(int i = 0; i < sep.size(); ++i)
    cout << sep[i] << endl;
}
