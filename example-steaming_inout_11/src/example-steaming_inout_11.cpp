//============================================================================
// Name        : example-steaming_inout_11.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ofstream out("test.txt");
  if(! out)
  {
    cout<<"Cannot open output file\n";
       return 1;
  }
  char nums[4]={'a','b','c','d'};
  out.write((char *)nums,sizeof(nums));
  out.close();

  ifstream in("test.txt");
  if(! in)
  {
    cout<<"Cannot open input file\n";
       return 1;
  }
  in.read((char *)& nums,sizeof(nums));

  for(int i=0;i<4;i++)
    cout<<nums[i]<<' ';
  cout<<'\n';
  cout<<in.gcount()<<"characters read\n";
  in.close();
  return 0;
}
