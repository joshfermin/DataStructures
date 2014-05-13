#include "maze.h"
#include <cassert>
#include <iostream>
#include <fstream> 
using namespace std;

maze::maze()
{
	ifstream myIns; 
	myIns.open("Maze.txt");  // Opening maze that you want to be solved
	
	assert(myIns.is_open());

	//for each item in Ins put into maze arry
	//int xDim; int yDim;
	
	myIns>>yDim>>xDim;
	
	mazeArray = new char[yDim*xDim]; // inputting maze as an array of chars
	
	for(int k=0; k < yDim*xDim; k++)
	{
		myIns >> mazeArray[k];
	}
}


void maze::init() // Finding and setting starting position
{
	for (int i=0; i < yDim; i++)
		{
		for (int j=0; j < xDim; j++)
			{
				if(mazeArray[i*xDim+j] == '*')
				{
					startingIndex = i*xDim+j;
				}
			}
		}
	solve(startingIndex);
}

// solving starting index // RECURSION
bool maze::solve(int index)
{
	
	// Printing out character and index associated
	// cout << mazeArray[index] << " " << index  << endl;
	// cout << index << endl;
	
	// Marking spot as visited
	mazeArray[index] = 'v';
	
	
	// Right dollar sign
	if(mazeArray[index + 1] == '$' && ((index + 1) % xDim) != 0)
	{

			mazeArray[index] = '*';
			return true;
	}
	
	// Left dollar sign
	if(mazeArray[index - 1] == '$'  && ((index) % (xDim) != 0))
	{
		{
			mazeArray[index] = '*';
			return true;
		}
	}
	
	// Bottom Dollar Sign
	if(mazeArray[index + xDim] == '$' && index <= ((xDim * yDim)-xDim)) 
	{
			mazeArray[index] = '*';
			return true;
	}
	
	// Up Dollar Sign
	if(mazeArray[index - xDim] == '$' && index - xDim >= xDim) 
	{
			mazeArray[index] = '*';
			return true;
	}
	
	// Checking Right
	if ((index + 1)%xDim != 0 && (mazeArray[index+1] == '-')) 
	{
		if(solve(index+1)) 
		{
			mazeArray[index] = '*';
			return true;     
		}
	}
	
	// Checking left
	if(mazeArray[index - 1] == '-'  && ((index) % (xDim) != 0))
	{
		if(solve(index - 1))
		{
			mazeArray[index] = '*';
			return true;
		}
	}
	
	
	// Checking down and for border
	if ((index + xDim) <= (xDim * yDim) && mazeArray[index + xDim] == '-')
		{
			if(solve(index + xDim))
				{
				mazeArray[index] = '*';
				return true;
				}
		}
	
	
	// Checking up
	if((index - xDim >= 0) && (mazeArray[index - xDim] == '-')) 
			{
				if(solve(index - xDim))
					{
					mazeArray[index] = '*';
					return true;
					}
			}
			
	mazeArray[index] = '-';
	return false;
}


ostream& operator << (ostream& outs, const maze& source)

	{
	for (int i=0; i < source.yDim; i++)
		{
		for (int j=0; j < source.xDim; j++)
			{
				outs << source.mazeArray[i*source.xDim+j];
				}
					outs << "\n";
			}
	return outs;
}


/*
 * 
 * 
 * 
 * 
 * 
 * 
	for (int i=0; i < yDim; i++)
	{
		for (int p=0; p < xDim; p++)
			{
				myIns>>mazeArray[i*xDim+p];
			}
	}
	* 
	* 
	*
	*
	* 
	* 
	* 
	* 
	* 
	* 
	* 
	* 
	*  
	if (index < 0 || index >= (xDim*yDim)){return false;} 
	
	cout<<index<< " : " << mazeArray[index] <<endl;
	
	mazeArray[index]='v';  // marks current spot as visited (v)
	
	//First is the base case of the recursion. are we at the goal ($)
	if(mazeArray[index] == '$'){return true;}

	if(mazeArray[index - xDim]== '-' && index<(xDim*(yDim-1))) // checks down for open path and considers maze "border"
	{
		if(solve(index-xDim))  // RECURSION!
		{
			mazeArray[index]='*';
			return true;
		}
	}
	
	if(mazeArray[index+xDim]=='-' && index>xDim)  // checks up 
	{
		if(solve(index+xDim))
		{
			mazeArray[index]='*';
			return true;
		}
	}
	if(mazeArray[index+1]=='-' && (index+1%xDim)!=0) // checks right (move the pointer right 1, check to see if its a left boundary)
	{
		if(solve(index+1))  
		{
			mazeArray[index]='*';
			return true;
		}
	}
	if(mazeArray[index-1]=='-' && index%xDim!=0) // checks left 
	{
		if(solve(index-1)) 
		{
			mazeArray[index]='*';
			return true;
		}
	}
	* 
	// outs << source.xDim << " " << source.yDim << endl;
	// outs << source.xDim << " " << source.yDim << "\n" << source.mazeArray << endl;
*/
