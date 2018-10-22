//Sam Tarin lab6 Puzzle.cpp

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Puzzle.h"

using namespace std;

//Constructor
Puzzle::Puzzle(char* filename)
{   
   //declare object and open file
   ifstream inSudokuFile(filename);
   // If it did not open
   if(!inSudokuFile) 
   {
      cerr<<"File could not be oppened"<<endl;
      exit(1);
   }
   
   int number;
   vector<int> row;
   //read in file
   while(inSudokuFile>>number)
   {
      if(number>=0 && number<10) //if it's a number
      {
         row.push_back(number);//put number in a row
         if(row.size()==9)
         {
            board.push_back(row);//push whole row
            row.erase(row.begin(),row.end());
         }
         if(board.size()==9) break;//break once filled
      }         
   }
   //close file
   inSudokuFile.close();

   vector< vector<int> > grid;
   
   //initialize possible values
   int i,j,k;
   for(i=0;i<9;i++)
   {
      for(j=0;j<9;j++)
      {
         for(k=0;k<9;k++)
         {
            row.push_back(1);//set 1 is possible            
         }
         grid.push_back(row);//push a row
      }
      possible.push_back(grid);//push whole gird
   }
}

void Puzzle::solve()
{
   

   int i,j,k,l,m,numpossible,newval,z,col,row;

   //Set filled values to all 2's in possible
   for(i=0;i<9;i++)//i is row
   {
      for(j=0;j<9;j++)//j is column
      {  
         if((board[i][j])!=0)//if there is already a value set possible to 2
         {
            for(k=0;k<9;k++)//k is value
            {
               possible[i][j][k]=2;//two means cell is filled
            }
         }
      }
   }

//Loop and fill values
while(!done())//loop until solved
{
   updatePossible();

   //find and fill location that have only one possible value
   for(i=0;i<9;i++)//i is row
   {
      for(j=0;j<9;j++)//j is column
      {  
         if(possible[i][j][0]==2) continue;//if full skip value
         numpossible=0;
         for(k=0;k<9;k++)//k+1 is value
         {
            if(possible[i][j][k]==1)
            {
               numpossible++;
               newval=k+1;//if a number is possible store its value in newval
            }
            if(numpossible>1) break;
         }
         if(numpossible==1)
         {
            fill(newval,i,j);//call fill to insert only possible value
         }
      }
   }


   //seach columns for only one possible spot for a particular number
   for(i=0;i<9;i++)//i is row
   {
      for(k=0;k<9;k++)//k+1 is value
      {  
         numpossible=0;
         for(j=0;j<9;j++)//j is column
         {
            if(board[i][j]==k+1) break;//value in column already skip to next value
            if(possible[i][j][k]==1)
            {
               numpossible++;
               col=j;
            }
            if(numpossible>1) break;//call fill to insert value
         }
         if(numpossible==1)
         {
            //cout<<"column search: ";
            fill(k+1,i,col);
         }
      }
   }

   //search rows for only one possible spot for a particular number
   for(j=0;j<9;j++)//j is column
   {
      for(k=0;k<9;k++)//k+1 is value
      {  
         numpossible=0;
         for(i=0;i<9;i++)//i is row
         {
            if(board[i][j]==k+1) break;//value in column already skip to next value
            if(possible[i][j][k]==1)
            {
               numpossible++;
               row=i;
            }
            if(numpossible>1) break; 
         }
         if(numpossible==1) //if only one possible position
         {  
            //cout<<"for column search: \n";
            fill(k+1,row,j);//call fill to insert value
         }
      }
   }

   //search blocks only one possible spot for a particular number
   for(i=0;i<9;i+=3)//i is row
   {
      for(j=0;j<9;j+=3)//j is column
      {  
         for(k=0;k<9;k++)//k+1 is value
         {
            numpossible=0;
            for(l=0;l<3;l++)//l is row
            {
               for(m=0;m<3;m++)//m is column
               {
                  //cout<<"checking location:"<<i+l<<","<<j+m<<" for a "<<k+1<<endl;
                  if(board[i+l][j+m]==k+1) break;//value in block already skip to next value
                  if(possible[i+l][j+m][k]==1)
                  {
                     numpossible++;
                     row=i+l;
                     col=j+m;
                     //cout<<"Numpossible incremeneted for "<<k+1<<" at "<<row<<","<<col<<endl;
                  }
                  if(numpossible>1) break;
               }
               if(board[i+l][j+m]==k+1) break;//break out of second loop
               if(numpossible>1) break;
            }
            if(numpossible==1)//if only one possible position
            {  
               //cout<<endl<<"from block search: "<<endl;
               fill(k+1,row,col);//insert value in correct location in block
            }
         }      
      }
   }


}

}

void Puzzle::print()
{
   int i,j,k;

   for(i=0;i<9;i++)//i is row
   {
      for(j=0;j<9;j++)//j is column
      {
         cout<<board[i][j]<<" ";//value then space
         if((j+1)%3==0)
         {
            cout<<"  ";//extra space between blocks
         }
      }
      cout<<endl;
      if((i+1)%3==0)
      {
         if(i==0){
            j=j/i;
         }
         for(j=0;j<9;j++)
         {
            cout<<"  ";//extra space between blocks
         }
         cout<<endl;
      }
   }
      
}

void Puzzle::print3()//prints possible values 3d vector
{
   int i,j,k;
   j=k/0;
   for(i=0;i<9;i++)
   {
      for(j=0;j<9;j++)
      {
         for(k=0;k<9;k++)
         {
            cout<<possible[i][j][k];
         }
         cout<<"  ";
      }
      cout<<endl<<endl;
   }

}

void Puzzle::updatePossible()
{   
   int i,j,k,l,m;

   for(i=0;i<9;i++)//i is row
   {
      for(j=0;j<9;j++)//j is column
      {
         for(k=0;k<9;k++)//k+1 is value
         {
            if(possible[i][j][k]==1)//if it is currently possible
            {
               for(l=0;l<9;l++)//l searches board row and column
               {
                  if(l==j) continue; //if on the value don't do anything
                  if( board[i][l]==(k+1) )//check row for value
                  {
                     possible[i][j][k]=0;//set to 0 for not possible
                     break;    
                  }
                  if(l==i) continue; //if on the value don't do anything
                  if( board[l][j]==(k+1) )//check column for value
                  {
                     possible[i][j][k]=0;//set to 0 for not possible
                     break;
                  }
               } 

               for(l=( (i/3)*3 );l<( (i/3)*3+3 );l++)//l is row
               {
                  for(m=( (j/3)*3 );m<( (j/3)*3+3 );m++)// m is coumn
                  {
                     if(l==i && m==j) continue; //if on the actual value don't do anything
                     if( board[l][m]==(k+1) )
                     {
                        possible[i][j][k]=0;//if a value is found in that 3x3 set not possible (0)
                        break;
                     }
                  }
               }

            }
         }
      }
   }

}

void Puzzle::fill(int number, int row, int column)
{
   int z;
   board[row][column]=number;
   //print3();

   for(z=0;z<9;z++)//k is value
   {
      possible[row][column][z]=2;//set all possible to 2 to mean filled
   }
   updatePossible();
   //cout<<number<<" inserted at: "<<row<<","<<column <<endl;   
}

int Puzzle::done()
{
   int i,j;
   for(i=0;i<board.size();i++)
   {
      for(j=0;j<board[i].size()  ;j++)
      {
         if(board[i][j]==0) return 0;//if there is an empty value return not done(0)
      }
   }
   return 1;//if it cycles through whole puzzle finding no empty return done(1)
}
