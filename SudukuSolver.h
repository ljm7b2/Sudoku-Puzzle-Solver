//Luke McDuff
//ljm7b2@mail.umkc.edu
//Program 6
//11/30/14

#pragma once
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class SudukuSolver
{
public:
	
	SudukuSolver();
	//initializes character array, ways to solve to base values

	void SolveSudukuPuzzle() { solver(0, 0); }
	//public method to recursively solve suduku puzzle
	
	int getWaysToSolve() { return waysToSolve; }
	//returns the total unique ways to solve suduku puzzle

	void importPuzzleSolveAndPrint(ifstream& fin, ostream& out);
	//the easiest way to use, class declare file input stream and output stream
	//function solves and outputs unique ways to solve puzzle

	void updateFileName(string fN){ userFileName = fN; }
	//assigns a filename for output information

private:

	//VARIABLES
	char sudukuGrid[16][16];				//holds the puzzle from file

	char characterArr[16];					//holds all hex characters from 0-F

	int characterArrTracker[16];			// keeps track of what character have been used; 0 if not, 1 if have

	int waysToSolve;						//holds the possible ways to solve the puzzle

	string userFileName;					//holds filename given by user
		
	//METHODS
	bool rowValid(int row);					//checks row to ensure validity by game rules

	bool columnValid(int column);			//checks column to ensure validity by game rules

	bool gridValid(int row, int column);	//checks grid to ensure validity by game rules


	int solver(int row, int col);			//method to recursively solve puzzle, updates incremenent function      
											//to keep track of unique ways to solve

	int findChar(char c);					//finds the index of given character and returns integer index


	void incrementChecker(int index);		//checks the character arr tracker to ensure no values greater than 1 are present

	void resetChecker();					//resets character arr tracker to all zeros


	void resetPuzzle(int row, int col);		//reinserts a period where a character has been placed, to return puzzle to original state


	void setWaysToSolve() { waysToSolve += 1; }	//increments unique ways to solve by 1
};