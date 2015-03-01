//Luke McDuff
//ljm7b2@mail.umkc.edu
//Program 6
//11/30/14

#include "SudukuSolver.h"

SudukuSolver::SudukuSolver()
{
	waysToSolve = 0;

	const char cArr[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' }; //possible puzzle character

	for (int i = 0; i < 16; i++)   //place character values in character array
		
		characterArr[i] = cArr[i];
}

void SudukuSolver::resetChecker()                     //initialize all tracking values to 0
{
	for (int i = 0; i < 16; i++)
		
		characterArrTracker[i] = 0;
}

int SudukuSolver::findChar(char puzzChar)
{
	for (int index = 0; index < 16; index++)                  //find all puzzle character in character and return index, else return -1 if '.'
	{
		if (puzzChar == '.')
			
			return -1;

		if (characterArr[index] == puzzChar)
			
			return index;
	}
}

void SudukuSolver::incrementChecker(int index)
{
	if (index != -1)
		
		characterArrTracker[index] += 1;              //if the index is not -1 increment character tracker
	
}

bool SudukuSolver::rowValid(int row)                          //checks row to ensure game rules validity for row
{
	resetChecker();

	for (int col = 0; col < 16; col++)
		
		incrementChecker(findChar(sudukuGrid[row][col]));

	for (int i = 0; i < 16; i++)
		
		if (characterArrTracker[i] >= 2)
			
			return false;
	
	return true;
			
}
bool SudukuSolver::columnValid(int column)								//checks column for game validity rules for column
{
	resetChecker();

	for (int row = 0; row < 16; row++)		
		
		incrementChecker(findChar(sudukuGrid[row][column]));

	for (int i = 0; i < 16; i++)		
		
		if (characterArrTracker[i] >= 2)			
			
			return false;

	return true;

}
bool SudukuSolver::gridValid(int row, int column)								//checks grid for game rules validity
{
	int row1 = row - (row % 4), col1 = column - (column % 4), r, c;

	resetChecker();

	for (r = row1; r < row1 + 4; r++)			
		
		for (c = col1; c < col1 + 4; c++)					
			
			incrementChecker(findChar(sudukuGrid[r][c]));

	
	for (int i = 0; i < 16; i++)		
		
		if (characterArrTracker[i] >= 2)			
			
			return false;
			
	return true;
}

int SudukuSolver::solver(int row, int col)									//recursive solve function
{
	while (row < 16 && sudukuGrid[row][col] != '.') //find the location of the first '.' and start solving
	{
		col += 1;
		if (col == 16)
		{
			row += 1;
			col = 0;
		}
	}

	if (row == 16) //base case, no '.' have been found; thus one solution found or completed puzzle given
		return 1;

	for (int puzChar = 0; puzChar < 16; puzChar++)
	{
		sudukuGrid[row][col] = characterArr[puzChar];

																						//recursive call
		if (rowValid(row) == true && columnValid(col) == true && gridValid(row, col) == true && solver(row, col) == 1)
		{
			setWaysToSolve();    //increment counter by 1 each time a way to solve is found
		}
	}

	resetPuzzle(row, col); //clear the inserted variables when finished

	return 0;
}

void SudukuSolver::resetPuzzle(int row, int col)         //resets puzzle to original input
{
	sudukuGrid[row][col] = '.';
}

void SudukuSolver::importPuzzleSolveAndPrint(ifstream& fin, ostream& out)   //one all function for easy use
{																			//reads in data, solves and outputs information
	char data;

	int counter = 1;

	while (fin >> data)
	{
		for (int row = 0; row < 16; row++)												//read in suduku data
		{

			for (int col = 0; col < 16; col++)
			{
				
				sudukuGrid[row][col] = data;
				
				fin >> data;				
			}
		}
		
		fin.putback(data);

		SolveSudukuPuzzle();		//solve and print data

		out << "\n(" << getWaysToSolve() << ')' << " Ways To Solve ("

			<< "Puzzle " << counter << ')'

			<< "  From File:  " << userFileName << endl;

		waysToSolve = 0;

		counter++;
	}
	
}


























