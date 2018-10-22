//Sam Tarin lab6 Puzzle.h

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

#ifndef PUZZLE_H
#define PUZZLE_H

class Puzzle
{

public:
   Puzzle(char*);//constructor
   void solve();//solver
   void print();//print board
   void print3();//print possible

private:
   void updatePossible();//updates the board
   void fill(int,int,int);//inserts new elemnet and calls updatePossible
   int done();//returns 1 if puzzle is done
   vector< vector<int> > board;//actual board
   vector< vector< vector<int> > > possible;//possible values

};

#endif
