#ifndef MAZE_H_
#define MAZE_H_
#include <iostream>

;class maze
{
public:
	maze(); // opens maze.txt

	void init(); // finds starting position, and calls solve
	bool solve(int index); 
	
friend std::ostream& operator << (std::ostream& outs, const maze& source); 
		// overload ostream operator and print out maze
		// double loop?

private:
	char* mazeArray; // representing maze in 1D
	int startingIndex; // an int that represents starting pt
	int xDim; // x dimension of maze
	int yDim; // y dimension of maze
	
	

};

#endif
