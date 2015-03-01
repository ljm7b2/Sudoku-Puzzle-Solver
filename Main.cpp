//Luke McDuff
//ljm7b2@mail.umkc.edu
//CS 201
//Program 6
//11/30/14


/*
Description: Program 6 recursively solves Suduku puzzles that are relatively easy. It uses brute force and back
			 tracking  methods to solve the puzzles. I have built this solver in an easy to use class.

Inputs: Inputs are a text file containing a 16x16 Suduku puzzle, with periods representing blank spaces.
		This class can handle multiple puzzles in one text file.

Outputs: The program outputs only the number of ways each puzzle can be uniquely solved, as well as the name of the text
		 file used and which puzzle it is in the text file.

Algorithm: (only includes algorithm for sorting function, the rest is common sense)
			
		   1) Open text file and read in puzzle into 16x16 2D array.
		   
		   2) Starting at location (0,0) in array, scan through array and break out of loop when first '.' (empty cell)
			  is found.
		   
		   3) Try every possible character from 0-f (hex). When each character is placed in the array, check to make
			  sure the row, column and grid are valid by game rule standards.
		   
		   4) Call the solve function again, starting with the coordinates from step 3.
		  
		  5) When the step 2 has scanned completely through the array and found no '.' (empty cells), then program has 
		      found a unique way to solve. Increment solutions counter.		

Error Handling: The only error handling is when inputing the name of the text file, program will reprompt the user untill
				and existing text file name is given.

*/

#include "SudukuSolver.h"

using namespace std;

void getFileName(ifstream& fin, string& filename);
//asks user for file name input, when good filename is received
//returns ifstream


int main()
{
	cout << "START TIME:  " << __TIMESTAMP__ << endl << endl;

	string filename;

	SudukuSolver puzzle;
	
	ifstream fin;
	
	getFileName(fin,filename);
	
	puzzle.updateFileName(filename);

	puzzle.importPuzzleSolveAndPrint(fin,cout);  //imports puzzle solves and outputs information

	fin.close();
	
	system("PAUSE");

	return 0;

}

void getFileName(ifstream& fin, string& filename)
{
	cout << "What is the Suduku Puzzle File Name: ";

	cin >> filename;

	fin.open(filename);

	while (!fin.good())               //loops untill file that exists is entered 
	{
		cout << "\nBad file name, please re-enter: ";
		
		cin >> filename;
		
		fin.open(filename);
	}	
}