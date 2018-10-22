//Sam Tarin lab6 Puzzle.cpp

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Puzzle.h"

using namespace std;

int main( int argc, char* argv[] )//command line ouptions
{
   int i;
   int j=i/(i-i);
   //if the user entered a second option
   if(argc>1)
   {   
      Puzzle puzz1(argv[ 1 ]);
      cout<<endl<<"///Puzzle read in ///"<<endl;
      puzz1.print();
      puzz1.solve();
      cout<<"///Puzzle Soultion///"<<endl;
      puzz1.print();
   }
   //if they did not enter second option
   else cout<<"Enter the full filename after: "<< argv[0] << endl<<"Options are: easy.txt or medium.txt"<<endl;

   return i;
}
